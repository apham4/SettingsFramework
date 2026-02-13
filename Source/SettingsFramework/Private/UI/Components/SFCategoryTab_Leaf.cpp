// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/Components/SFCategoryTab_Leaf.h"
#include "Components/PanelWidget.h"
#include "SFSettingsDeveloperSettings.h"
#include "Core/SFLogs.h"
#include "UI/Components/SFSettingGroupWidget.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "Definitions/SFSettingCategory.h"
#include "Definitions/SFSettingDefinition.h"

#pragma region Initialization
void USFCategoryTab_Leaf::NativeOnActivated()
{
	Super::NativeOnActivated();

	if (bInitialized || !IsValid(SettingCategory))
	{
		return;
	}

	const USFSettingsDeveloperSettings* developerSettings = GetDefault<USFSettingsDeveloperSettings>();
	if (!IsValid(developerSettings))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFCategoryTab_Leaf::NativeOnActivated - Failed to get Plugin Developer Settings."));
		return;
	}
	if (!IsValid(developerSettings->SettingGroupWidgetClass))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFCategoryTab_Leaf::NativeOnActivated - Setting Group Widget Class is not set in Developer Settings. Set this in Project Settings > Plugins > Settings Framework."));
		return;
	}

	// Case 1: setting groups
	for (const FSFSettingGroup& group : SettingCategory->SettingGroups)
	{
		USFSettingGroupWidget* groupWidget = CreateWidget<USFSettingGroupWidget>(this, developerSettings->SettingGroupWidgetClass);
		if (!IsValid(groupWidget))
		{
			continue;
		}

		groupWidget->DisplaySettingGroupInfo(group);
		for (const USFSettingDefinition* setting : group.Settings)
		{
			CreateSettingEntryAndAddToGroup(setting, groupWidget);
		}

		UPanelSlot* groupAsPanelWidget = SettingGroupContainer->AddChild(groupWidget);
		OnGroupWidgetAdded(groupAsPanelWidget, groupWidget);
	}

	// Case 2: setting list
	if (SettingCategory->SettingGroups.Num() == 0)
	{
		USFSettingGroupWidget* groupWidget = CreateWidget<USFSettingGroupWidget>(this, developerSettings->SettingGroupWidgetClass);
		if (IsValid(groupWidget))
		{
			groupWidget->DisplaySettingGroupInfo(FSFSettingGroup());
			for (const USFSettingDefinition* setting : SettingCategory->Settings)
			{
				CreateSettingEntryAndAddToGroup(setting, groupWidget);
			}
		}
		UPanelSlot* groupAsPanelWidget = SettingGroupContainer->AddChild(groupWidget);
		OnGroupWidgetAdded(groupAsPanelWidget, groupWidget);
	}

	bInitialized = true;
}

void USFCategoryTab_Leaf::CreateSettingEntryAndAddToGroup(const USFSettingDefinition* SettingDefinition, USFSettingGroupWidget* GroupWidget)
{
	const USFSettingsDeveloperSettings* developerSettings = GetDefault<USFSettingsDeveloperSettings>();
	if (!IsValid(SettingDefinition) || !IsValid(developerSettings))
	{
		return;
	}

	const TSubclassOf<USFSettingEntryWidget>* entryWidgetClassPtr = developerSettings->SettingEntryWidgetClasses.Find(SettingDefinition->GetClass());
	USFSettingEntryWidget* entryWidget = (entryWidgetClassPtr != nullptr && IsValid(*entryWidgetClassPtr)) ? CreateWidget<USFSettingEntryWidget>(this, *entryWidgetClassPtr) : nullptr;
	if (!IsValid(entryWidget))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFCategoryTab_Leaf::CreateSettingEntryAndAddToGroup - Failed to create an entry widget for setting %s."), *SettingDefinition->SettingTag.ToString());
		return;
	}

	entryWidget->InitializeSettingEntry(SettingDefinition);
	entryWidget->OnSettingFocused.AddDynamic(this, &USFCategoryTab_Leaf::HandleSettingEntryFocused);
	GroupWidget->AddSettingEntry(entryWidget);
}

void USFCategoryTab_Leaf::HandleSettingEntryFocused(const FGameplayTag& SettingTag)
{
	// Bubble up to screen so that the description box can display the focused setting's description.
	OnSettingFocused.Broadcast(SettingTag);
}
#pragma endregion

#pragma region CommonUI Navigation
UWidget* USFCategoryTab_Leaf::NativeGetDesiredFocusTarget() const
{
	USFSettingGroupWidget* firstGroup = (IsValid(SettingGroupContainer) && SettingGroupContainer->GetChildrenCount() > 0) ? Cast<USFSettingGroupWidget>(SettingGroupContainer->GetChildAt(0)) : nullptr;
	return IsValid(firstGroup) ? firstGroup->GetFirstSettingEntry() : Super::NativeGetDesiredFocusTarget();
}
#pragma endregion