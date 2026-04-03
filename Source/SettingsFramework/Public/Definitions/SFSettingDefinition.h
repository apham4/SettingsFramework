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

public:
	// Returns the class type of the value this setting uses.
	virtual TSubclassOf<USFSettingValue> GetValueClass() const { PURE_VIRTUAL(USFSettingDefinition::GetValueClass, return nullptr;); }

	// Returns the default value for this setting.
	UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
	virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const { return DefaultValue; };

protected:
	// Fallback default value.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value")
	TObjectPtr<class USFSettingValue> DefaultValue;
};

/**
 * Setting definition for setting a numeric value (int/float).
 */
UCLASS(DisplayName = "SF Scalar Setting")
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

public:
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Scalar::StaticClass();
	}
};

/**
 * Setting definition for setting a binary value (true/false).
 */
UCLASS(DisplayName = "SF Bool Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Bool : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Bool::StaticClass();
	}
};

/**
 * Setting definition for a dropdown/list.
 */
UCLASS(DisplayName = "SF Discrete Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Discrete : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	// The underlying value type for the options in this setting
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Discrete")
	TSubclassOf<USFSettingValue> ValueWrapperClass;

	// Should the options be generated dynamically at runtime
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Discrete")
	bool bUseDynamicOptions = false;

	// STATIC: Manual list defined in editor (e.g. High/Med/Low)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "!bUseDynamicOptions"))
	TArray<struct FSFSettingOption> StaticOptions;

	// DYNAMIC: Logic class that generates the list (e.g. Resolutions, Monitors)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "bUseDynamicOptions"))
	TSubclassOf<class USFSettingOptionSource> OptionSource;

	// DYNAMIC: List of settings that this setting should listen to to refresh its dynamic options. If the condition to refresh is something else, use SFSettingEntryWidget_Rotator::RefreshOptions with custom logic.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "bUseDynamicOptions"))
	FGameplayTagContainer DeterminantSettingTags;

public:
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override;

	virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const override;

	UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
	TArray<struct FSFSettingOption> GetSettingOptions(const UObject* WorldContextObject) const;
};

/**
 * Setting definition for a keybind.
 */
UCLASS(DisplayName = "SF Keybind Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Key : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	// Identifiers for the Player Mappable Key Options (in IMC)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
	FName KBMPrimaryName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
	FName KBMSecondaryName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
	FName GamepadName;

	// Only settings sharing a channel will trigger collision warnings (e.g. Global, Combat, etc.)
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Behavior")
	FGameplayTagContainer CollisionChannels;

public:
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Key::StaticClass();
	}
};