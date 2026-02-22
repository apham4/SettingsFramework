// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/SettingEntries/SFSettingEntryWidget_Keybind.h"
#include "Core/SFSettingValue.h"
#include "Definitions/SFSettingDefinition.h"
#include "CommonButtonBase.h"
#include "Components/TextBlock.h"
#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"
#include "SFSettingsDeveloperSettings.h"

#pragma region Initialization
void USFSettingEntryWidget_Keybind::NativeConstruct()
{
	Super::NativeConstruct();
	bIsFocusable = true;
}

void USFSettingEntryWidget_Keybind::InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition)
{
	Super::InitializeSettingEntry(InSettingDefinition);

	if (IsValid(KBMPrimaryButton))
	{
		KBMPrimaryButton->OnClicked().AddUObject(this, &USFSettingEntryWidget_Keybind::HandleKBMPrimaryButtonClicked);
	}
	if (IsValid(KBMSecondaryButton))
	{
		KBMSecondaryButton->OnClicked().AddUObject(this, &USFSettingEntryWidget_Keybind::HandleKBMSecondaryButtonClicked);
	}
	if (IsValid(GamepadButton))
	{
		GamepadButton->OnClicked().AddUObject(this, &USFSettingEntryWidget_Keybind::HandleGamepadButtonClicked);
	}
}
#pragma endregion

#pragma region Setting Value & State
void USFSettingEntryWidget_Keybind::UpdateVisualValue_Implementation(const USFSettingValue* NewValue)
{
	const USFSettingValue_Key* keyValue = Cast<USFSettingValue_Key>(NewValue);
	if (!IsValid(keyValue) || keyValue->Value == CurrentKeybindData)
	{
		return;
	}
	CurrentKeybindData = keyValue->Value;
	SetSlotText(ESFKeybindSlot::KBMPrimary, CurrentKeybindData.KBMPrimary, false);
	SetSlotText(ESFKeybindSlot::KBMSecondary, CurrentKeybindData.KBMSecondary, false);
	SetSlotText(ESFKeybindSlot::Gamepad, CurrentKeybindData.Gamepad, false);
}

void USFSettingEntryWidget_Keybind::ApplyNewKeybind(FKey NewKey)
{
	USFSettingsSubsystem* settingsSubsystem = USFFunctionLibrary::GetSettingsSubsystem(this);
	if (!IsValid(settingsSubsystem) || (NewKey.IsGamepadKey() != (CurrentListeningSlot == ESFKeybindSlot::Gamepad)))
	{
		return;
	}

	FSFKeybindValueData newData = CurrentKeybindData;
	switch (CurrentListeningSlot)
	{
		case ESFKeybindSlot::KBMPrimary:
			newData.KBMPrimary = NewKey;
			break;
		case ESFKeybindSlot::KBMSecondary:
			newData.KBMSecondary = NewKey;
			break;
		case ESFKeybindSlot::Gamepad:
			newData.Gamepad = NewKey;
			break;
		default:
			break;
	}

	if (IsValid(KBMPrimaryButton))
	{
		KBMPrimaryButton->SetIsSelected(false);
	}
	if (IsValid(KBMSecondaryButton))
	{
		KBMSecondaryButton->SetIsSelected(false);
	}
	if (IsValid(GamepadButton))
	{
		GamepadButton->SetIsSelected(false);
	}

	// Reshow cursor if it was hidden
	CurrentListeningSlot = ESFKeybindSlot::None;

	// Update via SFSettingsSubsystem::UpdateKeybinding instead of using USFSettingEntryWidget::OnUserChangedValue for collision detection
	const USFSettingsDeveloperSettings* devSettings = GetDefault<USFSettingsDeveloperSettings>();
	ESFKeybindCollisionResolution collisionResolution = IsValid(devSettings) ? devSettings->DefaultKeybindCollisionResolution : ESFKeybindCollisionResolution::Overwrite;
	settingsSubsystem->UpdateKeybinding(SettingTag, newData, collisionResolution);
}
#pragma endregion

