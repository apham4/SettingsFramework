// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingValue.generated.h"

/**
 * @brief Abstract base class for all setting values.
 *
 * Abstract base class for all setting values.
 * Wraps raw data (float, bool, key) into a generic UObject for safe transport.
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class SETTINGSFRAMEWORK_API USFSettingValue : public UObject
{
    GENERATED_BODY()

public:
	/**
    * Convert current value to string for saving
	* @return The string representation of the current value. Should be parseable by DeserializeFromString().
    */
    virtual FString SerializeToString() const PURE_VIRTUAL(USFSettingValue::SerializeToString, return FString(););

    /**
    * Load value from string
	* @param InString The string to parse the value from, typically loaded from disk.
    */
    virtual void DeserializeFromString(const FString& InString) PURE_VIRTUAL(USFSettingValue::DeserializeFromString, );

    /**
    * Creates a deep copy of this value
	* @param Outer The outer for the new duplicated object. Typically the caller should pass in itself as the outer, so that the duplicated value will be owned by the same object that owns this value.
	* @return A deep copy of this value object.
    */
    virtual USFSettingValue* Duplicate(UObject* Outer) const
    {
        return DuplicateObject<USFSettingValue>(this, Outer);
    };

    /**
    * Checks equality with another value object.
	* @param Other The other value object to compare with.
	* @return true if the two value objects are considered equal in terms of their underlying value, false otherwise.
    */
    virtual bool Equals(const USFSettingValue* Other) const PURE_VIRTUAL(USFSettingValue::Equals, return false;);

    /**
    * Helper function for debugging. Simply calls SerializeToString().
	* @return The string representation of the current value, same as SerializeToString().
    */
    virtual FString ToString() const { return SerializeToString(); }
};

/**
 * @brief Setting value representing a numeric value (int/float).
 * 
 * Setting value representing a numeric value (int/float).
 * 
 * Blueprint display name: SF Scalar Value.
 */
UCLASS(DisplayName = "SF Scalar Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Scalar : public USFSettingValue
{
    GENERATED_BODY()

public:
    /**
    * The underlying numeric value.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    float Value = 0.0f;

	/**
    * @inheritdoc
    */
    virtual FString SerializeToString() const override;
    /**
    * @inheritdoc
    */
    virtual void DeserializeFromString(const FString& InString) override;
    /**
    * @inheritdoc
    */
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
 * @brief Setting value representing a boolean value.
 * 
 * Setting value representing a boolean value.
 * 
 * Blueprint display name: SF Bool Value.
 */
UCLASS(DisplayName = "SF Bool Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Bool : public USFSettingValue
{
    GENERATED_BODY()

public:
    /**
    * The underlying bool value.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    bool Value = false;

    /**
    * @inheritdoc
    */
    virtual FString SerializeToString() const override;
    /**
    * @inheritdoc
    */
    virtual void DeserializeFromString(const FString& InString) override;
    /**
    * @inheritdoc
    */
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
 * @brief Setting value representing a Gameplay Tag for enum-type selection.
 *
 * Setting value representing a Gameplay Tag for enum-type selection.
 * 
 * Blueprint display name: SF Tag Value.
 */
UCLASS(DisplayName = "SF Tag Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Tag : public USFSettingValue
{
    GENERATED_BODY()

public:
    /**
    * The underlying Gameplay Tag value.
	* @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    FGameplayTag Value;

    /**
    * @inheritdoc
    */
    virtual FString SerializeToString() const override;
    /**
    * @inheritdoc
    */
    virtual void DeserializeFromString(const FString& InString) override;
    /**
    * @inheritdoc
    */
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
 * @brief Setting value with an underlying string value. Useful for IDs, names, resolutions, etc.
 *
 * Setting value with an underlying string value. Useful for IDs, names, resolutions, etc.
 * 
 * Blueprint display name: SF String Value.
 */
UCLASS(DisplayName = "SF String Value")
class SETTINGSFRAMEWORK_API USFSettingValue_String : public USFSettingValue
{
    GENERATED_BODY()

public:
    /**
    * The underlying string value.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    FString Value;

    /**
    * @inheritdoc
    */
    virtual FString SerializeToString() const override;
    /**
    * @inheritdoc
    */
    virtual void DeserializeFromString(const FString& InString) override;
    /**
    * @inheritdoc
    */
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
 * @brief Setting value representing a key binding for KBM and Gamepad.
 *
 * Setting value representing a key binding for KBM and Gamepad.
 * 
 * Blueprint display name: SF Keybind Value.
 */
UCLASS(DisplayName = "SF Keybind Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Key : public USFSettingValue
{
    GENERATED_BODY()

public:
    /**
    * The underlying keybind data struct.
	* @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    FSFKeybindValueData Value;

    /**
    * @inheritdoc
    */
    virtual FString SerializeToString() const override;
    /**
    * @inheritdoc
    */
    virtual void DeserializeFromString(const FString& InString) override;
    /**
    * @inheritdoc
    */
    virtual bool Equals(const USFSettingValue* Other) const override;
};