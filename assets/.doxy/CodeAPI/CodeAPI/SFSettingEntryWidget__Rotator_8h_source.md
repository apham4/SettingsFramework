

# File SFSettingEntryWidget\_Rotator.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**UI**](dir_c0d111a2beff4c46a32685df6daadb0f.md) **>** [**SettingEntries**](dir_ee82e1fcdef3b55cd27efecd9a182f3f.md) **>** [**SFSettingEntryWidget\_Rotator.h**](SFSettingEntryWidget__Rotator_8h.md)

[Go to the documentation of this file](SFSettingEntryWidget__Rotator_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Rotator.generated.h"

UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Rotator : public USFSettingEntryWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "SFSettingEntryWidget_Rotator")
    void RefreshOptions();

protected:
    virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;

    virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

    UFUNCTION()
    void HandleRotatorRotated(int32 NewValue, enum ERotatorDirection RotatorDirection);
    UFUNCTION()
    void CheckForDeterminantSettings(const FGameplayTag& ChangedSettingTag, class USFSettingValue* NewValue);

    UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Rotator", meta = (BindWidget))
    TObjectPtr<class UCommonRotator> RotatorWidget;

    UPROPERTY(Transient)
    TArray<struct FSFSettingOption> Options;

#pragma region Helpers
protected:
    void PopulateOptions(const TArray<struct FSFSettingOption>& SettingOptions);

    bool SelectOptionByValue(const class USFSettingValue* Value);
#pragma endregion
};
```


