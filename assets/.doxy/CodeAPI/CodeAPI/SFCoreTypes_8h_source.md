

# File SFCoreTypes.h

[**File List**](files.md) **>** [**Core**](dir_39651220af2aa02d3a35c23742da36c9.md) **>** [**SFCoreTypes.h**](SFCoreTypes_8h.md)

[Go to the documentation of this file](SFCoreTypes_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/InputChord.h"
#include "InputCoreTypes.h"
#include "SFCoreTypes.generated.h"

#pragma region Backend
USTRUCT(BlueprintType)
struct FSFSettingOption
{
    GENERATED_BODY()

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingOption")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "SFSettingOption")
    TObjectPtr<class USFSettingValue> Value;
};

USTRUCT(BlueprintType)
struct FSFKeybindValueData
{
    GENERATED_BODY()

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFKeybindValueData")
    FKey KBMPrimary;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFKeybindValueData")
    FKey KBMSecondary;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFKeybindValueData")
    FKey Gamepad;

    bool operator==(const FSFKeybindValueData& Other) const
    {
        return KBMPrimary == Other.KBMPrimary
            && KBMSecondary == Other.KBMSecondary
            && Gamepad == Other.Gamepad;
    }
};

UENUM(BlueprintType)
enum class ESFKeybindCollisionResolution : uint8
{
    // If collision found, allow the new binding to be added alongside the existing one, even if they are the same action or same input.
    AllowDuplicate      UMETA(DisplayName = "Allow Duplicate Bindings"),
    // If collision found, allow the new binding but remove the existing one(s) that conflict with it.
    Overwrite           UMETA(DisplayName = "Overwrite Existing Binding"),
    // If collision found, allow the new binding but also change the conflicting existing binding to the new binding's old value.
    Swap                UMETA(DisplayName = "Swap Bindings"),
};
#pragma endregion

#pragma region UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSettingEntryFocused, const struct FGameplayTag&, SettingTag);
#pragma endregion
```


