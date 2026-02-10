// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SFSettingsDeveloperSettings.generated.h"

/**
 * Developer settings for the SettingsFramework plugin. TODO: Add all these in instructions documentation.
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Settings Framework"))
class SETTINGSFRAMEWORK_API USFSettingsDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	// The master registry asset containing setting hierarchy and definitions. Loaded asynchronously on SFSettingsSubsystem initialization.
	UPROPERTY(Config, EditAnywhere, Category = "Settings Registry")
	TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistry;

	// Save slot name for saving and loading setting values.
	UPROPERTY(Config, EditAnywhere, Category = "Settings Serialization")
	FString SaveGameSlotName = TEXT("SF_SaveSlot");

	// Recursion guard: Maximum depth for updating setting dependencies to prevent infinite loops.
	UPROPERTY(Config, EditAnywhere, Category = "Settings Conditions")
	int32 MaxUpdateDepth = 10;

	// Widget class for settings UI's category tab buttons.
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class UCommonButtonBase> TabButtonClass;

	// Widget class for displaying a branch-type category (contains sub-categories).
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFCategoryTab_Branch> BranchTabContentClass;

	// Widget class for displaying a leaf-type category (contains setting entries).
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFCategoryTab_Leaf> LeafTabContentClass;

	// Widget class for displaying a setting group (visually groups related settings within a leaf category).
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TSubclassOf<class USFSettingGroupWidget> SettingGroupWidgetClass;

	// Mapping of Definition Classes to Widget Classes (e.g. USFSettingDefinition_Scalar -> WBP_Setting_Slider)
	UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
	TMap<TSubclassOf<class USFSettingDefinition>, TSubclassOf<class USFSettingEntryWidget>> WidgetClasses;

public:
	virtual FName GetCategoryName() const override
	{
		return FName("Plugins");
	}
};
