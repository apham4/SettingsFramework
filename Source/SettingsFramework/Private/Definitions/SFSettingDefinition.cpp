// Copyright 2026 Anh Pham. All Rights Reserved.


#include "Definitions/SFSettingDefinition.h"
#include "Core/SFSettingValue.h"
#include "Definitions/SFSettingOptionSource.h"

#pragma region Discrete Setting
void USFSettingDefinition_Discrete::PostLoad()
{
	Super::PostLoad();
	if (OptionSource)
	{
		CachedSettingOptionSource = NewObject<USFSettingOptionSource>(this, OptionSource);
	}
}

TArray<struct FSFSettingOption> USFSettingDefinition_Discrete::GetSettingOptions(const UObject* WorldContextObject) const
{
	TArray<struct FSFSettingOption> options;
	if (bUseDynamicOptions && IsValid(CachedSettingOptionSource))
	{
		options = CachedSettingOptionSource->GetAvailableOptions(WorldContextObject);
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
	if (bUseDynamicOptions && IsValid(CachedSettingOptionSource))
	{
		defaultValue = CachedSettingOptionSource->GetDefaultValue(WorldContextObject);
	}
	else
	{
		defaultValue = DefaultValue;
	}
	return defaultValue;
}
#pragma endregion