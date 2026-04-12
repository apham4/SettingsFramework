

# File SFSettingsSubsystem.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**SFSettingsSubsystem.h**](SFSettingsSubsystem_8h.md)

[Go to the documentation of this file](SFSettingsSubsystem_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "SFSettingsSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSFSettingChanged, const FGameplayTag&, SettingTag, class USFSettingValue*, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSFSettingSaved, const FGameplayTag&, SettingTag, class USFSettingValue*, SavedValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSFSettingsInitialized);

UCLASS(BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingsSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
    
#pragma region Initialization
public: 
    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Initialization")
    bool IsInitialized() const { return bIsInitialized; };

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

protected:
    void OnSettingsRegistryLoaded(TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistrySoftPtr);
    void RegisterCategory(const class USFSettingCategory* Category);
    void RegisterSetting(class USFSettingDefinition* Definition);
public:
    UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|Initialization")
    FOnSFSettingsInitialized OnSettingsInitialized;

protected:
    bool bIsInitialized = false;
#pragma endregion

#pragma region Setting Data
public:
    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
    TArray<USFSettingCategory*> GetRootCategories() const;

    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
    class USFSettingDefinition* GetSettingDefinition(const FGameplayTag& SettingTag) const;

    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
    class USFSettingOptionSource* GetDynamicOptionSource(const FGameplayTag& SettingTag) const;

protected:
    UPROPERTY(Transient)
    TMap<FGameplayTag, TObjectPtr<class USFSettingOptionSource>> DynamicOptionSources;
#pragma endregion

#pragma region Settings State Management
public:
    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
    class USFSettingValue* GetSettingValue(const FGameplayTag SettingTag) const;

    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
    class USFSettingValue* GetSavedSettingValue(const FGameplayTag SettingTag) const;

    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
    class USFSettingValue* GetDefaultSettingValue(const FGameplayTag SettingTag) const;

    UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
    void SetSettingValue(const FGameplayTag SettingTag, const class USFSettingValue* NewValue);

    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
    bool IsSettingDirty(const FGameplayTag SettingTag) const;

    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
    bool AreAnySettingsDirty() const;

    UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
    void RevertSetting(const FGameplayTag SettingTag);

    UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
    void ResetSettingToDefault(const FGameplayTag SettingTag);

    UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
    void SaveSettings();

    UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
    void RevertSettings();

    UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
    void ResetSettingsToDefault();

public:
    UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|State Management")
    FOnSFSettingChanged OnSettingValueChanged;

    UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|State Management")
    FOnSFSettingSaved OnSettingValueSaved;

protected:
    UPROPERTY(Transient)
    TObjectPtr<class USFSettingsRegistry> SettingsRegistry;

    UPROPERTY(Transient)
    TMap<FGameplayTag, TObjectPtr<class USFSettingDefinition>> RegisteredSettings;

    UPROPERTY(Transient)
    TMap<FGameplayTag, TObjectPtr<class USFSettingValue>> CurrentValues;

    UPROPERTY(Transient)
    TMap<FGameplayTag, TObjectPtr<class USFSettingValue>> SavedValues;
#pragma endregion

#pragma region Condition Checks
public:
    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Conditions")
    bool IsSettingVisible(const FGameplayTag& SettingTag) const;

    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Conditions")
    bool IsSettingEditable(const FGameplayTag& SettingTag) const;

protected:
    void UpdateSettingDependencies();

    // Recursion guard
    int32 MaxUpdateDepth = 10;

    int32 UpdateDepth = 0;
#pragma endregion

#pragma region Serialization
protected:
    void LoadSettingsFromSaveGame();

    void SaveSettingsToSaveGame();

protected:
    FString SaveGameSlotName = TEXT("SF_SaveSlot");
#pragma endregion

#pragma region Keybinding
public:
    UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Keybinding")
    FGameplayTag GetKeybindingCollision(const struct FKey Key, const FGameplayTagContainer CollisionChannels, const FGameplayTag SettingTagToIgnore) const;

    UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|Keybinding")
    bool UpdateKeybinding(const FGameplayTag SettingTag, struct FSFKeybindValueData& NewValue, const enum ESFKeybindCollisionResolution ResolutionPolicy);

protected:
    bool ResolveKeybindingCollision(const FGameplayTag& SettingBeingUpdated, const struct FKey& NewKey, const struct FKey& OldKey, const FGameplayTagContainer& CollisionChannels, const enum ESFKeybindCollisionResolution& ResolutionPolicy);
#pragma endregion
};
```


