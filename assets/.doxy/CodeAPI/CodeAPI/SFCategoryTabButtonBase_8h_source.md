

# File SFCategoryTabButtonBase.h

[**File List**](files.md) **>** [**Components**](dir_d359c2365a038846f780cd493464dc51.md) **>** [**SFCategoryTabButtonBase.h**](SFCategoryTabButtonBase_8h.md)

[Go to the documentation of this file](SFCategoryTabButtonBase_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "SFCategoryTabButtonBase.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTabButtonBase : public UCommonButtonBase
{
    GENERATED_BODY()
    
public:
    UFUNCTION(BlueprintNativeEvent, Category = "SFCategoryTabButtonBase")
    void SetCategoryData(const class USFSettingCategory* InCategory);

    virtual void SetCategoryData_Implementation(const class USFSettingCategory* InCategory) {};
};
```


