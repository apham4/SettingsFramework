// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingEntryWidget_Keybind.generated.h"

/**
 * Enum to track which keybind slot is currently listening for input for rebinding.
 */
UENUM()
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
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Keybind : public USFSettingEntryWidget
{
	GENERATED_BODY()
	
	// TODO: Bind CommonUI actions to Clear and Cancel.
#pragma region Initialization
protected:
	virtual void NativeConstruct() override;
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;
#pragma endregion

#pragma region Setting Value & State
protected:
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

	void ApplyNewKeybind(FKey NewKey);

	UPROPERTY()
	FSFKeybindValueData CurrentKeybindData;
#pragma endregion

#pragma region Keybind Widgets
protected:
	UFUNCTION()
	void HandleKBMPrimaryButtonClicked();

	UFUNCTION()
	void HandleKBMSecondaryButtonClicked();

	UFUNCTION()
	void HandleGamepadButtonClicked();

	void CancelListening();
	void ClearSlot(ESFKeybindSlot SlotToClear);

	void SetSlotText(ESFKeybindSlot SlotToSet, FKey Key, bool bIsListening);

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets|KBM Primary", meta = (BindWidget))
	TObjectPtr<class UCommonButtonBase> KBMPrimaryButton;

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets|KBM Primary", meta = (BindWidget))
	TObjectPtr<class UTextBlock> KBMPrimaryButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets|KBM Secondary", meta = (BindWidget))
	TObjectPtr<class UCommonButtonBase> KBMSecondaryButton;

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets|KBM Secondary", meta = (BindWidget))
	TObjectPtr<class UTextBlock> KBMSecondaryButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets|Gamepad", meta = (BindWidget))
	TObjectPtr<class UCommonButtonBase> GamepadButton;

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets|Gamepad", meta = (BindWidget))
	TObjectPtr<class UTextBlock> GamepadButtonText;

	ESFKeybindSlot CurrentListeningSlot = ESFKeybindSlot::None;
#pragma endregion

#pragma region Input
protected:
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
#pragma endregion
};
