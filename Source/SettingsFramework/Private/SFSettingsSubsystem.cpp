// Copyright 2026 Anh Pham. All Rights Reserved.


#include "SFSettingsSubsystem.h"
#include "GameplayTagContainer.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Core/SFLogs.h"
#include "Core/SFCoreTypes.h"
#include "Core/SFSettingValue.h"
#include "Definitions/SFSettingsRegistry.h"
#include "Definitions/SFSettingCategory.h"
#include "Definitions/SFSettingDefinition.h"
#include "Definitions/SFSettingCondition.h"
#include "SaveGame/SFSaveGame.h"
#include "SFSettingsDeveloperSettings.h"

#pragma region Initialization
void USFSettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    
    // Load config variables from Developer Settings
    const USFSettingsDeveloperSettings* devSettings = GetDefault<USFSettingsDeveloperSettings>();
    if (!IsValid(devSettings))
    {
        UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] Plugin Developer Settings not found."));
        return;
    }

	// Save game slot name
	SaveGameSlotName = devSettings->SaveGameSlotName;

	// Recursion guard
	MaxUpdateDepth = devSettings->MaxUpdateDepth;

    // SettingsRegistry
    if (!devSettings->SettingsRegistry.IsNull())
    {
        FStreamableManager& streamable = UAssetManager::GetStreamableManager();
        streamable.RequestAsyncLoad(devSettings->SettingsRegistry.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &USFSettingsSubsystem::OnSettingsRegistryLoaded, devSettings->SettingsRegistry));
    }
}

void USFSettingsSubsystem::OnSettingsRegistryLoaded(TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistrySoftPtr)
{
    RegisteredSettings.Empty();
    SettingsRegistry = SettingsRegistrySoftPtr.Get();
    if (!IsValid(SettingsRegistry))
    {
        UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] Failed to load Settings Registry asset."));
        return;
	}

    for (const USFSettingCategory* category : SettingsRegistry->RootCategories)
    {
        RegisterCategory(category);
	}

    LoadSettingsFromSaveGame();

    bIsInitialized = true;
	OnSettingsInitialized.Broadcast();
}

void USFSettingsSubsystem::RegisterCategory(const USFSettingCategory* Category)
{
    if (!IsValid(Category))
    {
        return;
	}

    if (Category->CategoryType == ESFCategoryType::Branch)
    {
        for (const USFSettingCategory* subcategory : Category->Subcategories)
        {
            RegisterCategory(subcategory);
        }
    }
    else if (Category->CategoryType == ESFCategoryType::Leaf)
    {
        for (const FSFSettingGroup& group : Category->SettingGroups)
        {
            for (USFSettingDefinition* settingDef : group.Settings)
            {
                if (!IsValid(settingDef))
                {
                    continue;
                }
                RegisteredSettings.Emplace(settingDef->SettingTag, settingDef);
            }
        }

        // If no groups are defined, register fallback setting list directly under the category.
        if (Category->SettingGroups.Num() == 0)
        {
            for (USFSettingDefinition* settingDef : Category->Settings)
            {
                if (!IsValid(settingDef))
                {
                    continue;
                }
                RegisteredSettings.Emplace(settingDef->SettingTag, settingDef);
            }
        }
    }
}
#pragma endregion

#pragma region Setting Data
TArray<USFSettingCategory*> USFSettingsSubsystem::GetRootCategories() const
{
    return IsValid(SettingsRegistry) ? SettingsRegistry->RootCategories : TArray<USFSettingCategory*>();
}

USFSettingDefinition* USFSettingsSubsystem::GetSettingDefinition(const FGameplayTag& SettingTag) const
{
    if (const TObjectPtr<USFSettingDefinition>* found = RegisteredSettings.Find(SettingTag))
    {
        return *found;
    }
    return nullptr;
}
#pragma endregion