#pragma region Keybind Widgets
void USFSettingEntryWidget_Keybind::HandleKBMPrimaryButtonClicked()
{
	// May need to hide cursor
	CurrentListeningSlot = ESFKeybindSlot::KBMPrimary;
	SetSlotText(CurrentListeningSlot, FKey(), true);
	SetFocus();
	if (IsValid(KBMPrimaryButton))
	{
		KBMPrimaryButton->SetIsSelected(true);
	}
}

void USFSettingEntryWidget_Keybind::HandleKBMSecondaryButtonClicked()
{
	// May need to hide cursor
	CurrentListeningSlot = ESFKeybindSlot::KBMSecondary;
	SetSlotText(CurrentListeningSlot, FKey(), true);
	SetFocus();
	if (IsValid(KBMSecondaryButton))
	{
		KBMSecondaryButton->SetIsSelected(true);
	}
}

void USFSettingEntryWidget_Keybind::HandleGamepadButtonClicked()
{
	// May need to hide cursor
	CurrentListeningSlot = ESFKeybindSlot::Gamepad;
	SetSlotText(CurrentListeningSlot, FKey(), true);
	SetFocus();
	if (IsValid(GamepadButton))
	{
		GamepadButton->SetIsSelected(true);
	}
}

void USFSettingEntryWidget_Keybind::CancelListening()
{
	// NOTE_TO_SELF: currently not called
	CurrentListeningSlot = ESFKeybindSlot::None;
	SetSlotText(ESFKeybindSlot::KBMPrimary, CurrentKeybindData.KBMPrimary, false);
	SetSlotText(ESFKeybindSlot::KBMSecondary, CurrentKeybindData.KBMSecondary, false);
	SetSlotText(ESFKeybindSlot::Gamepad, CurrentKeybindData.Gamepad, false);
}

void USFSettingEntryWidget_Keybind::ClearSlot(ESFKeybindSlot SlotToClear)
{
	// NOTE_TO_SELF: currently not called
	CurrentListeningSlot = SlotToClear;
	ApplyNewKeybind(FKey());
}

void USFSettingEntryWidget_Keybind::SetSlotText(ESFKeybindSlot SlotToSet, FKey Key, bool bIsListening)
{
	UTextBlock* textBlock = nullptr;
	switch (SlotToSet)
	{
		case ESFKeybindSlot::KBMPrimary:
			textBlock = KBMPrimaryButtonText;
			break;
		case ESFKeybindSlot::KBMSecondary:
			textBlock = KBMSecondaryButtonText;
			break;
		case ESFKeybindSlot::Gamepad:
			textBlock = GamepadButtonText;
			break;
		default:
			break;
	}
	if (!IsValid(textBlock))
	{
		return;
	}
	if (bIsListening)
	{
		textBlock->SetText(FText::FromString(TEXT("Press any Key...")));
	}
	else
	{
		textBlock->SetText(Key.IsValid() ? Key.GetDisplayName() : FText::FromString(TEXT("Unbound")));
	}
}
#pragma endregion

#pragma region Input
FReply USFSettingEntryWidget_Keybind::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (CurrentListeningSlot == ESFKeybindSlot::None)
	{
		return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
	}
	ApplyNewKeybind(InKeyEvent.GetKey());
	return FReply::Handled();
}

FReply USFSettingEntryWidget_Keybind::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (CurrentListeningSlot == ESFKeybindSlot::None)
	{
		return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	}
	ApplyNewKeybind(InMouseEvent.GetEffectingButton());
	return FReply::Handled();
}

FReply USFSettingEntryWidget_Keybind::NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (CurrentListeningSlot == ESFKeybindSlot::None)
	{
		return Super::NativeOnMouseWheel(InGeometry, InMouseEvent);
	}
	FKey wheelKey = InMouseEvent.GetWheelDelta() > 0 ? EKeys::MouseScrollUp : EKeys::MouseScrollDown;
	ApplyNewKeybind(wheelKey);
	return FReply::Handled();
}
#pragma endregion