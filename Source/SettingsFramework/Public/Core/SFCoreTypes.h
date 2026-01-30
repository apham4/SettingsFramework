// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SFCoreTypes.generated.h"

/**
 * Represents a single selectable option in a list (e.g. "High", "1920x1080", "Monitor 1"). 
 */
USTRUCT(BlueprintType)
struct FSFSettingOption
{
    GENERATED_BODY()

    // The text displayed to the player
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingOption")
    FText DisplayName;

	// The value associated with this option, can be of any type
    // Instanced allows inline editing in Data Asset
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "SFSettingOption")
	TObjectPtr<class USFSettingValue> Value;
};