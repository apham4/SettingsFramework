

# File SFSettingEntryWidget\_Slider.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**UI**](dir_c0d111a2beff4c46a32685df6daadb0f.md) **>** [**SettingEntries**](dir_ee82e1fcdef3b55cd27efecd9a182f3f.md) **>** [**SFSettingEntryWidget\_Slider.h**](SFSettingEntryWidget__Slider_8h.md)

[Go to the documentation of this file](SFSettingEntryWidget__Slider_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Slider.generated.h"

UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Slider : public USFSettingEntryWidget
{
    GENERATED_BODY()

protected:
    virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;

    virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

    UFUNCTION()
    void HandleSliderValueChanged(float NewValue);
    UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Slider", meta = (BindWidget))
    TObjectPtr<class UAnalogSlider> SliderWidget;
};
```


