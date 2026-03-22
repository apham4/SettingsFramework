// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SettingEntries/SFSettingEntryWidget_Rotator.h"
#include "CommonRotator.h"
#include "Core/SFCoreTypes.h"
#include "Core/SFSettingValue.h"
#include "Definitions/SFSettingDefinition.h"

void USFSettingEntryWidget_Rotator::InitializeSettingEntry(const USFSettingDefinition* InSettingDefinition)
{
	Super::InitializeSettingEntry(InSettingDefinition);
	const USFSettingDefinition_Discrete* discreteSettingDef = Cast<USFSettingDefinition_Discrete>(InSettingDefinition);
	if (!IsValid(discreteSettingDef) || !IsValid(RotatorWidget))
	{
		return;
	}

	Options = discreteSettingDef->GetSettingOptions(this);
	TArray<FText> optionDisplayTexts;
	for (const FSFSettingOption& settingOption : Options)
	{
		optionDisplayTexts.Emplace(settingOption.DisplayName);
	}
	RotatorWidget->PopulateTextLabels(optionDisplayTexts);
	RotatorWidget->OnRotatedWithDirection.AddDynamic(this, &USFSettingEntryWidget_Rotator::HandleRotatorRotated);
}

void USFSettingEntryWidget_Rotator::UpdateVisualValue_Implementation(const class USFSettingValue* NewValue)
{
	if (!IsValid(RotatorWidget) || !IsValid(NewValue))
	{
		return;
	}

	for (int32 i = 0; i < Options.Num(); ++i)
	{
		if (Options[i].Value->Equals(NewValue))
		{
			if (RotatorWidget->GetSelectedIndex() != i)
			{
				RotatorWidget->SetSelectedItem(i);
			}
			break;
		}
	}
}

void USFSettingEntryWidget_Rotator::HandleRotatorRotated(int32 NewValue, ERotatorDirection RotatorDirection)
{
	if (NewValue < 0 || NewValue >= Options.Num())
	{
		return;
	}
	OnUserChangedValue(Options[NewValue].Value);
}