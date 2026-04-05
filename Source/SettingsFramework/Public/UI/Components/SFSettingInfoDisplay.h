// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SFSettingInfoDisplay.generated.h"

/**
 * @brief Base widget class for displaying detailed information of a setting (name, description, etc.) when its entry widget is focused/hovered.
 *
 * Base widget class for displaying detailed information of a setting (name, description, etc.) when its entry widget is focused/hovered.
 * @note @abstract @blueprinttype @blueprintable
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingInfoDisplay : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	/**
	* Display the information of the setting represented by the given setting Gameplay Tag.
	* @param SettingTag The Gameplay Tag representing the setting to display.
	*/
	void DisplaySetting(const struct FGameplayTag& SettingTag);
	
protected:
	/**
	* Display the information of the setting represented by the given setting definition. Internal and intended to be overridden in Blueprint subclass for actual info display.
	* @param SettingDefinition The setting definition representing the setting to display.
	* @note @bie
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingInfoDisplay")
	void DisplaySettingByDefinition(const class USFSettingDefinition* SettingDefinition);
};
