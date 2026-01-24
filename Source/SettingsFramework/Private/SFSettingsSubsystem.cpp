// Copyright 2026 Anh Pham. All Rights Reserved.


#include "SFSettingsSubsystem.h"
#include "GameplayTagContainer.h"
#include "SFSettingsDeveloperSettings.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Definitions/SFSettingsRegistry.h"
#include "Definitions/SFSettingCategory.h"
#include "Definitions/SFSettingDefinition.h"
#include "Definitions/SFSettingCondition.h"
#include "Core/SFSettingValue.h"
#include "Core/SFLogs.h"

#pragma region Initialization
void USFSettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

	// Load Settings Registry asset from Developer Settings
	const USFSettingsDeveloperSettings* devSettings = GetDefault<USFSettingsDeveloperSettings>();
    if (!IsValid(devSettings) || devSettings->SettingsRegistry.IsNull())
    {
        UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] No Settings Registry assigned in Project Settings."));
        return;
    }

	FStreamableManager& streamable = UAssetManager::GetStreamableManager();
    streamable.RequestAsyncLoad(devSettings->SettingsRegistry.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &USFSettingsSubsystem::OnSettingsRegistryLoaded, devSettings->SettingsRegistry));
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

    LoadSavedSettingValues();

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
	}
}

void USFSettingsSubsystem::LoadSavedSettingValues()
{
	// TODO: Load from USaveGame to both SavedValues and CurrentValues
	// For each setting, fire both OnSettingValueChanged and OnSettingValueSaved
}
#pragma endregion

#pragma region Settings State Management
TArray<USFSettingCategory*> USFSettingsSubsystem::GetRootCategories() const
{
    return IsValid(SettingsRegistry) ? SettingsRegistry->RootCategories : TArray<USFSettingCategory*>();
}

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

void USFSettingsSubsystem::SetSettingValue(const FGameplayTag& SettingTag, USFSettingValue* NewValue)
{
    if (!IsValid(NewValue))
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

    // TODO: Write SavedValues to USaveGame and SaveToSlot
}

void USFSettingsSubsystem::RevertSettings()
{
    for (const auto& entry : SavedValues)
    {
		const FGameplayTag& settingTag = entry.Key;
		USFSettingValue* savedValue = entry.Value;
        if (IsValid(savedValue) && (!CurrentValues.Contains(settingTag) || !CurrentValues[settingTag]->Equals(savedValue)))
        {
            USFSettingValue* duplicatedValue = savedValue->Duplicate(this);
            CurrentValues[settingTag] = duplicatedValue;
            OnSettingValueChanged.Broadcast(settingTag, duplicatedValue);
        }
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

#pragma region Helpers
USFSettingDefinition* USFSettingsSubsystem::GetSettingDefinition(const struct FGameplayTag& SettingTag) const
{
    if (const TObjectPtr<USFSettingDefinition>* found = RegisteredSettings.Find(SettingTag))
    {
        return *found;
    }
    return nullptr;
}
#pragma endregion