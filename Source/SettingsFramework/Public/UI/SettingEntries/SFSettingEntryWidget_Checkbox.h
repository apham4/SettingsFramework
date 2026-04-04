// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Checkbox.generated.h"

/**
 * @brief The native base class for a setting entry widget for a boolean setting, represented as a checkbox in the UI.
 *
 * The native base class for a setting entry widget for a boolean setting, represented as a checkbox in the UI.
 * 
 * The widget blueprint implementing this class should be assigned as a value to the SettingEntryWidgetClasses map with the boolean setting definition class (USFSettingDefinition_Bool) as the key in the Developer Settings at Project Settings > Plugins > SettingsFramework.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Checkbox : public USFSettingEntryWidget
{
	GENERATED_BODY()
	
protected:
	/**
	* @inheritdoc
	*/
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;

	/**
	* @inheritdoc
	*/
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

	/** @cond */
	UFUNCTION()
	void HandleCheckStateChanged(bool bIsChecked);
	/** @endcond */

	/**
	* The checkbox widget representing the boolean setting value in the UI.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Checkbox", meta = (BindWidget))
	TObjectPtr<class UCheckBox> CheckboxWidget;
};
