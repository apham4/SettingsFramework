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

#pragma region Setting Data
public:
	// Get the list of root categories
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
	TArray<USFSettingCategory*> GetRootCategories() const;

	// Get the setting definition associated with the given setting gameplay tag
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
	class USFSettingDefinition* GetSettingDefinition(const struct FGameplayTag& SettingTag) const;
#pragma endregion

#pragma region Settings State Management
public:
	// Get current setting value
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetSettingValue(const struct FGameplayTag& SettingTag) const;

	// Get saved setting value
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetSavedSettingValue(const struct FGameplayTag& SettingTag) const;

	// Get default setting value from definition
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetDefaultSettingValue(const struct FGameplayTag& SettingTag) const;

	// Update current setting value (does not save to disk)
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void SetSettingValue(const struct FGameplayTag& SettingTag, class USFSettingValue* NewValue);

	// Check if current value is different from saved value
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	bool IsSettingDirty(const struct FGameplayTag& SettingTag) const;

	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	bool AreAnySettingsDirty() const;

	// Discard current value and revert to saved value
	// Fires OnSettingValueChanged if the value was reverted
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void RevertSetting(const struct FGameplayTag& SettingTag);

	// Reset current value to default value from definition. Does not change saved value.
	// Fires OnSettingValueChanged if the value was reset
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void ResetSettingToDefault(const struct FGameplayTag& SettingTag);

	// Save current setting values to disk
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void SaveSettings();

	// Call RevertSetting for all dirty settings
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void RevertSettings();

	// Call ResetSettingToDefault for all settings. Does not change saved values.
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

#pragma region Keybinding
public:
	// Returns a setting GamplayTag that have keybindings that would collide with the given input chord and collision channels, excluding the setting specified by SettingTagToIgnore.
	// Returns empty tag if there are no collisions.
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Keybinding")
	struct FGameplayTag GetKeybindingCollision(const struct FInputChord& Chord, const struct FGameplayTagContainer& CollisionChannels, const struct FGameplayTag& SettingTagToIgnore) const;

	// Update a keybinding with specific collision handling. Returns true if successful.
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|Keybinding")
	bool UpdateKeybinding(const struct FGameplayTag& SettingTag, struct FSFKeybindValueData& NewValue, const enum ESFKeybindCollisionResolution& ResolutionPolicy);

protected:
	// For SettingBeingUpdated, NewChord is being applied to one of its slots, with OldChord being its previous value. Check to see if this NewChord collides with any other setting's keybinding slots.
	// If there is collision, resolve it according to the ResolutionPolicy.
	// Returns true if resolved successfully.
	bool ResolveKeybindingCollision(const struct FGameplayTag& SettingBeingUpdated, const struct FInputChord& NewChord, const struct FInputChord& OldChord, const struct FGameplayTagContainer& CollisionChannels, const enum ESFKeybindCollisionResolution& ResolutionPolicy);
#pragma endregion
};
