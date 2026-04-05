// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFSettingCondition.generated.h"

/**
 * @brief Base class for evaluating conditions determining a setting's state.
 *
 * Base class for evaluating conditions determining a setting's state.
 * The setting Data Asset has a list of VisibilityConditions, and a list of EditabilityConditions, which will be used to evaluate its specific active/disabled/hidden state.
 * @note @abstract @blueprintable @editinlinenew @defaulttoinstanced
 */
UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class SETTINGSFRAMEWORK_API USFSettingCondition : public UObject
{
	GENERATED_BODY()
	
public:
	/**
	* Evaluate the condition.
	* @param WorldContextObject The world context object from which to get the world object.
	* @return true if the condition is met, false otherwise.
	* @note @bne
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "SFSettingCondition")
	bool IsConditionMet(const UObject* WorldContextObject) const;

	/**
	* Native implementation of IsConditionMet.
	*/
	virtual bool IsConditionMet_Implementation(const UObject* WorldContextObject) const { return true; }
};
