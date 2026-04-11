

# File SFFunctionLibrary.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**SFFunctionLibrary.h**](SFFunctionLibrary_8h.md)

[Go to the documentation of this file](SFFunctionLibrary_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonInputTypeEnum.h"
#include "SFFunctionLibrary.generated.h"

UCLASS()
class SETTINGSFRAMEWORK_API USFFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "SFFunctionLibrary", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext))
    static class USFSettingsSubsystem* GetSettingsSubsystem(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Input|CommonUI", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext))
    static ECommonInputType GetCurrentInputMethod(const UObject* WorldContextObject);
};
```


