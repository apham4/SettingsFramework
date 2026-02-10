// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SFSettingInfoDisplay.generated.h"

/**
 * Widget for displaying detailed information of a setting (name, description, etc.) when it is focused/hovered.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingInfoDisplay : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	void DisplaySetting(const struct FGameplayTag& SettingTag);
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingInfoDisplay")
	void DisplaySettingByDefinition(const class USFSettingDefinition* SettingDefinition);
};
