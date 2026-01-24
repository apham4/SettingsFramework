// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFSettingCondition.generated.h"

/**
 * Base class for evaluating conditions determining a setting's state.
 * The setting data asset has a list of Visibility Conditions, and a list of Editability Conditions, which will be used to evaluate its specific active/disabled/hidden state.
 */
UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class SETTINGSFRAMEWORK_API USFSettingCondition : public UObject
{
	GENERATED_BODY()
	
public:
	// NOTE_TO_SELF: Pass in World/GameInstance/PlayerController for Context. Call GetWorld() on it.
	UFUNCTION(BlueprintNativeEvent, Category = "SFSettingCondition")
	bool IsConditionMet(const UObject* WorldContextObject) const;
	virtual bool IsConditionMet_Implementation(const UObject* WorldContextObject) const { return true; }
};
