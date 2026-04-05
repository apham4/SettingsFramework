

# File SFSettingOptionSource.h

[**File List**](files.md) **>** [**Definitions**](dir_49fd2e6d8d3cd0aca0d770534c763afe.md) **>** [**SFSettingOptionSource.h**](SFSettingOptionSource_8h.md)

[Go to the documentation of this file](SFSettingOptionSource_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFSettingOptionSource.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class SETTINGSFRAMEWORK_API USFSettingOptionSource : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingOptionSource")
    TArray<struct FSFSettingOption> GetAvailableOptions(const UObject* WorldContextObject) const;
    
    virtual TArray<struct FSFSettingOption> GetAvailableOptions_Implementation(const UObject* WorldContextObject) const { return TArray<struct FSFSettingOption>(); }

    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingOptionSource")
    class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const;

    virtual class USFSettingValue* GetDefaultValue_Implementation(const UObject* WorldContextObject) const { return nullptr; }
};
```


