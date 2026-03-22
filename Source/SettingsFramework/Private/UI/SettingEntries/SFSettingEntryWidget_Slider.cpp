// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SettingEntries/SFSettingEntryWidget_Slider.h"
#include "AnalogSlider.h"
#include "Core/SFSettingValue.h"
#include "Definitions/SFSettingDefinition.h"

void USFSettingEntryWidget_Slider::InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition)
{
	Super::InitializeSettingEntry(InSettingDefinition);
	const USFSettingDefinition_Scalar* scalarSettingDef = Cast<USFSettingDefinition_Scalar>(InSettingDefinition);
	if (!IsValid(scalarSettingDef) || !IsValid(SliderWidget))
	{
		return;
	}
	SliderWidget->SetMinValue(scalarSettingDef->MinValue);
	SliderWidget->SetMaxValue(scalarSettingDef->MaxValue);
	SliderWidget->SetStepSize(scalarSettingDef->StepSize);
	SliderWidget->MouseUsesStep = true;
	SliderWidget->OnValueChanged.AddDynamic(this, &USFSettingEntryWidget_Slider::HandleSliderValueChanged);
}

void USFSettingEntryWidget_Slider::UpdateVisualValue_Implementation(const class USFSettingValue* NewValue)
{
	const USFSettingValue_Scalar* scalarValue = Cast<USFSettingValue_Scalar>(NewValue);
	if (!IsValid(SliderWidget) || !IsValid(scalarValue) || FMath::IsNearlyEqual(SliderWidget->GetValue(), scalarValue->Value))
	{
		return;
	}
	SliderWidget->SetValue(scalarValue->Value);
}

void USFSettingEntryWidget_Slider::HandleSliderValueChanged(float NewValue)
{
	USFSettingValue_Scalar* newVal = NewObject<USFSettingValue_Scalar>();
	newVal->Value = NewValue;
	OnUserChangedValue(newVal);
}