

# File SFSettingDefinition.h

[**File List**](files.md) **>** [**Definitions**](dir_49fd2e6d8d3cd0aca0d770534c763afe.md) **>** [**SFSettingDefinition.h**](SFSettingDefinition_8h.md)

[Go to the documentation of this file](SFSettingDefinition_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Core/SFSettingValue.h"
#include "SFSettingDefinition.generated.h"

UCLASS(Abstract, BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingDefinition : public UDataAsset
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition")
    FGameplayTag SettingTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Display")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Display", meta = (MultiLine = true))
    FText Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
    TArray<TObjectPtr<class USFSettingCondition>> VisibilityConditions;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
    TArray<TObjectPtr<class USFSettingCondition>> EditabilityConditions;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Behavior")
    bool bRevertToDefaultOnDisable = false;

public:
    virtual TSubclassOf<USFSettingValue> GetValueClass() const { PURE_VIRTUAL(USFSettingDefinition::GetValueClass, return nullptr;); }

    UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
    virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const { return DefaultValue; };

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value")
    TObjectPtr<class USFSettingValue> DefaultValue;
};

UCLASS(DisplayName = "SF Scalar Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Scalar : public USFSettingDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
    float MinValue = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
    float MaxValue = 100.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Scalar")
    float StepSize = 1.0f;

public:
    virtual TSubclassOf<USFSettingValue> GetValueClass() const override
    {
        return USFSettingValue_Scalar::StaticClass();
    }
};

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

UCLASS(DisplayName = "SF Discrete Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Discrete : public USFSettingDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Discrete")
    TSubclassOf<USFSettingValue> ValueWrapperClass;

    UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Value|Discrete")
    bool bUseDynamicOptions = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "!bUseDynamicOptions"))
    TArray<struct FSFSettingOption> StaticOptions;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "bUseDynamicOptions"))
    TSubclassOf<class USFSettingOptionSource> OptionSource;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Discrete", meta = (EditCondition = "bUseDynamicOptions"))
    FGameplayTagContainer DeterminantSettingTags;

public:
    virtual TSubclassOf<USFSettingValue> GetValueClass() const override;

    virtual class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const override;

    UFUNCTION(BlueprintPure, Category = "SFSettingDefinition|Value", meta = (WorldContext="WorldContextObject"))
    TArray<struct FSFSettingOption> GetSettingOptions(const UObject* WorldContextObject) const;
};

UCLASS(DisplayName = "SF Keybind Setting")
class SETTINGSFRAMEWORK_API USFSettingDefinition_Key : public USFSettingDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
    FName KBMPrimaryName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
    FName KBMSecondaryName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingDefinition|Value|Keybind")
    FName GamepadName;

    UPROPERTY(EditDefaultsOnly, Category = "SFSettingDefinition|Behavior")
    FGameplayTagContainer CollisionChannels;

public:
    virtual TSubclassOf<USFSettingValue> GetValueClass() const override
    {
        return USFSettingValue_Key::StaticClass();
    }
};
```


