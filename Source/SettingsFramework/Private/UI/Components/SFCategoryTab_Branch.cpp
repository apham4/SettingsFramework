// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/Components/SFCategoryTab_Branch.h"
#include "Definitions/SFSettingCategory.h"
#include "CommonButtonBase.h"
#include "CommonTabListWidgetBase.h"
#include "CommonAnimatedSwitcher.h"
#include "Core/SFLogs.h"
#include "SFSettingsDeveloperSettings.h"
#include "UI/Components/SFCategoryTab_Leaf.h"
#include "UI/Components/SFCategoryTabButtonBase.h"

#pragma region Initialization
void USFCategoryTab_Branch::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (IsValid(TabContentSwitcher))
	{
		TabContentSwitcher->OnActiveWidgetIndexChanged.AddUObject(this, &USFCategoryTab_Branch::HandleSwitcherActiveIndexChanged);
	}
}

void USFCategoryTab_Branch::InitializeCategoryDisplay()
{
	if (bInitialized || !IsValid(SettingCategory))
	{
		return;
	}

	const USFSettingsDeveloperSettings* developerSettings = GetDefault<USFSettingsDeveloperSettings>();
	if (!IsValid(developerSettings))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFCategoryTab_Branch::InitializeCategoryDisplay - Failed to get Plugin Developer Settings."));
		return;
	}
	if (!IsValid(developerSettings->BranchTabButtonClass))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFCategoryTab_Branch::InitializeCategoryDisplay - Tab Button Class is not set in Developer Settings. Set this in Project Settings > Plugins > Settings Framework."));
		return;
	}
	if (!IsValid(developerSettings->LeafTabContentClass))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFCategoryTab_Branch::InitializeCategoryDisplay - Leaf Tab Content Class is not set in Developer Settings. Set this in Project Settings > Plugins > Settings Framework."));
		return;
	}
	if (!IsValid(SubCategoryTabList) || !IsValid(TabContentSwitcher))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFCategoryTab_Branch::InitializeCategoryDisplay - Failed to get instances of Tab List or TabContentSwitcher in widget."));
		return;
	}

	SubCategoryTabList->SetLinkedSwitcher(TabContentSwitcher);
	for (USFSettingCategory* category : SettingCategory->Subcategories)
	{
		if (!IsValid(category) || !category->CategoryTag.IsValid())
		{
			continue;
		}

		USFCategoryTabBase* tabContent = nullptr;
		switch (category->CategoryType)
		{
		case ESFCategoryType::Branch:
			UE_LOG(LogSettingsFramework, Warning, TEXT("[SettingsFramework] USFCategoryTab_Branch::InitializeCategoryDisplay - Detected branch-type category %s inside branch-type category %s. SettingsFramework UI only supports up to 1 level of nested categories for usability. This category will not be initialized and populated."), *category->CategoryTag.ToString(), *SettingCategory->CategoryTag.ToString());
			break;
		case ESFCategoryType::Leaf:
			tabContent = Cast<USFCategoryTabBase>(CreateWidget(this, developerSettings->LeafTabContentClass));
			break;
		}

		if (IsValid(tabContent))
		{
			tabContent->SetCategory(category);
			tabContent->OnSettingFocused.AddDynamic(this, &USFCategoryTab_Branch::HandleSubCategorySettingFocused);
			SubCategoryTabList->RegisterTab(FName(category->CategoryTag.ToString()), developerSettings->BranchTabButtonClass, tabContent);
			USFCategoryTabButtonBase* tabButton = Cast<USFCategoryTabButtonBase>(SubCategoryTabList->GetTabButtonBaseByID(FName(category->CategoryTag.ToString())));
			if (IsValid(tabButton))
			{
				tabButton->SetCategoryData(category);
			}
		}
		TabContentSwitcher->AddChild(tabContent);
	}

	HandleSwitcherActiveIndexChanged(TabContentSwitcher->GetChildAt(0), 0);

	bInitialized = true;
}

void USFCategoryTab_Branch::HandleSwitcherActiveIndexChanged(UWidget* ContentWidget, int32 Index)
{
	USFCategoryTabBase* categoryTab = Cast<USFCategoryTabBase>(ContentWidget);
	if (IsValid(categoryTab))
	{
		categoryTab->InitializeCategoryDisplay();
	}
}

void USFCategoryTab_Branch::HandleSubCategorySettingFocused(const struct FGameplayTag& SettingTag)
{
	// Bubble event up to screen so it can update the details panel
	OnSettingFocused.Broadcast(SettingTag);
}
#pragma endregion

#pragma region Navigation
UWidget* USFCategoryTab_Branch::GetDesiredFocusTarget() const
{
	UWidget* activeWidget = IsValid(TabContentSwitcher) ? TabContentSwitcher->GetActiveWidget() : nullptr;
	return IsValid(activeWidget) ? activeWidget : nullptr;
}
#pragma endregion