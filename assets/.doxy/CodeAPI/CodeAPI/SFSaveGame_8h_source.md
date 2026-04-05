

# File SFSaveGame.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**SaveGame**](dir_2040f41784c4464894ecea1e6ef2879a.md) **>** [**SFSaveGame.h**](SFSaveGame_8h.md)

[Go to the documentation of this file](SFSaveGame_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "SFSaveGame.generated.h"

UCLASS()
class SETTINGSFRAMEWORK_API USFSaveGame : public USaveGame
{
    GENERATED_BODY()
    
public:
    UPROPERTY(VisibleAnywhere, Category = "SFSaveGame")
    TMap<FGameplayTag, FString> SerializedSettings;
};
```


