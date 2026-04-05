// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingEntryWidget_Keybind.generated.h"

/**
 * Enum to track which keybind slot is currently listening for input for rebinding.
 */
UENUM(BlueprintType)
enum class ESFKeybindSlot : uint8
{
	None,
	KBMPrimary,
	KBMSecondary,
	Gamepad
};

/**
 * Setting entry widget for keybind settings, represented as buttons that listens for the next key press in the UI.
 */

/**
 * @brief The native base class for a setting entry widget for a key bind setting, represented as buttons that listen for the next key press in the UI.
 *
 * The native base class for a setting entry widget for a key bind setting, represented as buttons that listen for the next key press in the UI.
 * 
 * The widget blueprint implementing this class should be assigned as a value to the SettingEntryWidgetClasses map with the key bind setting definition class (USFSettingDefinition_Key) as the key in the Developer Settings at Project Settings > Plugins > SettingsFramework.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Keybind : public USFSettingEntryWidget
{
	GENERATED_BODY()
	
	// TODO: Bind CommonUI actions to Clear and Cancel.
#pragma region Initialization
protected:
	/** @cond */
	virtual void NativeConstruct() override;
	/** @endcond */

	/**
	* @inheritdoc
	*/
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;
#pragma endregion

#pragma region Setting Value & State
protected:
	/**
	* @inheritdoc
	*/
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

	/**
	* Apply the given key as the new keybind for the currently listening slot (specified by CurrentListeningSlot) and update it in the USFSettingsSubsystem instance.
	* @param NewKey The new keybind to apply for the currently listening slot.
	*/
	void ApplyNewKeybind(FKey NewKey);

	/**
	* The cached current keybind data for this setting entry, used to compare against new input and determine whether the value has actually changed and whether to apply the change to the subsystem.
	*/
	UPROPERTY()
	FSFKeybindValueData CurrentKeybindData;
#pragma endregion

#pragma region Keybind Widgets
protected:
	/** @cond */
	UFUNCTION()
	void HandleKBMPrimaryButtonClicked();

	UFUNCTION()
	void HandleKBMSecondaryButtonClicked();

	UFUNCTION()
	void HandleGamepadButtonClicked();
	/** @endcond */

	/**
	* Cosmetically display the given key in the button widget for the specified slot, and update the display to indicate that the widget is currently listening for input if bIsListening is true.
	* @param SlotToSet The keybind slot for which to set the button text.
	* @param Key The key to display in the button widget for the specified slot.
	* @param bIsListening Whether the button widget for the specified slot should display as currently listening for input.
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "SFSettingEntryWidget_Keybind | Keybind Widgets")
	void SetSlotText(ESFKeybindSlot SlotToSet, FKey Key, bool bIsListening);

	/**
	* Native implementation of SetSlotText, can be optionally overridden by C++ subclasses.
	*/
	virtual void SetSlotText_Implementation(ESFKeybindSlot SlotToSet, FKey Key, bool bIsListening) {};

	/**
	* If the widget is in listening state, cancel it and update the button display to show the current keybind.
	*/
	void CancelListening();

	/**
	* Set the specified slot to have no keybind, update it in the USFSettingsSubsystem instance, and update the button display accordingly.
	* @param SlotToClear The keybind slot to clear the keybind for.
	*/
	void ClearSlot(ESFKeybindSlot SlotToClear);

	/**
	* Button widget for displaying and changing the primary KBM keybind.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets", meta = (BindWidget))
	TObjectPtr<class UCommonButtonBase> KBMPrimaryButton;

	/**
	* Button widget for displaying and changing the secondary KBM keybind.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets", meta = (BindWidget))
	TObjectPtr<class UCommonButtonBase> KBMSecondaryButton;

	/**
	* Button widget for displaying and changing the gamepad keybind.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets", meta = (BindWidget))
	TObjectPtr<class UCommonButtonBase> GamepadButton;

	/**
	* Transient variable to track which keybind slot is currently listening for input for rebinding.
	*/
	ESFKeybindSlot CurrentListeningSlot = ESFKeybindSlot::None;
#pragma endregion

#pragma region Input
protected:
	/** @cond */
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	/** @endcond */
#pragma endregion
};
