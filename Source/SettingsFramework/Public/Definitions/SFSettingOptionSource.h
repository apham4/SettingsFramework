// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFSettingOptionSource.generated.h"

/**
 * @brief Base class for providing a dynamic runtime list of options for a setting.
 *
 * Base class for providing a dynamic runtime list of options for a setting.
 * 
 * This class is used in USFSettingDefinition_Discrete when UseDynamicOptions is true.
 * @note @abstract @blueprintable @editinlinenew
 */
UCLASS(Abstract, Blueprintable, EditInlineNew)
class SETTINGSFRAMEWORK_API USFSettingOptionSource : public UObject
{
    GENERATED_BODY()

public:
    /**
	* Get the list of options to choose from for this setting
	* @param WorldContextObject The world context object from which to get the world object.
    * @return The list of options to choose from for this setting. The value should be of the type specified by the setting definition's ValueWrapperClass.
	* @note @bne
    */
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingOptionSource")
    TArray<struct FSFSettingOption> GetAvailableOptions(const UObject* WorldContextObject) const;
    
    /**
	* Native implementation of GetAvailableOptions.
    */
    virtual TArray<struct FSFSettingOption> GetAvailableOptions_Implementation(const UObject* WorldContextObject) const { return TArray<struct FSFSettingOption>(); }

    /**
	* Get the default value for this setting. This is optional to implement, and if not implemented, the setting will use the fallback default value defined in the DefaultValue property of the setting definition.
	* @param WorldContextObject The world context object from which to get the world object.
	* @return The default value for this setting. The value should be of the type specified by the setting definition's ValueWrapperClass.
	* @note @bne
    */
    UFUNCTION(BlueprintNativeEvent, Category = "SFSettingOptionSource")
    class USFSettingValue* GetDefaultValue(const UObject* WorldContextObject) const;

    /**
	* Native implementation of GetDefaultValue.
    */
    virtual class USFSettingValue* GetDefaultValue_Implementation(const UObject* WorldContextObject) const { return nullptr; }
};
