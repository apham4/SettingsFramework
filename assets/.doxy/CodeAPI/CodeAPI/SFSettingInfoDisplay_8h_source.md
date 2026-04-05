

# File SFSettingInfoDisplay.h

[**File List**](files.md) **>** [**Components**](dir_d359c2365a038846f780cd493464dc51.md) **>** [**SFSettingInfoDisplay.h**](SFSettingInfoDisplay_8h.md)

[Go to the documentation of this file](SFSettingInfoDisplay_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SFSettingInfoDisplay.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingInfoDisplay : public UCommonUserWidget
{
    GENERATED_BODY()

public:
    void DisplaySetting(const struct FGameplayTag& SettingTag);
    
protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingInfoDisplay")
    void DisplaySettingByDefinition(const class USFSettingDefinition* SettingDefinition);
};
```


