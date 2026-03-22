// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SFSettingsScreen.h"
#include "CommonButtonBase.h"
#include "CommonTabListWidgetBase.h"
#include "CommonAnimatedSwitcher.h"
#include "Core/SFLogs.h"
#include "SFSettingsDeveloperSettings.h"
#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"
#include "Definitions/SFSettingCategory.h"
#include "UI/Components/SFSettingInfoDisplay.h"
#include "UI/Components/SFCategoryTab_Branch.h"
#include "UI/Components/SFCategoryTab_Leaf.h"
#include "UI/Components/SFCategoryTabButtonBase.h"

#pragma region Initialization
void USFSettingsScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (IsValid(TabContentSwitcher))
	{
		TabContentSwitcher->OnActiveWidgetIndexChanged.AddUObject(this, &USFSettingsScreen::HandleSwitcherActiveIndexChanged);
	}
}

void USFSettingsScreen::NativeOnActivated()
{
	Super::NativeOnActivated();
	
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(this);
	if (bTabsInitialized || !IsValid(settingsSubsystem))
	{
		if (!IsValid(settingsSubsystem))
		{
			UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFSettingsScreen:NativeOnActivated - Failed to get Settings Subsystem."));
		}
		return;
	}

	if (settingsSubsystem->IsInitialized())
	{
		InitializeSettingsScreen();
	}
	else
	{
		settingsSubsystem->OnSettingsInitialized.AddDynamic(this, &USFSettingsScreen::InitializeSettingsScreen);
	}
}

void USFSettingsScreen::InitializeSettingsScreen()
{
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(this);
	const USFSettingsDeveloperSettings* developerSettings = GetDefault<USFSettingsDeveloperSettings>();
	if (!IsValid(settingsSubsystem) || !IsValid(developerSettings))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFSettingsScreen:InitializeSettingsScreen - Failed to get Settings Subsystem or Plugin Developer Settings."));
		return;
	}
	if (!IsValid(developerSettings->RootTabButtonClass))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFSettingsScreen:InitializeSettingsScreen - Tab Button Class is not set in Developer Settings. Set this in Project Settings > Plugins > Settings Framework."));
		return;
	}
	if (!IsValid(developerSettings->BranchTabContentClass))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFSettingsScreen:InitializeSettingsScreen - Branch Tab Content Class is not set in Developer Settings. Set this in Project Settings > Plugins > Settings Framework."));
		return;
	}
	if (!IsValid(developerSettings->LeafTabContentClass))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFSettingsScreen:InitializeSettingsScreen - Leaf Tab Content Class is not set in Developer Settings. Set this in Project Settings > Plugins > Settings Framework."));
		return;
	}
	if (!IsValid(CategoryTabList) || !IsValid(TabContentSwitcher))
	{
		UE_LOG(LogSettingsFramework, Error, TEXT("[SettingsFramework] USFSettingsScreen:InitializeSettingsScreen - Failed to get instances of Tab List or TabContentSwitcher in widget."));
		return;
	}
	
	TabContentSwitcher->ClearChildren();
	CategoryTabList->SetLinkedSwitcher(TabContentSwitcher);

	TArray<USFSettingCategory*> rootCategories = settingsSubsystem->GetRootCategories();
	for (USFSettingCategory* category : rootCategories)
	{
		if (!IsValid(category) || !category->CategoryTag.IsValid())
		{
			continue;
		}

		USFCategoryTabBase* tabContent = nullptr;
		switch (category->CategoryType)
		{
		case ESFCategoryType::Branch:
			tabContent = Cast<USFCategoryTabBase>(CreateWidget(this, developerSettings->BranchTabContentClass));
			break;
		case ESFCategoryType::Leaf:
			tabContent = Cast<USFCategoryTabBase>(CreateWidget(this, developerSettings->LeafTabContentClass));
			break;
		}

		if (IsValid(tabContent))
		{
			tabContent->SetCategory(category);
			tabContent->OnSettingFocused.AddDynamic(this, &USFSettingsScreen::HandleSettingFocused);
			CategoryTabList->RegisterTab(FName(category->CategoryTag.ToString()), developerSettings->RootTabButtonClass, tabContent);
			USFCategoryTabButtonBase* tabButton = Cast<USFCategoryTabButtonBase>(CategoryTabList->GetTabButtonBaseByID(FName(category->CategoryTag.ToString())));
			if (IsValid(tabButton))
			{
				tabButton->SetCategoryData(category);
			}
			TabContentSwitcher->AddChild(tabContent);
		}
	}

	// Select first tab after initializing
	/*if (rootCategories.Num() > 0 && TabContentSwitcher->GetChildrenCount() > 0)
	{
		FName FirstTabID = FName(rootCategories[0]->CategoryTag.ToString());
		CategoryTabList->SelectTabByID(FirstTabID);
		HandleSwitcherActiveIndexChanged(TabContentSwitcher->GetChildAt(0), 0);
	}*/

	HandleSwitcherActiveIndexChanged(TabContentSwitcher->GetChildAt(0), 0);

	bTabsInitialized = true;
}
#pragma endregion

#pragma region Tab Navigation
void USFSettingsScreen::HandleSwitcherActiveIndexChanged(UWidget* ContentWidget, int32 Index)
{
	USFCategoryTabBase* categoryTab = Cast<USFCategoryTabBase>(ContentWidget);
	if (IsValid(categoryTab))
	{
		categoryTab->InitializeCategoryDisplay();
	}
}
#pragma endregion

#pragma region Display
void USFSettingsScreen::HandleSettingFocused(const FGameplayTag& SettingTag)
{
	if (IsValid(SettingInfoDisplay))
	{
		SettingInfoDisplay->DisplaySetting(SettingTag);
	}
}
#pragma endregion

#pragma region Setting Actions
void USFSettingsScreen::SaveSettings()
{
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(this);
	if (!IsValid(settingsSubsystem))
	{
		return;
	}
	settingsSubsystem->SaveSettings();
}

void USFSettingsScreen::RevertSettings()
{
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(this);
	if (!IsValid(settingsSubsystem))
	{
		return;
	}
	settingsSubsystem->RevertSettings();
}

void USFSettingsScreen::ResetSettingsToDefault()
{
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(this);
	if (!IsValid(settingsSubsystem))
	{
		return;
	}
	settingsSubsystem->ResetSettingsToDefault();
}
#pragma endregion

#pragma region Navigation
UWidget* USFSettingsScreen::NativeGetDesiredFocusTarget() const
{
	USFCategoryTabBase* activeWidget = IsValid(TabContentSwitcher) ? Cast<USFCategoryTabBase>(TabContentSwitcher->GetActiveWidget()) : nullptr;
	return IsValid(activeWidget) ? activeWidget->GetDesiredFocusTarget() : Super::NativeGetDesiredFocusTarget();
}
#pragma endregion