// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "SFSettingsSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSFSettingChanged, const FGameplayTag&, SettingTag, class USFSettingValue*, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSFSettingSaved, const FGameplayTag&, SettingTag, class USFSettingValue*, SavedValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSFSettingsInitialized);

/**
 * @brief The subsystem that manages all settings data and logic at runtime.
 *
 * This subsystem is responsible for managing all settings data and logic at runtime. This includes tasks such as:
 * 
 * * Asynchronously loads setting definitions and categories from the settings registry on initialization 
 * 
 * * Manages current and saved setting values
 * 
 * * Checks conditions for settings' visibility and editability
 * 
 * * Handles saving and loading settings to disk.
 * 
 * * Among other things.
 * @note @blueprinttype
 */
UCLASS(BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
#pragma region Initialization
public: 
	/**
	* Checks if the settings registry has finished loading and saved setting values have been loaded from disk.
	* @return true if the subsystem is ready to be used, false if the settings registry is still loading or if there was an error during initialization.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Initialization")
	bool IsInitialized() const { return bIsInitialized; };

	/** @cond */

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

protected:
	void OnSettingsRegistryLoaded(TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistrySoftPtr);
	void RegisterCategory(const class USFSettingCategory* Category);
	void RegisterSetting(class USFSettingDefinition* Definition);
	/** @endcond */
	
public:
	/**
	* Event fired when the settings registry has finished loading and saved setting values have been loaded from disk, indicating that the subsystem is ready to be used.
	*/
	UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|Initialization")
	FOnSFSettingsInitialized OnSettingsInitialized;

	/** @cond */
protected:
	bool bIsInitialized = false;
	/** @endcond */
#pragma endregion

#pragma region Setting Data
public:
	/**
	* Get the collection of root categories.
	* @return An array of root categories.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
	TArray<USFSettingCategory*> GetRootCategories() const;

	/**
	* Get the setting definition associated with the given setting Gameplay Tag
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return The setting definition Data Asset associated with the given setting Gameplay Tag. Returns nullptr if the tag is not found or if the associated asset failed to load.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
	class USFSettingDefinition* GetSettingDefinition(const FGameplayTag& SettingTag) const;

	/**
	* Get the dynamic option source object associated with the given setting Gameplay Tag if it is a discrete setting with dynamic options.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return The setting option source object associated with the given setting Gameplay Tag. Returns nullptr if invalid.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Setting Data")
	class USFSettingOptionSource* GetDynamicOptionSource(const FGameplayTag& SettingTag) const;

protected:
	/**
	* The map of setting GameplayTag to setting setting option source object for registered discrete settings wtih dynamic options.
	* @note @t
	*/
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<class USFSettingOptionSource>> DynamicOptionSources;
#pragma endregion

#pragma region Settings State Management
public:
	/**
	* Get the current active value of a setting associated with the given setting Gameplay Tag.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return The current active value of the setting associated with the given setting Gameplay Tag. Returns the default setting if no current value is found. Returns nullptr if the tag is not found or if the value is invalid.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetSettingValue(const FGameplayTag SettingTag) const;

	/**
	* Get the saved value of a setting associated with the given setting Gameplay Tag.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return The saved value of the setting associated with the given setting Gameplay Tag. Returns the default setting if no saved value is found. Returns nullptr if the tag is not found or if the value is invalid.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetSavedSettingValue(const FGameplayTag SettingTag) const;

	/**
	* Get the default value of a setting associated with the given setting Gameplay Tag.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return The default value of the setting associated with the given setting Gameplay Tag. Returns nullptr if the tag is not found or if the value is invalid.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	class USFSettingValue* GetDefaultSettingValue(const FGameplayTag SettingTag) const;

	/**
	* Update the current active value of a setting associated with the given setting Gameplay Tag. Does not save value to disk.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void SetSettingValue(const FGameplayTag SettingTag, const class USFSettingValue* NewValue);

	/**
	* Check if the current active value of the setting associated with the given setting Gameplay Tag is different from its saved value.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return true if they are different or if one of them is invalid, false if they are the same or if they are both invalid.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	bool IsSettingDirty(const FGameplayTag SettingTag) const;

	/**
	* Check if any setting has its current active value different from its saved value.
	* @return true if there is at least one setting that is dirty, false if all settings are clean or if there are no registered settings.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|State Management")
	bool AreAnySettingsDirty() const;

	/**
	* Discard current active value and revert to saved value for the setting associated with the given setting Gameplay Tag. Does not change saved value.
	* Fires OnSettingValueChanged if the value was reverted.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void RevertSetting(const FGameplayTag SettingTag);

	/**
	* Discard current active value and reset to default value for the setting associated with the given setting Gameplay Tag. Does not change saved value.
	* Fires OnSettingValueChanged if the value was reset.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void ResetSettingToDefault(const FGameplayTag SettingTag);

	/**
	* Save and serialize all current active setting values to disk, overwriting previous saved values.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void SaveSettings();

	/**
	* Discard the current active value and revert to saved value for all settings that have unsaved changes. Does not change saved values.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void RevertSettings();

	/**
	* Discard the current active value and reset to default value for all settings. Does not change saved values.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|State Management")
	void ResetSettingsToDefault();

public:
	/**
	* Event fired when a setting's current active value is changed.
	* @note @ba
	*/
	UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|State Management")
	FOnSFSettingChanged OnSettingValueChanged;

	/**
	* Event fired when a setting's current active value is saved to disk.
	* @note @ba
	*/
	UPROPERTY(BlueprintAssignable, Category = "SFSettingsSubsystem|State Management")
	FOnSFSettingSaved OnSettingValueSaved;

protected:
	/**
	* Transient pointer to the loaded settings registry asset.
	* @note @t
	*/
	UPROPERTY(Transient)
	TObjectPtr<class USFSettingsRegistry> SettingsRegistry;

	/**
	* The map of setting GameplayTag to setting definition Data Asset for registered settings. Used for quick lookup of setting definitions at runtime.
	* @note @t
	*/
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<class USFSettingDefinition>> RegisteredSettings;

	/**
	* The map of setting GameplayTag to current active value for registered settings. Used for managing current setting values at runtime.
	* @note @t
	*/
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<class USFSettingValue>> CurrentValues;

	/**
	* The map of setting GameplayTag to saved value for registered settings. Used for managing saved setting values at runtime and for saving/loading settings to disk.
	* @note @t
	*/
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<class USFSettingValue>> SavedValues;
#pragma endregion

#pragma region Condition Checks
public:
	/**
	* Check if a setting associated with the given setting Gameplay Tag should be visible based on its visibility conditions defined in its setting definition.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return true if the setting should be visible, false if it should be hidden or if the tag's setting is not found.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Conditions")
	bool IsSettingVisible(const FGameplayTag& SettingTag) const;

	/**
	* Check if a setting associated with the given setting Gameplay Tag should be editable/enabled based on its editability conditions defined in its setting definition.
	* @param SettingTag The Gameplay Tag associated with the setting.
	* @return true if the setting should be editable/enabled, false if it should be disabled or if the tag's setting is not found.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Conditions")
	bool IsSettingEditable(const FGameplayTag& SettingTag) const;

protected:
	/** @cond */
	void UpdateSettingDependencies();

	// Recursion guard
	int32 MaxUpdateDepth = 10;

	int32 UpdateDepth = 0;
	/** @endcond */
#pragma endregion

#pragma region Serialization
protected:
	/**
	* Load saved setting values from disk and update CurrentValues and SavedValues maps accordingly. Called during initialization after settings registry is loaded.
	*/
	void LoadSettingsFromSaveGame();

	/**
	* Save current active setting values to disk and update SavedValues map accordingly. Called when SaveSettings is called.
	*/
	void SaveSettingsToSaveGame();

protected:
	/** @cond */
	FString SaveGameSlotName = TEXT("SF_SaveSlot");
	/** @endcond */
#pragma endregion

#pragma region Keybinding
public:
	/**
	* Check for keybinding collisions with a given input key and collision channels, excluding a specific setting.
	* @param Key The input key to check for collisions.
	* @param CollisionChannels The Gameplay Tag container of collision channels to check against. Only settings that have at least one of these tags in their collision channels will be checked for collision.
	* @param SettingTagToIgnore The Gameplay Tag of the setting to ignore during collision check. This is useful when updating a keybinding for a specific setting and you want to ignore collision with its current keybinding.
	* @return The Gameplay Tag of the setting that has a colliding keybinding, or an empty tag if there are no collisions.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingsSubsystem|Keybinding")
	FGameplayTag GetKeybindingCollision(const struct FKey Key, const FGameplayTagContainer CollisionChannels, const FGameplayTag SettingTagToIgnore) const;

	/**
	* Update a keybinding for a setting with specific collision handling. 
	* If the new keybinding collides with existing keybindings based on the given collision channels, the collision will be resolved according to the specified resolution policy.
	* @param SettingTag The Gameplay Tag of the setting to update the keybinding for.
	* @param NewValue The new keybinding value data to apply to the setting.
	* @param ResolutionPolicy The policy to use for resolving keybinding collisions if the new keybinding collides with existing keybindings. 
	* **AllowDuplicate** means the new keybinding will be applied even if there is a collision. **Overwrite** means the existing conflicting keybind will be removed. **Swap** means the existing conflicting keybind will be changed to the new keybinding's old value.
	* @return true if the keybinding was updated successfully, false if there was an error such as the setting tag not being found, the new value being invalid, or if collision resolution failed.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsSubsystem|Keybinding")
	bool UpdateKeybinding(const FGameplayTag SettingTag, struct FSFKeybindValueData& NewValue, const enum ESFKeybindCollisionResolution ResolutionPolicy);

protected:
	/**
	* Check for keybinding collisions with a given new keybinding for a specific setting and resolve them according to the specified resolution policy.
	* @param SettingBeingUpdated The Gameplay Tag of the setting that is being updated with the new keybinding.
	* @param NewKey The new keybinding value that is being applied to the setting.
	* @param OldKey The old keybinding value that is being replaced by the new keybinding for the setting.
	* @param CollisionChannels The Gameplay Tag container of collision channels to check against. Only settings that have at least one of these tags in their collision channels will be checked for collision.
	* @param ResolutionPolicy The policy to use for resolving keybinding collisions if the new keybinding collides with existing keybindings.
	* **AllowDuplicate** means the new keybinding will be applied even if there is a collision. **Overwrite** means the existing conflicting keybind will be removed. **Swap** means the existing conflicting keybind will be changed to the new keybinding's old value.
	* @return true if the collision was resolved successfully, false if resolution failed.
	*/
	bool ResolveKeybindingCollision(const FGameplayTag& SettingBeingUpdated, const struct FKey& NewKey, const struct FKey& OldKey, const FGameplayTagContainer& CollisionChannels, const enum ESFKeybindCollisionResolution& ResolutionPolicy);
#pragma endregion
};
