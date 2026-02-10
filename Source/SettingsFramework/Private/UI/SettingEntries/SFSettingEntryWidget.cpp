// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "Definitions/SFSettingDefinition.h"
#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"

void USFSettingEntryWidget::InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition)
{
	if (!IsValid(InSettingDefinition))
	{
		return;
	}
	SettingTag = InSettingDefinition->SettingTag;
	BP_InitializeSettingEntry(InSettingDefinition);
}

USFSettingDefinition* USFSettingEntryWidget::GetSettingDefinition() const
{
	const USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(GetWorld());
	return IsValid(settingsSubsystem) ? settingsSubsystem->GetSettingDefinition(SettingTag) : nullptr;
}

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

	if (SettingTag.IsValid())
	{
		OnSettingFocused.Broadcast(SettingTag);
	}
}