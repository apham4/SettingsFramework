

# File SFSettingCondition.h

[**File List**](files.md) **>** [**Definitions**](dir_49fd2e6d8d3cd0aca0d770534c763afe.md) **>** [**SFSettingCondition.h**](SFSettingCondition_8h.md)

[Go to the documentation of this file](SFSettingCondition_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFSettingCondition.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class SETTINGSFRAMEWORK_API USFSettingCondition : public UObject
{
    GENERATED_BODY()
    
public:
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingCondition")
    bool IsConditionMet(const UObject* WorldContextObject) const;

    virtual bool IsConditionMet_Implementation(const UObject* WorldContextObject) const { return true; }
};
```


