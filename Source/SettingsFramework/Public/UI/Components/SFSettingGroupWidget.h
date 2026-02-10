// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SFSettingGroupWidget.generated.h"

/**
 * Displays a group of setting entries, with a text name.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingGroupWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	// Implement in Blueprint: display the metadata of the given group. If empty struct, clear the display.
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingGroup")
	void DisplaySettingGroupInfo(const struct FSFSettingGroup& SettingGroup);

	// Add an initialized setting entry widget to this group.
	void AddSettingEntry(class USFSettingEntryWidget* EntryWidget);

	class USFSettingEntryWidget* GetFirstSettingEntry() const;
	
protected:
	// Implement in Blueprint: add any additional styling like padding and such.
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingGroup")
	void OnSettingEntryAdded(class UPanelSlot* EntryAsPanelSlot, class USFSettingEntryWidget* EntryAsSettingWidget);

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingGroup", meta = (BindWidget))
	TObjectPtr<class UPanelWidget> SettingEntryContainer;
};
