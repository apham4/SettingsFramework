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

class USFSettingEntryWidget* USFSettingGroupWidget::GetFirstValidSettingEntry() const
{
	if (!IsValid(SettingEntryContainer))
	{
		return nullptr;
	}
	
	USFSettingEntryWidget* validEntry = nullptr;
	for (UWidget* child : SettingEntryContainer->GetAllChildren())
	{
		USFSettingEntryWidget* asSettingEntry = Cast<USFSettingEntryWidget>(child);
		if (IsValid(asSettingEntry) && asSettingEntry->IsVisible() && asSettingEntry->GetIsEnabled())
		{
			validEntry = asSettingEntry;
			break;
		}
	}

	return validEntry;
}