#pragma region Settings State Management
USFSettingValue* USFSettingsSubsystem::GetSettingValue(const FGameplayTag& SettingTag) const
{
    USFSettingValue* valueToReturn = nullptr;
    if (const TObjectPtr<USFSettingValue>* val = CurrentValues.Find(SettingTag))
    {
        valueToReturn = *val;
    }
    else if (const TObjectPtr<USFSettingDefinition>* settingDef = RegisteredSettings.Find(SettingTag))
    {
		valueToReturn = (*settingDef)->DefaultValue;
    }
    return valueToReturn;
}

USFSettingValue* USFSettingsSubsystem::GetSavedSettingValue(const FGameplayTag& SettingTag) const
{
    USFSettingValue* valueToReturn = nullptr;
    if (const TObjectPtr<USFSettingValue>* val = SavedValues.Find(SettingTag))
    {
        valueToReturn = *val;
    }
    else if (const TObjectPtr<USFSettingDefinition>* settingDef = RegisteredSettings.Find(SettingTag))
    {
        valueToReturn = (*settingDef)->DefaultValue;
    }
    return valueToReturn;
}

USFSettingValue* USFSettingsSubsystem::GetDefaultSettingValue(const FGameplayTag& SettingTag) const
{
    USFSettingDefinition* settingDef = GetSettingDefinition(SettingTag);
    return IsValid(settingDef) ? settingDef->GetDefaultValue(this) : nullptr;
}

void USFSettingsSubsystem::SetSettingValue(const FGameplayTag& SettingTag, USFSettingValue* NewValue)
{
    if (!IsValid(NewValue) || (CurrentValues.Contains(SettingTag) && CurrentValues[SettingTag]->Equals(NewValue)))
    {
        return;
    }

    if (UpdateDepth > MaxUpdateDepth)
    {
        UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] Infinite dependency loop detected for %s"), *SettingTag.ToString());
        return;
    }

    ++UpdateDepth;

	USFSettingValue* duplicatedValue = NewValue->Duplicate(this);
	CurrentValues[SettingTag] = duplicatedValue;
	OnSettingValueChanged.Broadcast(SettingTag, duplicatedValue);

	UpdateSettingDependencies();

    --UpdateDepth;
}

bool USFSettingsSubsystem::IsSettingDirty(const struct FGameplayTag& SettingTag) const
{
    const USFSettingValue* currentValue = GetSettingValue(SettingTag);
    const USFSettingValue* savedValue = GetSavedSettingValue(SettingTag);
    if (!IsValid(currentValue) && !IsValid(savedValue))
    {
        return false;
    }
    if (!IsValid(currentValue) || !IsValid(savedValue))
    {
        return true;
    }
    return !currentValue->Equals(savedValue);
}

bool USFSettingsSubsystem::AreAnySettingsDirty() const
{
    for (const auto& entry : RegisteredSettings)
    {
        const FGameplayTag& settingTag = entry.Key;
        if (IsSettingDirty(settingTag))
        {
            return true;
        }
    }
	return false;
}

void USFSettingsSubsystem::RevertSetting(const FGameplayTag& SettingTag)
{
    const USFSettingValue* valueToUse = GetSavedSettingValue(SettingTag);
    valueToUse = IsValid(valueToUse) ? valueToUse : GetDefaultSettingValue(SettingTag);
    const USFSettingValue* currentValue = GetSettingValue(SettingTag);
    if (!IsValid(valueToUse) || valueToUse->Equals(currentValue))
    {
        return;
    }
    USFSettingValue* duplicatedValue = valueToUse->Duplicate(this);
    CurrentValues[SettingTag] = duplicatedValue;
    OnSettingValueChanged.Broadcast(SettingTag, duplicatedValue);
}

void USFSettingsSubsystem::ResetSettingToDefault(const FGameplayTag& SettingTag)
{
    const USFSettingValue* currentValue = GetSettingValue(SettingTag);
    const USFSettingValue* defaultValue = GetDefaultSettingValue(SettingTag);
    if (!IsValid(defaultValue) || defaultValue->Equals(currentValue))
    {
        return;
    }
    USFSettingValue* duplicatedValue = defaultValue->Duplicate(this);
    CurrentValues[SettingTag] = duplicatedValue;
    OnSettingValueChanged.Broadcast(SettingTag, duplicatedValue);
}

