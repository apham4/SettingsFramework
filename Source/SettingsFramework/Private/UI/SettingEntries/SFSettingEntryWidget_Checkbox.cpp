// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SettingEntries/SFSettingEntryWidget_Checkbox.h"
#include "Components/CheckBox.h"
#include "Core/SFSettingValue.h"

void USFSettingEntryWidget_Checkbox::InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition)
{
	Super::InitializeSettingEntry(InSettingDefinition);
	if (IsValid(CheckboxWidget))
	{
		CheckboxWidget->OnCheckStateChanged.AddDynamic(this, &USFSettingEntryWidget_Checkbox::HandleCheckStateChanged);
	}
}

void USFSettingEntryWidget_Checkbox::UpdateVisualValue_Implementation(const class USFSettingValue* NewValue)
{
	const USFSettingValue_Bool* boolValue = Cast<USFSettingValue_Bool>(NewValue);
	if (!IsValid(CheckboxWidget) || !IsValid(boolValue))
	{
		return;
	}
	CheckboxWidget->SetIsChecked(boolValue->Value);
}

void USFSettingEntryWidget_Checkbox::HandleCheckStateChanged(bool bIsChecked)
{
	USFSettingValue_Bool* newVal = NewObject<USFSettingValue_Bool>();
	newVal->Value = bIsChecked;
	OnUserChangedValue(newVal);
}