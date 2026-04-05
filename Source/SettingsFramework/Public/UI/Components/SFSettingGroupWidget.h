// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SFSettingGroupWidget.generated.h"

/**
 * @brief The native base class for the widget displaying a setting group.
 *
 * The native base class for the widget displaying a setting group.
 *
 * The widget blueprint implementing this class should be assigned to the SettingGroupWidgetClass in the Developer Settings at Project Settings > Plugins > SettingsFramework.
 * @note @abstract @blueprinttype @blueprintable
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingGroupWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	/**
	* Display the metadata of the associated setting group. If the given struct is empty, clear the display.
	* @param SettingGroup The struct containing the metadata of the associated setting group.
	* @note @bie
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingGroup")
	void DisplaySettingGroupInfo(const struct FSFSettingGroup& SettingGroup);

	/**
	* Add an initialized setting entry widget to be displayed in this group. This is called by USFCategoryTab_Leaf when initializing the display of its setting entries.
	* @param EntryWidget The initialized setting entry widget to be added to this group.
	*/
	void AddSettingEntry(class USFSettingEntryWidget* EntryWidget);

	/**
	* Get the first setting entry widget in this group that is valid for navigation (visible and enabled). Used for setting initial focus when displaying a leaf category tab.
	* @return The first setting entry widget in this group that is valid for navigation, nullptr if none is found.
	*/
	class USFSettingEntryWidget* GetFirstValidSettingEntry() const;
	
protected:
	/**
	* Called when a setting entry widget is added to SettingEntryContainer. To be implemented in Blueprint to add any additional styling like padding and such.
	* @param EntryAsPanelSlot The added setting entry widget as a panel slot, used for styling.
	* @param EntryAsSettingWidget The added setting entry widget as a setting entry widget, used for any additional logic that may be needed.
	* @note @bie
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingGroup")
	void OnSettingEntryAdded(class UPanelSlot* EntryAsPanelSlot, class USFSettingEntryWidget* EntryAsSettingWidget);

	/**
	* The container widget for setting entries within this group. Setting entry widgets are added to this container when initializing the display of a leaf category tab.
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingGroup", meta = (BindWidget))
	TObjectPtr<class UPanelWidget> SettingEntryContainer;
};
