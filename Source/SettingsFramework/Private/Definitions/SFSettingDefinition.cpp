// Copyright 2026 Anh Pham. All Rights Reserved.


#include "Definitions/SFSettingDefinition.h"
#include "Core/SFSettingValue.h"
#include "Definitions/SFSettingOptionSource.h"
#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"

#pragma region Discrete Setting
TSubclassOf<USFSettingValue> USFSettingDefinition_Discrete::GetValueClass() const
{
	if (ValueWrapperClass)
	{
		return ValueWrapperClass;
	}
	else
	{
		return USFSettingValue_Tag::StaticClass();
	}
}

TArray<struct FSFSettingOption> USFSettingDefinition_Discrete::GetSettingOptions(const UObject* WorldContextObject) const
{
	TArray<struct FSFSettingOption> options;
	if (bUseDynamicOptions)
	{
		USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(WorldContextObject);
		USFSettingOptionSource* optionSource = IsValid(settingsSubsystem) ? settingsSubsystem->GetDynamicOptionSource(SettingTag) : nullptr;
		if (IsValid(optionSource))
		{
			options = optionSource->GetAvailableOptions(WorldContextObject);
		}
	}
	else
	{
		options = StaticOptions;
	}
	return options;
}

USFSettingValue* USFSettingDefinition_Discrete::GetDefaultValue(const UObject* WorldContextObject) const
{
	USFSettingValue* defaultValue = nullptr;
	if (bUseDynamicOptions)
	{
		USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(WorldContextObject);
		USFSettingOptionSource* optionSource = IsValid(settingsSubsystem) ? settingsSubsystem->GetDynamicOptionSource(SettingTag) : nullptr;
		if (IsValid(optionSource))
		{
			defaultValue = optionSource->GetDefaultValue(WorldContextObject);
		}
	}
	else
	{
		defaultValue = DefaultValue;
	}
	return defaultValue;
}
#pragma endregion