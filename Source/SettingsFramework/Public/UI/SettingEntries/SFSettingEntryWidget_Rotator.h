// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Rotator.generated.h"

/**
 * @brief The native base class for a setting entry widget for a discrete setting, represented as a rotator in the UI.
 *
 * The native base class for a setting entry widget for a discrete setting, represented as a rotator in the UI.
 * 
 * The widget blueprint implementing this class should be assigned as a value to the SettingEntryWidgetClasses map with the discrete setting definition class (USFSettingDefinition_Discrete) as the key in the Developer Settings at Project Settings > Plugins > SettingsFramework.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Rotator : public USFSettingEntryWidget
{
	GENERATED_BODY()

public:
	/**
	* Re-evaluate and repopulate the available options. Intended for discrete settings with dynamic options at runtime.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingEntryWidget_Rotator")
	void RefreshOptions();

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
	void HandleRotatorRotated(int32 NewValue, enum ERotatorDirection RotatorDirection);
	/** @endcond */

	/**
	* Intended for discrete settings with dynamic options at runtime. Refresh the available options when there is a value change from a determinant setting (specified in this discrete setting's definition asset).
	*/
	UFUNCTION()
	void CheckForDeterminantSettings(const FGameplayTag& ChangedSettingTag, class USFSettingValue* NewValue);

	/**
	* The rotator widget representing the discrete setting value in the UI.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Rotator", meta = (BindWidget))
	TObjectPtr<class UCommonRotator> RotatorWidget;

	/**
	* The transient list of options currently displayed by the rotator widget. This is to keep track of the full FSFSettingOption data structs since the rotator widget only stores the display text and index int.
	* @note @t
	*/
	UPROPERTY(Transient)
	TArray<struct FSFSettingOption> Options;

#pragma region Helpers
protected:
	/**
	* Populate the rotator widget with the provided list of setting options. This will also update the internal Options array to keep track of the full data for each option.
	* @param SettingOptions The list of setting options to populate the rotator widget with.
	*/
	void PopulateOptions(const TArray<struct FSFSettingOption>& SettingOptions);

	/**
	* Set the selected option in the rotator widget based on the provided setting value.
	* @param Value The setting value to match against the available options to select the appropriate one in the rotator widget.
	* @return True if a matching option was found and selected, false otherwise.
	*/
	bool SelectOptionByValue(const class USFSettingValue* Value);
#pragma endregion
};
