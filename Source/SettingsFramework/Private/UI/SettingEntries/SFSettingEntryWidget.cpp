// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "Definitions/SFSettingDefinition.h"
#include "Core/SFSettingValue.h"
#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"
#include "CommonTextBlock.h"

#pragma region Initialization
void USFSettingEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	bIsFocusable = true;
}

void USFSettingEntryWidget::InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition)
{
	if (!IsValid(InSettingDefinition))
	{
		return;
	}

	SettingTag = InSettingDefinition->SettingTag;
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(GetWorld());
	if (IsValid(settingsSubsystem))
	{
		settingsSubsystem->OnSettingValueChanged.AddDynamic(this, &USFSettingEntryWidget::HandleOnSettingValueChanged);
		HandleOnSettingValueChanged(SettingTag, settingsSubsystem->GetSettingValue(SettingTag));
	}

	if (IsValid(SettingLabel))
	{
		SettingLabel->SetText(InSettingDefinition->DisplayName);
	}

	BP_InitializeSettingEntry(InSettingDefinition);
}

void USFSettingEntryWidget::HandleOnSettingValueChanged(const FGameplayTag& ChangedSettingTag, USFSettingValue* NewValue)
{
	if (ChangedSettingTag == SettingTag)
	{
		UpdateVisualValue(NewValue);
	}
	UpdateWidgetState(); // Update state whenever any setting changes, in case there are inter-setting dependencies that affect enabled/disabled state of this setting entry
}
#pragma endregion

#pragma region Setting Data
USFSettingDefinition* USFSettingEntryWidget::GetSettingDefinition() const
{
	const USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(GetWorld());
	return IsValid(settingsSubsystem) ? settingsSubsystem->GetSettingDefinition(SettingTag) : nullptr;
}
#pragma endregion

#pragma region Setting Value & State
void USFSettingEntryWidget::OnUserChangedValue(USFSettingValue* NewValue)
{
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(GetWorld());
	if (IsValid(settingsSubsystem))
	{
		settingsSubsystem->SetSettingValue(SettingTag, NewValue);
	}
}

void USFSettingEntryWidget::UpdateWidgetState()
{
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(GetWorld());
	if (!IsValid(settingsSubsystem))
	{
		return;
	}
	SetVisibility(settingsSubsystem->IsSettingVisible(SettingTag) ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	SetIsEnabled(settingsSubsystem->IsSettingEditable(SettingTag));
}
#pragma endregion

#pragma region Navigation
void USFSettingEntryWidget::NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnAddedToFocusPath(InFocusEvent);
	if (SettingTag.IsValid())
	{
		OnSettingFocused.Broadcast(SettingTag);
	}
}

void USFSettingEntryWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	SetFocus();
}
#pragma endregion