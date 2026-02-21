// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Slider.generated.h"

/**
 * Setting entry widget for scalar settings, represented as a slider in the UI.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Slider : public USFSettingEntryWidget
{
	GENERATED_BODY()

protected:
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

	UFUNCTION()
	void HandleSliderValueChanged(float NewValue);

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Slider", meta = (BindWidget))
	TObjectPtr<class UAnalogSlider> SliderWidget;
};
