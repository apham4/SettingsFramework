// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Checkbox.generated.h"

/**
 * Setting entry widget for boolean settings, represented as a checkbox in the UI.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Checkbox : public USFSettingEntryWidget
{
	GENERATED_BODY()
	
protected:
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

	UFUNCTION()
	void HandleCheckStateChanged(bool bIsChecked);

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Checkbox", meta = (BindWidget))
	TObjectPtr<class UCheckBox> CheckboxWidget;
};
