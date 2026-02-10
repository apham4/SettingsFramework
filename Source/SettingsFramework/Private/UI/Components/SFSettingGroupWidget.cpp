// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/Components/SFSettingGroupWidget.h"
#include "Components/PanelWidget.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"

void USFSettingGroupWidget::AddSettingEntry(USFSettingEntryWidget* EntryWidget)
{
	if (!IsValid(SettingEntryContainer) || !IsValid(EntryWidget))
	{
		return;
	}

	UPanelSlot* panelSlot = SettingEntryContainer->AddChild(EntryWidget);
	OnSettingEntryAdded(panelSlot, EntryWidget);
}

class USFSettingEntryWidget* USFSettingGroupWidget::GetFirstSettingEntry() const
{
	return (IsValid(SettingEntryContainer) && SettingEntryContainer->GetChildrenCount() > 0) ? Cast<USFSettingEntryWidget>(SettingEntryContainer->GetChildAt(0)) : nullptr;
}