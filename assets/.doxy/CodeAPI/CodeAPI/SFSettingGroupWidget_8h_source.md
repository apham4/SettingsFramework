

# File SFSettingGroupWidget.h

[**File List**](files.md) **>** [**Components**](dir_d359c2365a038846f780cd493464dc51.md) **>** [**SFSettingGroupWidget.h**](SFSettingGroupWidget_8h.md)

[Go to the documentation of this file](SFSettingGroupWidget_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SFSettingGroupWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingGroupWidget : public UCommonUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingGroup")
    void DisplaySettingGroupInfo(const struct FSFSettingGroup& SettingGroup);

    void AddSettingEntry(class USFSettingEntryWidget* EntryWidget);

    class USFSettingEntryWidget* GetFirstValidSettingEntry() const;
    
protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingGroup")
    void OnSettingEntryAdded(class UPanelSlot* EntryAsPanelSlot, class USFSettingEntryWidget* EntryAsSettingWidget);

    UPROPERTY(BlueprintReadOnly, Category = "SFSettingGroup", meta = (BindWidget))
    TObjectPtr<class UPanelWidget> SettingEntryContainer;
};
```