void USFSettingsSubsystem::SaveSettings()
{
    for (const auto& entry : CurrentValues)
    {
		const FGameplayTag& settingTag = entry.Key;
		USFSettingValue* currentValue = entry.Value;
        if (IsValid(currentValue) && (!SavedValues.Contains(settingTag) || !SavedValues[settingTag]->Equals(currentValue)))
        {
            USFSettingValue* duplicatedValue = currentValue->Duplicate(this);
            SavedValues[settingTag] = duplicatedValue;
            OnSettingValueSaved.Broadcast(settingTag, duplicatedValue);
		}
    }

    SaveSettingsToSaveGame();
}

void USFSettingsSubsystem::RevertSettings()
{
    for (const auto& entry : RegisteredSettings)
    {
        RevertSetting(entry.Key);
    }
}

void USFSettingsSubsystem::ResetSettingsToDefault()
{
    for (const auto& entry : RegisteredSettings)
    {
        ResetSettingToDefault(entry.Key);
    }
}
#pragma endregion

#pragma region Condition Checks
bool USFSettingsSubsystem::IsSettingVisible(const FGameplayTag& SettingTag) const
{
    const USFSettingDefinition* settingDef = GetSettingDefinition(SettingTag);
    if (!IsValid(settingDef))
    {
        return false;
    }

    bool retVal = true;
    for (USFSettingCondition* condition : settingDef->VisibilityConditions)
    {
        if (IsValid(condition) && !condition->IsConditionMet(this))
        {
            retVal = false;
            break;
        }
    }
    return retVal;
}

bool USFSettingsSubsystem::IsSettingEditable(const FGameplayTag& SettingTag) const
{
    const USFSettingDefinition* settingDef = GetSettingDefinition(SettingTag);
    if (!IsValid(settingDef))
    {
        return false;
    }

    bool retVal = true;
    for (USFSettingCondition* condition : settingDef->EditabilityConditions)
    {
        if (IsValid(condition) && !condition->IsConditionMet(this))
        {
            retVal = false;
            break;
        }
    }
    return retVal;
}

void USFSettingsSubsystem::UpdateSettingDependencies()
{
    for (const auto& entry : RegisteredSettings)
    {
        const FGameplayTag& settingTag = entry.Key;
        USFSettingDefinition* settingDef = entry.Value;

        if (!IsSettingVisible(settingTag) || !IsSettingEditable(settingTag))
        {
            // Setting is hidden or disabled, check to see if its value is different from default. If so, revert.
			USFSettingValue* currentValue = (CurrentValues.Contains(settingTag)) ? CurrentValues[settingTag] : nullptr;
            USFSettingValue* defaultValue = settingDef->GetDefaultValue(this);

            if (currentValue && !currentValue->Equals(defaultValue))
            {
				SetSettingValue(settingTag, defaultValue);
			}
        }
    }
}
#pragma endregion

#pragma region Serialization
void USFSettingsSubsystem::LoadSettingsFromSaveGame()
{
    USFSaveGame* saveGame = UGameplayStatics::DoesSaveGameExist(SaveGameSlotName, 0) ? Cast<USFSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveGameSlotName, 0)) : nullptr;
    if (!IsValid(saveGame))
    {
        return;
    }
    UE_LOG(LogSettingsFramework, Log, TEXT("[SettingsFramework] Settings loaded from slot %s"), *SaveGameSlotName);
    
    for (const auto& entry : saveGame->SerializedSettings)
    {
        const FGameplayTag& settingTag = entry.Key;
        const FString& serializedValue = entry.Value;
        
        USFSettingDefinition* settingDef = GetSettingDefinition(settingTag);
        TSubclassOf<USFSettingValue> valueClass = IsValid(settingDef) ? settingDef->GetValueClass() : nullptr;
        USFSettingValue* newValueInstance = IsValid(valueClass) ? NewObject<USFSettingValue>(this, valueClass) : nullptr;
        if (!IsValid(newValueInstance))
        {
            continue;
        }
        
        newValueInstance->DeserializeFromString(serializedValue);
        
        // Add to SavedValues and fire OnSettingValueSaved
        SavedValues.Emplace(settingTag, newValueInstance);
        OnSettingValueSaved.Broadcast(settingTag, newValueInstance);

        // Add to CurrentValues and fire OnSettingValueChanged
        USFSettingValue* duplicatedValue = newValueInstance->Duplicate(this);
        CurrentValues.Emplace(settingTag, duplicatedValue);
        OnSettingValueChanged.Broadcast(settingTag, duplicatedValue);
    }
}

