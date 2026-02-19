// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SFSettingsScreen.generated.h"

/**
 * The main entry point for the settings UI. Populates based on the data loaded in SFSettingsSubsystem.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingsScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
#pragma region Initialization
protected:
	// Lazy loading on activated
	virtual void NativeOnActivated() override;

	void InitializeSettingsScreen();

	bool bTabsInitialized;
#pragma endregion

#pragma region Tab Navigation
protected:
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonTabListWidgetBase> CategoryTabList;

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonAnimatedSwitcher> TabContentSwitcher;
#pragma endregion

#pragma region Display
protected:
	UFUNCTION()
	void HandleSettingFocused(const struct FGameplayTag& SettingTag);

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Display", meta = (BindWidget))
	TObjectPtr<class USFSettingInfoDisplay> SettingInfoDisplay;
#pragma endregion

#pragma region Setting Actions
protected:
	UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
	void SaveSettings();

	UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
	void RevertSettings();

	UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
	void ResetSettingsToDefault();
#pragma endregion

#pragma region CommonUI Navigation
protected:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
#pragma endregion
};
