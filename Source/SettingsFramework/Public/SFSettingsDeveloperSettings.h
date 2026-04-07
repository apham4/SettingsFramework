// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Core/SFCoreTypes.h"
#include "Templates/SubclassOf.h"
#include "SFSettingsDeveloperSettings.generated.h"

/**
 * @brief Developer settings to define project-wide configurations for the Settings Framework plugin.
 *
 * Developer settings to define project-wide configurations for the Settings Framework plugin. 
 * Accessed through **Project Settings** > **Plugins** > **Settings Framework** in the Unreal Editor.
 * @note @configgame
 */
UCLASS(Config = Game, meta = (DisplayName = "Settings Framework", ToolTip = "Developer settings to define project-wide configurations for the Settings Framework plugin."))
class SETTINGSFRAMEWORK_API USFSettingsDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	/**
	* The master registry asset containing setting hierarchy and definitions. Loaded asynchronously on USFSettingsSubsystem initialization.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings Registry")
	TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistry;

	/**
	* Save slot name for saving and loading setting values to and from disk.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings Serialization")
	FString SaveGameSlotName = TEXT("SF_SaveSlot");

	/**
	* The recursion guard for conditional dependencies: Maximum depth for updating setting dependencies to prevent infinite loops. If the depth is exceeded, a warning will be logged and the update will be halted.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings Conditions")
	int32 MaxUpdateDepth = 10;

	/**
	* The default keybind collision resolution policy when adding a new keybind that conflicts with an existing one.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings Logic")
	ESFKeybindCollisionResolution DefaultKeybindCollisionResolution = ESFKeybindCollisionResolution::Overwrite;

	/**
	* The widget class for the Settings Screen UI's root category tab buttons.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFCategoryTabButtonBase> RootTabButtonClass;

	/**
	* The widget class for the Settings Screen UI's branch category tab buttons.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFCategoryTabButtonBase> BranchTabButtonClass;

	/**
	* The widget class for displaying the content of a Branch category (containing sub-categories) in the Settings Screen UI.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFCategoryTab_Branch> BranchTabContentClass;

	/**
	* The widget class for displaying the content of a Leaf category (containing setting groups and setting entries) in the Settings Screen UI.
	* @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFCategoryTab_Leaf> LeafTabContentClass;

	/**
	* The widget class for displaying a setting group in the Settings Screen UI.
	* @note @config @ea 
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFSettingGroupWidget> SettingGroupWidgetClass;

	/**
	* The mapping of widget classes to display each variation of setting definition (e.g. a slider widget for a scalar setting) in the Settings Screen UI.
	* * @note @config @ea
	*/
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TMap<TSubclassOf<class USFSettingDefinition>, TSubclassOf<class USFSettingEntryWidget>> SettingEntryWidgetClasses;

public:
	virtual FName GetCategoryName() const override
	{
		return FName("Plugins");
	}
};
