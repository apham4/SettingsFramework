// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Core/SFSettingValue.h"
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

	// Conditions that determine whether this setting is visible
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	TArray<TObjectPtr<class USFSettingCondition>> VisibilityConditions;

	// Conditions that determine whether this setting is editable/active
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	TArray<TObjectPtr<class USFSettingCondition>> EditabilityConditions;

	// NOTE_TO_SELF: Instanced = can pick specific subclass in editor

public:
	// Returns the class type of the value this setting uses.
	virtual TSubclassOf<USFSettingValue> GetValueClass() const { PURE_VIRTUAL(USFSettingDefinition::GetValueClass, return nullptr;); }

	// Returns the default value for this setting.
	UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
	virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const { return DefaultValue; };

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

public:
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Scalar::StaticClass();
	}
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

public:
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Tag::StaticClass();
	}

	virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const override;

	UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
	TArray<struct FSFSettingOption> GetSettingOptions(const UObject* WorldContextObject) const;

protected:
	virtual void PostLoad() override;

	UPROPERTY(Transient)
	TObjectPtr<class USFSettingOptionSource> CachedSettingOptionSource;
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

public:
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Key::StaticClass();
	}
};