void USFSettingsSubsystem::SaveSettingsToSaveGame()
{
    USFSaveGame* saveGame = Cast<USFSaveGame>(UGameplayStatics::CreateSaveGameObject(USFSaveGame::StaticClass()));
    if (!IsValid(saveGame))
    {
        return;
    }

    for (const auto& entry : SavedValues)
    {
        const FGameplayTag& settingTag = entry.Key;
        USFSettingValue* savedValue = entry.Value;
        if (IsValid(savedValue))
        {
            saveGame->SerializedSettings.Add(settingTag, savedValue->SerializeToString());
        }
    }

    UGameplayStatics::AsyncSaveGameToSlot(saveGame, SaveGameSlotName, 0, FAsyncSaveGameToSlotDelegate::CreateWeakLambda(this, [this](const FString& InSlotName, const int32 InUserIndex, bool bSuccess)
        {
            if (bSuccess)
            {
                UE_LOG(LogSettingsFramework, Log, TEXT("[SettingsFramework] Settings successfully saved to slot %s"), *SaveGameSlotName);
            }
            else
            {
                UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] Failed to save settings to slot %s"), *SaveGameSlotName);
            }
        }));
}
#pragma endregion

#pragma region Keybinding
FGameplayTag USFSettingsSubsystem::GetKeybindingCollision(const FInputChord& Chord, const FGameplayTagContainer& CollisionChannels, const FGameplayTag& SettingTagToIgnore) const
{
    if (!Chord.IsValidChord() || CollisionChannels.IsEmpty())
    {
        return FGameplayTag::EmptyTag;
    }

    FGameplayTag retVal = FGameplayTag();
    for (const TPair<FGameplayTag, TObjectPtr<USFSettingDefinition>>& entry : RegisteredSettings)
    {
        const FGameplayTag& settingTag = entry.Key;
        const USFSettingDefinition_Key* keyDef = Cast<USFSettingDefinition_Key>(entry.Value);
        if ((SettingTagToIgnore.IsValid() && settingTag == SettingTagToIgnore) || !IsValid(keyDef) || !keyDef->CollisionChannels.HasAny(CollisionChannels))
        {
            continue;
        }
        
        USFSettingValue_Key* currentValue = Cast<USFSettingValue_Key>(GetSettingValue(settingTag));
        if (IsValid(currentValue))
        {
            if (currentValue->Value.KBMPrimary == Chord
                || currentValue->Value.KBMSecondary == Chord
                || currentValue->Value.Gamepad == Chord)
            {
                retVal = settingTag;
                break;
            }
        }
    }

    return retVal;
}

