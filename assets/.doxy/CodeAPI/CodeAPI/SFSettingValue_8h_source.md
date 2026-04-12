

# File SFSettingValue.h

[**File List**](files.md) **>** [**Core**](dir_39651220af2aa02d3a35c23742da36c9.md) **>** [**SFSettingValue.h**](SFSettingValue_8h.md)

[Go to the documentation of this file](SFSettingValue_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingValue.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class SETTINGSFRAMEWORK_API USFSettingValue : public UObject
{
    GENERATED_BODY()

public:
    virtual FString SerializeToString() const PURE_VIRTUAL(USFSettingValue::SerializeToString, return FString(););

    virtual void DeserializeFromString(const FString& InString) PURE_VIRTUAL(USFSettingValue::DeserializeFromString, );

    virtual USFSettingValue* Duplicate(UObject* Outer) const
    {
        return DuplicateObject<USFSettingValue>(this, Outer);
    };

    virtual bool Equals(const USFSettingValue* Other) const PURE_VIRTUAL(USFSettingValue::Equals, return false;);

    virtual FString ToString() const { return SerializeToString(); }
};

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
```


