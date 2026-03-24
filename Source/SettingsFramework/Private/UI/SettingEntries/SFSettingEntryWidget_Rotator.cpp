// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SettingEntries/SFSettingEntryWidget_Rotator.h"
#include "CommonRotator.h"
#include "Core/SFCoreTypes.h"
#include "Core/SFSettingValue.h"
#include "Definitions/SFSettingDefinition.h"
#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"

void USFSettingEntryWidget_Rotator::InitializeSettingEntry(const USFSettingDefinition* InSettingDefinition)
{
	const USFSettingDefinition_Discrete* discreteSettingDef = Cast<USFSettingDefinition_Discrete>(InSettingDefinition);
	if (!IsValid(discreteSettingDef) || !IsValid(RotatorWidget))
	{
		return;
	}

	PopulateOptions(discreteSettingDef->GetSettingOptions(this));

	Super::InitializeSettingEntry(InSettingDefinition);
	RotatorWidget->OnRotatedWithDirection.AddDynamic(this, &USFSettingEntryWidget_Rotator::HandleRotatorRotated);

	// For dynamic options
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(GetWorld());
	if (discreteSettingDef->bUseDynamicOptions && IsValid(settingsSubsystem))
	{
		settingsSubsystem->OnSettingValueChanged.AddDynamic(this, &USFSettingEntryWidget_Rotator::CheckForDeterminantSettings);
	}
}

void USFSettingEntryWidget_Rotator::RefreshOptions()
{
	const USFSettingDefinition_Discrete* settingDef = Cast<USFSettingDefinition_Discrete>(GetSettingDefinition());
	if (!IsValid(settingDef) || !IsValid(RotatorWidget))
	{
		return;
	}

	// Cache currently selected option
	FSFSettingOption currentSelectedOption = Options[RotatorWidget->GetSelectedIndex()];

	// Refresh the dynamic options
	PopulateOptions(settingDef->GetSettingOptions(this));

	// Reselect the option
	// If it was not found, select the default option
	if (!SelectOptionByValue(currentSelectedOption.Value))
	{
		SelectOptionByValue(settingDef->GetDefaultValue(this));
	}
}

void USFSettingEntryWidget_Rotator::UpdateVisualValue_Implementation(const class USFSettingValue* NewValue)
{
	if (!IsValid(RotatorWidget) || !IsValid(NewValue))
	{
		return;
	}
	SelectOptionByValue(NewValue);
}

void USFSettingEntryWidget_Rotator::HandleRotatorRotated(int32 NewValue, ERotatorDirection RotatorDirection)
{
	if (NewValue < 0 || NewValue >= Options.Num())
	{
		return;
	}
	OnUserChangedValue(Options[NewValue].Value);
}

void USFSettingEntryWidget_Rotator::CheckForDeterminantSettings(const FGameplayTag& ChangedSettingTag, USFSettingValue* NewValue)
{
	// Check if there was a value change from a determinant setting. If so, refresh options.
	const USFSettingDefinition_Discrete* settingDef = Cast<USFSettingDefinition_Discrete>(GetSettingDefinition());
	if (!IsValid(settingDef) || !settingDef->DeterminantSettingTags.HasTag(ChangedSettingTag))
	{
		return;
	}
	RefreshOptions();
}

#pragma region Helpers
void USFSettingEntryWidget_Rotator::PopulateOptions(const TArray<FSFSettingOption>& SettingOptions)
{
	if (!IsValid(RotatorWidget))
	{
		return;
	}

	Options = SettingOptions;
	TArray<FText> optionDisplayTexts;
	for (const FSFSettingOption& settingOption : Options)
	{
		optionDisplayTexts.Emplace(settingOption.DisplayName);
	}
	RotatorWidget->PopulateTextLabels(optionDisplayTexts);
}

bool USFSettingEntryWidget_Rotator::SelectOptionByValue(const USFSettingValue* Value)
{
	if (!IsValid(RotatorWidget))
	{
		return false;
	}

	bool bFound = false;
	for (int32 i = 0; i < Options.Num(); ++i)
	{
		if (Options[i].Value->Equals(Value))
		{
			RotatorWidget->SetSelectedItem(i);
			bFound = true;
			break;
		}
	}
	return bFound;
}
#pragma endregion