bool USFSettingsSubsystem::UpdateKeybinding(const FGameplayTag& SettingTag, FSFKeybindValueData& NewValue, const ESFKeybindCollisionResolution& ResolutionPolicy)
{
    USFSettingDefinition_Key* keySettingDef = Cast<USFSettingDefinition_Key>(GetSettingDefinition(SettingTag));
    if (!IsValid(keySettingDef))
    {
        return false;
    }

    // Get current value
    USFSettingValue_Key* currentValue = Cast<USFSettingValue_Key>(GetSettingValue(SettingTag));
    currentValue = IsValid(currentValue) ? currentValue : Cast<USFSettingValue_Key>(keySettingDef->GetDefaultValue(this));
    FSFKeybindValueData currentKeybindData = IsValid(currentValue) ? currentValue->Value : FSFKeybindValueData();

    // Check and resolve collisions for each slot
    bool bResolved = true;
    if (bResolved)
    {
        bResolved &= ResolveKeybindingCollision(SettingTag, NewValue.KBMPrimary, currentKeybindData.KBMPrimary, keySettingDef->CollisionChannels, ResolutionPolicy);
    }
    if (bResolved)
    {
        bResolved &= ResolveKeybindingCollision(SettingTag, NewValue.KBMSecondary, currentKeybindData.KBMSecondary, keySettingDef->CollisionChannels, ResolutionPolicy);
    }
    if (bResolved)
    {
        bResolved &= ResolveKeybindingCollision(SettingTag, NewValue.Gamepad, currentKeybindData.Gamepad, keySettingDef->CollisionChannels, ResolutionPolicy);
    }

    if (bResolved)
    {
        USFSettingValue_Key* newValueAsSettingValue = NewObject<USFSettingValue_Key>(this);
        newValueAsSettingValue->Value = NewValue;
        SetSettingValue(SettingTag, newValueAsSettingValue);
    }

    return bResolved;
}

bool USFSettingsSubsystem::ResolveKeybindingCollision(const FGameplayTag& SettingBeingUpdated, const FInputChord& NewChord, const FInputChord& OldChord, const FGameplayTagContainer& CollisionChannels, const ESFKeybindCollisionResolution& ResolutionPolicy)
{
    FGameplayTag collidingSetting = GetKeybindingCollision(NewChord, CollisionChannels, SettingBeingUpdated);
    if (!NewChord.IsValidChord() || NewChord == OldChord || !collidingSetting.IsValid() || ResolutionPolicy == ESFKeybindCollisionResolution::AllowDuplicate)
    {
        // If new chord is empty, same as old chord, there is no collision, or duplicate is allowed, just update the setting with no further action.
        return true;
    }

    // NOTE_TO_SELF: This value MUST have been valid for GetKeybindingCollision to return a valid collidingSetting, so what happens if it is invalid here?
    USFSettingValue_Key* collidingValue = Cast<USFSettingValue_Key>(GetSettingValue(collidingSetting));
    if (!IsValid(collidingValue))
    {
        // Detected a collision but failed to get the current value of the colliding setting. This should not happen, but if it does we log an error and do not apply the new keybind to avoid potential data loss from overwriting an existing keybind without properly resolving the collision.
        UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] Detected keybind collision for setting %s but failed to retrieve current value of colliding setting %s. New keybind will not be applied to avoid potential data loss."), *SettingBeingUpdated.ToString(), *collidingSetting.ToString());
        return false;
    }

    // Handle Resolution
    if (ResolutionPolicy == ESFKeybindCollisionResolution::Overwrite)
    {
        // Clear the slots in collidingValue that match NewChord
        USFSettingValue_Key* newValue = Cast<USFSettingValue_Key>(collidingValue->Duplicate(this));
        if (collidingValue->Value.KBMPrimary == NewChord)
        {
            newValue->Value.KBMPrimary = FInputChord();
        }
        if (collidingValue->Value.KBMSecondary == NewChord)
        {
            newValue->Value.KBMSecondary = FInputChord();
        }
        if (collidingValue->Value.Gamepad == NewChord)
        {
            newValue->Value.Gamepad = FInputChord();
        }

        SetSettingValue(collidingSetting, newValue);
    }
    else if (ResolutionPolicy == ESFKeybindCollisionResolution::Swap)
    {
        // Set the colliding slot(s) in the colliding setting to OldChord
        USFSettingValue_Key* newValue = Cast<USFSettingValue_Key>(collidingValue->Duplicate(this));
        if (collidingValue->Value.KBMPrimary == NewChord)
        {
            newValue->Value.KBMPrimary = OldChord;
        }
        if (collidingValue->Value.KBMSecondary == NewChord)
        {
            newValue->Value.KBMSecondary = OldChord;
        }
        if (collidingValue->Value.Gamepad == NewChord)
        {
            newValue->Value.Gamepad = OldChord;
        }

        SetSettingValue(collidingSetting, newValue);
    }

    return true;
}
#pragma endregion