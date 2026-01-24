// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SFSettingsDeveloperSettings.generated.h"

/**
 * Class for defining developer settings for the Settings Framework plugin.
 * These settings can be accessed and modified via the Unreal Editor's Project Settings.
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Settings Framework"))
class SETTINGSFRAMEWORK_API USFSettingsDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	// The master registry asset containing setting hierarchy and definitions. Loaded asynchronously on SFSettingsSubsystem initialization.
	UPROPERTY(Config, EditAnywhere, Category = "Settings Registry")
	TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistry;

public:
	virtual FName GetCategoryName() const override
	{
		return FName("Plugins");
	}
};
