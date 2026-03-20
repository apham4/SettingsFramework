// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingValue.generated.h"

// NOTE_TO_SELF: EditInlineNew allows creating objects directly inside data asset editor properties.
// NOTE_TO_SELF: DefaultToInstanced treats all instsances of this UObject as unique instsanced objects.

/**
 * Abstract base class for all setting values.
 * Wraps raw data (float, bool, key) into a generic UObject for safe transport.
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class SETTINGSFRAMEWORK_API USFSettingValue : public UObject
{
    GENERATED_BODY()

public:
	// NOTE_TO_SELF: PURE_VIRTUAL forces derived classes to implement these methods.

    // Convert current value to string for saving
    virtual FString SerializeToString() const PURE_VIRTUAL(USFSettingValue::SerializeToString, return FString(););

    // Load value from string
    virtual void DeserializeFromString(const FString& InString) PURE_VIRTUAL(USFSettingValue::DeserializeFromString, );

    // Creates a deep copy of this value
    virtual USFSettingValue* Duplicate(UObject* Outer) const
    {
        return DuplicateObject<USFSettingValue>(this, Outer);
    };

    // Checks equality with another value object
    virtual bool Equals(const USFSettingValue* Other) const PURE_VIRTUAL(USFSettingValue::Equals, return false;);

    // Helper for debugging
    virtual FString ToString() const { return SerializeToString(); }
};

/**
 * Setting value representing a numeric value (int/float).
 */
UCLASS(DisplayName = "SF Scalar Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Scalar : public USFSettingValue
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    float Value = 0.0f;

    virtual FString SerializeToString() const override;
    virtual void DeserializeFromString(const FString& InString) override;
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
 * Setting value representing a boolean value.
 */
UCLASS(DisplayName = "SF Bool Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Bool : public USFSettingValue
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    bool Value = false;

    virtual FString SerializeToString() const override;
    virtual void DeserializeFromString(const FString& InString) override;
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
* Setting value representing an enum-type selection.
*/
UCLASS(DisplayName = "SF Tag Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Tag : public USFSettingValue
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    FGameplayTag Value;

    virtual FString SerializeToString() const override;
    virtual void DeserializeFromString(const FString& InString) override;
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
* Setting value with a string as the underlying value. Useful for IDs, names, resolutions, etc.
*/
UCLASS(DisplayName = "SF String Value")
class SETTINGSFRAMEWORK_API USFSettingValue_String : public USFSettingValue
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    FString Value;

    virtual FString SerializeToString() const override;
    virtual void DeserializeFromString(const FString& InString) override;
    virtual bool Equals(const USFSettingValue* Other) const override;
};

/**
 * Setting value representing a key binding (key/input chord).
 */
UCLASS(DisplayName = "SF Keybind Value")
class SETTINGSFRAMEWORK_API USFSettingValue_Key : public USFSettingValue
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
    FSFKeybindValueData Value;

    virtual FString SerializeToString() const override;
    virtual void DeserializeFromString(const FString& InString) override;
    virtual bool Equals(const USFSettingValue* Other) const override;
};