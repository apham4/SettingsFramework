

# File SFSettingEntryWidget\_Keybind.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**UI**](dir_c0d111a2beff4c46a32685df6daadb0f.md) **>** [**SettingEntries**](dir_ee82e1fcdef3b55cd27efecd9a182f3f.md) **>** [**SFSettingEntryWidget\_Keybind.h**](SFSettingEntryWidget__Keybind_8h.md)

[Go to the documentation of this file](SFSettingEntryWidget__Keybind_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "Core/SFCoreTypes.h"
#include "CommonInputTypeEnum.h"
#include "SFSettingEntryWidget_Keybind.generated.h"

UENUM(BlueprintType)
enum class ESFKeybindSlot : uint8
{
    None,
    KBMPrimary,
    KBMSecondary,
    Gamepad
};

UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Keybind : public USFSettingEntryWidget
{
    GENERATED_BODY()
    
    // TODO: Bind CommonUI actions to Clear and Cancel.
#pragma region Initialization
protected:
    virtual void NativeConstruct() override;
    virtual void NativeOnInitialized() override;
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

    UFUNCTION()
    void HandleInputMethodChanged(ECommonInputType InputType);
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingEntryWidget_Keybind | Keybind Widgets")
    void SetSlotText(ESFKeybindSlot SlotToSet, FKey Key, bool bIsListening);

    virtual void SetSlotText_Implementation(ESFKeybindSlot SlotToSet, FKey Key, bool bIsListening) {};

    void CancelListening();

    void ClearSlot(ESFKeybindSlot SlotToClear);

    UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets", meta = (BindWidget))
    TObjectPtr<class UCommonButtonBase> KBMPrimaryButton;

    UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets", meta = (BindWidget))
    TObjectPtr<class UCommonButtonBase> KBMSecondaryButton;

    UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Keybind|Keybind Widgets", meta = (BindWidget))
    TObjectPtr<class UCommonButtonBase> GamepadButton;

    ESFKeybindSlot CurrentListeningSlot = ESFKeybindSlot::None;
#pragma endregion

#pragma region Navigation
public:
    virtual UWidget* GetPrimaryFocusTarget_Implementation() const;
#pragma endregion

#pragma region Input
protected:
    virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
#pragma endregion
};
```


