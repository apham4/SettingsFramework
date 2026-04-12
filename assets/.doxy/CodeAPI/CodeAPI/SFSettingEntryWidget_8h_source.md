

# File SFSettingEntryWidget.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**UI**](dir_c0d111a2beff4c46a32685df6daadb0f.md) **>** [**SettingEntries**](dir_ee82e1fcdef3b55cd27efecd9a182f3f.md) **>** [**SFSettingEntryWidget.h**](SFSettingEntryWidget_8h.md)

[Go to the documentation of this file](SFSettingEntryWidget_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingEntryWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingEntryWidget : public UCommonUserWidget
{
    GENERATED_BODY()

#pragma region Initialization
public:
    virtual void NativeConstruct() override;
    virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);
    
protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingEntryWidget|Initialization", meta = (DisplayName = "Initialize Setting Entry"))
    void BP_InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);

    UFUNCTION()
    void HandleOnSettingValueChanged(const FGameplayTag& ChangedSettingTag, class USFSettingValue* NewValue);
#pragma endregion

#pragma region Widgets
protected:
    UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget|Widgets", meta = (BindWidgetOptional))
    TObjectPtr<class UCommonTextBlock> SettingLabel;
#pragma endregion

#pragma region Setting Data
public:
    UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget|Setting Data")
    FGameplayTag GetSettingTag() const { return SettingTag; }

    UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget|Setting Data")
    class USFSettingDefinition* GetSettingDefinition() const;

    UPROPERTY(BlueprintAssignable, Category = "SFSettingEntryWidget|Setting Data")
    FOnSettingEntryFocused OnSettingFocused;

protected:
    UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget|Setting Data")
    FGameplayTag SettingTag;
#pragma endregion

#pragma region Setting Value & State
protected:
    UFUNCTION(BlueprintCallable, Category = "SFSettingEntryWidget|Setting Value & State")
    void OnUserChangedValue(class USFSettingValue* NewValue);

    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingEntryWidget|Setting Value & State")
    void UpdateVisualValue(const class USFSettingValue* NewValue);

    virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) {};

    void UpdateWidgetState();
#pragma endregion

#pragma region Navigation
public:
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingEntryWidget|Navigation")
    UWidget* GetPrimaryFocusTarget() const;
    virtual UWidget* GetPrimaryFocusTarget_Implementation() const;

protected:
    virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
    virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
#pragma endregion
};
```


