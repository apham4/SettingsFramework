// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/Components/SFSettingInfoDisplay.h"
#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"

void USFSettingInfoDisplay::DisplaySetting(const struct FGameplayTag& SettingTag)
{
	const USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(this);
	const class USFSettingDefinition* settingDef = IsValid(settingsSubsystem) ? settingsSubsystem->GetSettingDefinition(SettingTag) : nullptr;
	DisplaySettingByDefinition(settingDef);
}