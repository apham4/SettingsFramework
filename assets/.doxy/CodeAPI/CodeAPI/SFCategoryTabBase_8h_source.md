

# File SFCategoryTabBase.h

[**File List**](files.md) **>** [**Components**](dir_d359c2365a038846f780cd493464dc51.md) **>** [**SFCategoryTabBase.h**](SFCategoryTabBase_8h.md)

[Go to the documentation of this file](SFCategoryTabBase_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Core/SFCoreTypes.h"
#include "SFCategoryTabBase.generated.h"

UCLASS(Abstract, BlueprintType)
class SETTINGSFRAMEWORK_API USFCategoryTabBase : public UCommonActivatableWidget
{
    GENERATED_BODY()

#pragma region Initialization
public:
    void SetCategory(class USFSettingCategory* InSettingCategory);

    virtual void InitializeCategoryDisplay() {};
#pragma endregion

#pragma region Setting Category Data
public:
    UFUNCTION(BlueprintPure, Category = "SFCategoryTabBase|Setting Category Data")
    const class USFSettingCategory* GetSettingCategory() const { return SettingCategory; }

    UPROPERTY(BlueprintAssignable, Category = "SFCategoryTabBase")
    FOnSettingEntryFocused OnSettingFocused;

protected:
    UPROPERTY(Transient)
    TObjectPtr<class USFSettingCategory> SettingCategory;
#pragma endregion
};
```


