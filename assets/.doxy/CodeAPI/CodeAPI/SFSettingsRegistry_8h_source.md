

# File SFSettingsRegistry.h

[**File List**](files.md) **>** [**Definitions**](dir_49fd2e6d8d3cd0aca0d770534c763afe.md) **>** [**SFSettingsRegistry.h**](SFSettingsRegistry_8h.md)

[Go to the documentation of this file](SFSettingsRegistry_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SFSettingsRegistry.generated.h"

UCLASS()
class SETTINGSFRAMEWORK_API USFSettingsRegistry : public UDataAsset
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsRegistry")
    TArray<TObjectPtr<class USFSettingCategory>> RootCategories;
};
```


