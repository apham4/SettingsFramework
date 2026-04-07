// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SFSettingsScreen.generated.h"

/**
 * @brief The native base class for the outer-most widget of the settings screen UI. A widget blueprint subclass of this is to be added to a project's CommonUI widget stack.
 *
 * On initialization, this widget queries the USFSettingsSubsystem instance for setting categories and definitions, constructs and populates itself with the appropriate tabs and setting widgets.
 * 
 * The skeletal settings screen UI in Settings Framework only allows for one level of category nesting, meaning only root categories are allowed to be branch-type categories (containing sub-categories).
 * Any branch-type categories under that level are ignored when constructing the UI.
 * 
 * This widget also requests the USFSettingsSubsystem instance to perform actions such as saving, reverting, or resetting settings when initiated by the player from the UI.
 * @note @abstract @blueprinttype @blueprintable
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingsScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
#pragma region Initialization
protected:
	/** @cond */
	virtual void NativeOnInitialized() override;

	// Lazy loading on activated
	virtual void NativeOnActivated() override;
	/** @endcond */

	/**
	* Initializes the settings screen by querying the USFSettingsSubsystem for setting categories and definitions, constructing and populating tabs and setting widgets, and binding to subsystem events.
	* Called on widget activation to allow for lazy loading.
	*/
	UFUNCTION()
	void InitializeSettingsScreen();

	/** @cond */
	bool bTabsInitialized;
	/** @endcond */
#pragma endregion

#pragma region Tab Navigation
protected:
	/**
	* The Common Tab List widget containing tab buttons representing the root setting categories.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonTabListWidgetBase> CategoryTabList;

	/**
	* The Common Activatable Widget Switcher containing the content for each root setting category, switched by the CategoryTabList.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonActivatableWidgetSwitcher> TabContentSwitcher;

protected:
	/** @cond */
	UFUNCTION()
	void HandleSwitcherActiveIndexChanged(UWidget* ContentWidget, int32 Index);
	/** @endcond */
#pragma endregion

#pragma region Display
protected:
	/** @cond */
	UFUNCTION()
	void HandleSettingFocused(const struct FGameplayTag& SettingTag);
	/** @endcond */

	/**
	* The widget displaying detailed information about the currently focused setting, such as its display name, description, etc.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Display", meta = (BindWidget))
	TObjectPtr<class USFSettingInfoDisplay> SettingInfoDisplay;
#pragma endregion

#pragma region Setting Actions
protected:
	/**
	* Requests the USFSettingsSubsystem to save all setting values. Can be called manually or bound to SaveAction.
	* @note @bp
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
	void SaveSettings();

	/**
	* Requests the USFSettingsSubsystem to revert all setting values to their saved values. Can be called manually or bound to RevertAction.
	* @note @bp
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
	void RevertSettings();

	/**
	* Requests the USFSettingsSubsystem to reset all setting values to their default values. Can be called manually or bound to ResetToDefaultAction.
	* @note @bp
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
	void ResetSettingsToDefault();
#pragma endregion

#pragma region CommonUI Navigation
protected:
	/** @cond */
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
	/** @endcond */
#pragma endregion

#pragma region Input Action
protected:
	/**
	* The optional EnhancedInput action to automatically call SaveSettings. Requires Enhanced Input support to be enabled in Common Input settings.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsScreen|Input Action")
	TObjectPtr<class UInputAction> SaveAction;

	/**
	* The optional EnhancedInput action to automatically call RevertSettings. Requires Enhanced Input support to be enabled in Common Input settings.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsScreen|Input Action")
	TObjectPtr<class UInputAction> RevertAction;

	/**
	* The optional EnhancedInput action to automatically call ResetSettingsToDefault. Requires Enhanced Input support to be enabled in Common Input settings.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsScreen|Input Action")
	TObjectPtr<class UInputAction> ResetToDefaultAction;
#pragma endregion
};
