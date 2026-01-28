// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SFCoreTypes.generated.h"

/**
 * Represents a single selectable option in a list (e.g. "High", "1920x1080"). 
 * Used for configuration and not runtime instance, specialized for GameplayTags to ensure struct data usage.
 */
USTRUCT(BlueprintType)
struct FSFSettingOption
{
    GENERATED_BODY()

    // The text displayed to the player
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingOption")
    FText DisplayName;

    // The tag associated with this option
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingOption")
    FGameplayTag Value;
};