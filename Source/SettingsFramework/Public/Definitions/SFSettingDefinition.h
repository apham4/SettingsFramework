// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Core/SFSettingValue.h"
#include "SFSettingDefinition.generated.h"

/**
 * @brief Abstract base class for all setting definitions.
 *
 * Abstract base class for all setting definitions.
 * Has the basic metadata such as setting Gameplay Tag, display name, description, conditions, etc.
 * @note @abstract @blueprinttype
 */
UCLASS(Abstract, BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingDefinition : public UDataAsset
{
	GENERATED_BODY()
	
public:
	/**
	* The setting's unique identifier. Used for listening to value changes from this setting.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition")
	FGameplayTag SettingTag;

	/**
	* The setting's player-facing name, displayed on UI.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Display")
	FText DisplayName;

	/**
	* The setting's player-facing description, displayed on UI.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Display", meta = (MultiLine = true))
	FText Description;

	/**
	* The collection of condition evaluators that determine whether this setting is visible. 
	* If any condition in the array is not met, the setting will be hidden.
	* The check is triggered on any setting value change.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	TArray<TObjectPtr<class USFSettingCondition>> VisibilityConditions;

	/**
	* The collection of condition evaluators that determine whether this setting is editable/active.
	* If any condition in the array is not met, the setting will be disabled but still visible.
	* The check is triggered on any setting value change.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	TArray<TObjectPtr<class USFSettingCondition>> EditabilityConditions;

	/**
	* Should this setting be reverted to its default value if its VisibilityConditions or EditabilityConditions are not met.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
	bool bRevertToDefaultOnDisable = false;

public:
	/**
	* Get the USFSettingValue-derived class of the value this setting uses.
	* @return The USFSettingValue-derived class of the value this setting uses.
	*/
	virtual TSubclassOf<USFSettingValue> GetValueClass() const { PURE_VIRTUAL(USFSettingDefinition::GetValueClass, return nullptr;); }

	/**
	* Get the default value for this setting.
	* @param WorldContextObject The world context object from which to get the world object.
	* @return The default value for this setting.
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
	virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const { return DefaultValue; };

protected:
	/**
	* The static default value for this setting. This is returned by GetDefaultValue() if it is not overridden by the subclass.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value")
	TObjectPtr<class USFSettingValue> DefaultValue;
};

/**
 * @brief Setting definition for setting a numeric value (int/float).
 *
 * Setting definition for setting a numeric value (int/float).
 * 
 * Blueprint display name: SF Scalar Setting.
 */
UCLASS(DisplayName = "SF Scalar Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Scalar : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	/**
	* Minimum allowed value.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
	float MinValue = 0.0f;

	/**
	* Maximum allowed value.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
	float MaxValue = 100.0f;

	/**
	* The step size at which the value can be increased/decreased.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
	float StepSize = 1.0f;

public:
	/**
	* @inheritdoc
	*/
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Scalar::StaticClass();
	}
};

/**
 * @brief Setting definition for setting a boolean value.
 *
 * Setting definition for setting a boolean value.
 * 
 * Blueprint display name: SF Bool Setting.
 */
UCLASS(DisplayName = "SF Bool Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Bool : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	/**
	* @inheritdoc
	*/
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Bool::StaticClass();
	}
};

/**
 * @brief Setting definition for setting an option among a list.
 *
 * Setting definition for setting an option among a list. This is usually used for a dropdown or a rotator.
 * 
 * Blueprint display name: SF Discrete Setting.
 */
UCLASS(DisplayName = "SF Discrete Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Discrete : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	/**
	* The underlying value type for the options in this setting.
	* @note @edo
	*/
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Discrete")
	TSubclassOf<USFSettingValue> ValueWrapperClass;

	/**
	* Does this setting have options that are generated dynamically at runtime?
	* @note @edo
	*/
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Discrete")
	bool bUseDynamicOptions = false;

	/**
	* For static options. The list of options to choose from for this setting. Each option has a display name and an underlying value. The value should be of the type specified by ValueWrapperClass.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "!bUseDynamicOptions"))
	TArray<struct FSFSettingOption> StaticOptions;

	/**
	* For dynamic options. The evaluator class that generates the options for this setting. The object created from this class is stored in USFSettingsSubsystem, and the logic from that object is run in GetSettingOptions() and GetDefaultValue().
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "bUseDynamicOptions"))
	TSubclassOf<class USFSettingOptionSource> OptionSource;

	/**
	* For dynamic options. The collection of settings that this setting should listen to to refresh its dynamic options. If the setting has a different refresh condition, explicitly call GetSettingOptions() for a new set of options.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "bUseDynamicOptions"))
	FGameplayTagContainer DeterminantSettingTags;

public:
	/**
	* @inheritdoc
	*/
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override;

	/**
	* Get the default value for this setting.
	* @return If UseDynamicOptions is set to true, return the default value evaluated from the OptionSource. Else, return the fallback default value defined in the DefaultValue property.
	*/
	virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const override;

	/**
	* Get the option list for this setting.
	* @return If UseDynamicOptions is set to true, return the option list evaluated from the OptionSource. Else, return the static option list defined in the StaticOptions property.
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
	TArray<struct FSFSettingOption> GetSettingOptions(const UObject* WorldContextObject) const;
};

/**
 * @brief Setting definition for setting keybind for an action.
 *
 * Setting definition for setting keybind for an action.
 *
 * Blueprint display name: SF Keybind Setting.
 */
UCLASS(DisplayName = "SF Keybind Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Key : public USFSettingDefinition
{
	GENERATED_BODY()

public:
	/**
	* The identifier for the primary KBM keybind in the Input Mapping Context.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
	FName KBMPrimaryName;

	/**
	* The identifier for the secondary KBM keybind in the Input Mapping Context.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
	FName KBMSecondaryName;

	/**
	* The identifier for the gamepad keybind in the Input Mapping Context.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
	FName GamepadName;

	/**
	* Channels identified by Gameplay Tags for collision checking. Only settings that share at least one channel will trigger collision warnings. 
	* Useful for categorizing keybinds into different groups such as "Global", "Combat", "UI", etc., so that only keybinds in the same group will trigger collision warnings.
	* @note @edo
	*/
	UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Behavior")
	FGameplayTagContainer CollisionChannels;

public:
	/**
	* @inheritdoc
	*/
	virtual TSubclassOf<USFSettingValue> GetValueClass() const override
	{
		return USFSettingValue_Key::StaticClass();
	}
};