// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "SFSettingDefinition.generated.h"

/**
 * Abstract base class for all setting definitions.
 * Has the basic data such as setting tag, display name, desc, conditions, etc.
 */
UCLASS(Abstract, BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingDefinition : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// Unique tag identifying this setting
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition")
	FGameplayTag SettingTag;

	// User-facing setting name
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Display")
	FText DisplayName;

	// User-facing setting description
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Display", meta = (MultiLine = true))
	FText Description;

	// Should this setting apply on save (true) or apply on change (false).
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	bool bApplyOnSave = false;

	// Conditions that determine whether this setting is visible
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	TArray<TObjectPtr<class USFSettingCondition>> VisibilitySettings;

	// Conditions that determine whether this setting is editable/active
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	TArray<TObjectPtr<class USFSettingCondition>> EditabilitySettings;

	// NOTE_TO_SELF: Instanced = can pick specific subclass in editor

	// Fallback default value.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value")
	TObjectPtr<class USFSettingValue> DefaultValue;
};

/**
 * Setting definition for setting a numeric value (int/float).
 */
UCLASS(DisplayName = "Scalar Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Scalar : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	// Minimum allowed value
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
	float MinValue = 0.0f;

	// Maximum allowed value
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
	float MaxValue = 100.0f;

	// Increment/decrement step size
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
	float StepSize = 1.0f;

	// Use this to enforce discrete steps (e.g. 10, 20, 30) instead of smooth sliding
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
	bool bSnapToStep = true;
};

/**
 * Setting definition for a dropdown/list.
 */
UCLASS(DisplayName = "Discrete Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Discrete : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	// Should the options be generated dynamically at runtime
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Discrete")
	bool bUseDynamicOptions = false;

	// STATIC: Manual list defined in editor (e.g. High/Med/Low)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "!bUseDynamicOptions"))
	TArray<struct FSFSettingOption> StaticOptions;

	// DYNAMIC: Logic class that generates the list (e.g. Resolutions, Monitors)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "bUseDynamicOptions"))
	TSubclassOf<class USFSettingOptionSource> OptionSource;
};

/**
 * Setting definition for a keybind.
 */
UCLASS(DisplayName = "Keybind Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Key : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	// The Input Mapping Context where this key lives
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Keybind")
	TSoftObjectPtr<class UInputMappingContext> MappingContext;

	// The specific Action to rebind (e.g. IA_Jump)
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Keybind")
	TSoftObjectPtr<class UInputAction> InputAction;

	// If an action has multiple bindings (e.g. Primary vs Secondary), 
	// use this index to target the specific slot.
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Keybind")
	int32 MappingIndex = 0;
};