// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFSettingOptionSource.generated.h"

/**
 * Base class for providing a dynamic runtime list of options for a setting.
 */
UCLASS(Abstract, Blueprintable, EditInlineNew)
class SETTINGSFRAMEWORK_API USFSettingOptionSource : public UObject
{
    GENERATED_BODY()

public:
    // NOTE_TO_SELF: Pass in World/GameInstance/PlayerController for Context
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingOptionSource")
    TArray<struct FSFSettingOption> GetAvailableOptions(const UObject* WorldContextObject) const;
    virtual TArray<struct FSFSettingOption> GetAvailableOptions_Implementation(const UObject* WorldContextObject) const { return TArray<struct FSFSettingOption>(); }

    // Optional: Calculate a dynamic default (e.g. "Best Resolution")
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingOptionSource")
    struct FGameplayTag GetDefaultValue(const UObject* WorldContextObject) const;
    virtual struct FGameplayTag GetDefaultValue_Implementation(const UObject* WorldContextObject) const { return FGameplayTag::EmptyTag; }
};
