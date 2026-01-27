// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SFSettingsSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSFSettingChanged, const struct FGameplayTag&, SettingTag, class USFSettingValue*, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSFSettingSaved, const struct FGameplayTag&, SettingTag, class USFSettingValue*, SavedValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSFSettingsInitialized);

/**
 * Settings subsystem that manages settings states and serialization.
 */
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
	
public:
	UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|Initialization")
	FOnSFSettingsInitialized OnSettingsInitialized;

protected:
	bool bIsInitialized = false;
#pragma endregion

#pragma region Settings State Management
public:
	// Get the list of root categories
	TArray<USFSettingCategory*> GetRootCategories() const;

	// Get current setting value
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetSettingValue(const struct FGameplayTag& SettingTag) const;

	// Get saved setting value
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetSavedSettingValue(const struct FGameplayTag& SettingTag) const;

	// Update current setting value (does not save to disk)
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void SetSettingValue(const struct FGameplayTag& SettingTag, class USFSettingValue* NewValue);

	// Check if current value is different from saved value
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	bool IsSettingDirty(const struct FGameplayTag& SettingTag) const;

	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	bool AreAnySettingsDirty() const;

	// Save current setting values to disk
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void SaveSettings();

	// Discard current values and revert to saved values
	// Fires OnSettingValueChanged for each reverted setting
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void RevertSettings();

public:
	UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|State Management")
	FOnSFSettingChanged OnSettingValueChanged;

	UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|State Management")
	FOnSFSettingSaved OnSettingValueSaved;

protected:
	UPROPERTY(Transient)
	TObjectPtr<class USFSettingsRegistry> SettingsRegistry;

	UPROPERTY(Transient)
	TMap<struct FGameplayTag, TObjectPtr<class USFSettingDefinition>> RegisteredSettings;

	// Current (unsaved) setting values
	UPROPERTY(Transient)
	TMap<struct FGameplayTag, TObjectPtr<class USFSettingValue>> CurrentValues;

	// Saved setting values (on-disk)
	UPROPERTY(Transient)
	TMap<struct FGameplayTag, TObjectPtr<class USFSettingValue>> SavedValues;

	
#pragma endregion

#pragma region Condition Checks
public:
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Conditions")
	bool IsSettingVisible(const struct FGameplayTag& SettingTag) const;

	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Conditions")
	bool IsSettingEditable(const struct FGameplayTag& SettingTag) const;

protected:
	// Check visibility of settings. If it becomes hidden or disabled, revert to default
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
	// Save game slot name.
	FString SaveGameSlotName = TEXT("SF_SaveSlot");
#pragma endregion

#pragma region Helpers
protected:
	class USFSettingDefinition* GetSettingDefinition(const struct FGameplayTag& SettingTag) const;
#pragma endregion
};
