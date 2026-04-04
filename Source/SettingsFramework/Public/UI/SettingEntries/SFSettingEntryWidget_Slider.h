// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Slider.generated.h"

/**
  * @brief The native base class for a setting entry widget for a scalar setting, represented as an analog slider in the UI.
  *
  * The native base class for a setting entry widget for a scalar setting, represented as an analog slider in the UI.
  *
  * The widget blueprint implementing this class should be assigned as a value to the SettingEntryWidgetClasses map with the scalar setting definition class (USFSettingDefinition_Scalar) as the key in the Developer Settings at Project Settings > Plugins > SettingsFramework.
  */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Slider : public USFSettingEntryWidget
{
	GENERATED_BODY()

protected:
	/**
	* @inheritdoc
	*/
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;

	/**
	* @inheritdoc
	*/
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

	/** @cond */
	UFUNCTION()
	void HandleSliderValueChanged(float NewValue);
	/** @endcond */

	/**
	* The analog slider widget representing the scalar setting value in the UI.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Slider", meta = (BindWidget))
	TObjectPtr<class UAnalogSlider> SliderWidget;
};
