// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SFSettingsDeveloperSettings.generated.h"

/**
 * Developer settings for the SettingsFramework plugin.
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Settings Framework"))
class SETTINGSFRAMEWORK_API USFSettingsDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	// The master registry asset containing setting hierarchy and definitions. Loaded asynchronously on SFSettingsSubsystem initialization.
	UPROPERTY(Config, EditAnywhere, Category = "Registry")
	TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistry;

	// Mapping of Definition Classes to Widget Classes (e.g. USFSettingDefinition_Scalar -> WBP_Setting_Slider)
	UPROPERTY(Config, EditAnywhere, Category = "UI Mappings")
	TMap<TSubclassOf<USFSettingDefinition>, TSubclassOf<class USFSettingEntryWidget>> WidgetClasses;

	// Save slot name for saving and loading setting values.
	UPROPERTY(Config, EditAnywhere, Category = "Serialization")
	FString SaveGameSlotName = TEXT("SF_SaveSlot");

	// Recursion guard: Maximum depth for updating setting dependencies to prevent infinite loops.
	UPROPERTY(Config, EditAnywhere, Category = "Conditions")
	int32 MaxUpdateDepth = 10;

public:
	virtual FName GetCategoryName() const override
	{
		return FName("Plugins");
	}
};
