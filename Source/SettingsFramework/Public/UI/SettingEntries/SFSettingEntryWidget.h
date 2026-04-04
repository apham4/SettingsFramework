// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingEntryWidget.generated.h"

/**
 * @brief The native base class for a single setting entry in the settings UI.
 *
 * The native base class for a single setting entry in the settings UI. 
 * This widget represents and displays a single setting definition from the USFSettingsSubsystem, allowing the player to view and change the setting value.
 * @note @abstract @blueprinttype @blueprintable
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

#pragma region Initialization
public:
	/** @cond */
	virtual void NativeConstruct() override;
	/** @endcond */

	/**
	* Initializes the data and display of this setting entry widget based on the assigned setting definition asset.
	* Subclasses can override this function to hook up any setting type-specific logic or display elements, but should call the parent implementation to ensure the base functionality is executed (e.g., binding to setting value change events from the subsystem).
	* @param InSettingDefinition The setting definition asset represented by this widget.
	*/
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);
	
protected:
	/**
	* Initializes the display of this setting entry widget based on the assigned setting definition asset, called after the native InitializeSettingEntry to allow for Blueprint implementations to run after the base logic.
	* @param InSettingDefinition The setting definition asset represented by this widget.
	* @note @bie
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingEntryWidget|Initialization", meta = (DisplayName = "Initialize Setting Entry"))
	void BP_InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);

	/** @cond */
	UFUNCTION()
	void HandleOnSettingValueChanged(const FGameplayTag& ChangedSettingTag, class USFSettingValue* NewValue);
	/** @endcond */
#pragma endregion

#pragma region Widgets
protected:
	/**
	* Optional text block widget displaying the setting name/label.
	* @note @bro @bwo
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget|Widgets", meta = (BindWidgetOptional))
	TObjectPtr<class UCommonTextBlock> SettingLabel;
#pragma endregion

#pragma region Setting Data
public:
	/**
	* Get the Gameplay Tag of the setting represented by this entry widget.
	* @return The Gameplay Tag of the setting represented by this entry widget.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget|Setting Data")
	FGameplayTag GetSettingTag() const { return SettingTag; }

	/**
	* Get the setting definition asset represented by this entry widget.
	* @return The setting definition asset represented by this entry widget.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget|Setting Data")
	class USFSettingDefinition* GetSettingDefinition() const;

	/**
	* Event fired when the setting entry is hovered/focused in the UI, used for bubbling up the focused setting's tag to the settings screen widget to display its info.
	* @note @ba
	*/
	UPROPERTY(BlueprintAssignable, Category = "SFSettingEntryWidget|Setting Data")
	FOnSettingEntryFocused OnSettingFocused;

protected:
	/**
	* The Gameplay Tag of the setting represented by this entry widget, used to communication with the USFSettingsSubsystem.
	* @note @bro
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget|Setting Data")
	FGameplayTag SettingTag;
#pragma endregion

#pragma region Setting Value & State
protected:
	/**
	* Requests the USFSettingsSubsystem to change the value of the setting represented by this entry widget.
	* This should be called when the user interacts with the entry widget to change the setting value (e.g., moving a slider, checking/unchecking a checkbox, etc.).
	* @param NewValue The new value to set for the setting, represented as a USFSettingValue object.
	* @note @bc
	*/
	UFUNCTION(BlueprintCallable, Category = "SFSettingEntryWidget|Setting Value & State")
	void OnUserChangedValue(class USFSettingValue* NewValue);

	/**
	* Update the visual representation of the setting value (e.g., slider position, checkbox state) based on the given value. 
	* This is called in response to setting value change events from the subsystem to ensure the UI stays in sync with the actual setting values.
	* When overriding in Blueprint, call the parent implementation if the native superclass has one.
	* @note @bne
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "SFSettingEntryWidget|Setting Value & State")
	void UpdateVisualValue(const class USFSettingValue* NewValue);

	/**
	* Native implementation of UpdateVisualValue, can be optionally overridden by C++ subclasses to handle setting value change events from the subsystem.
	*/
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) {};

	/**
	* Internal function to update the visibility and editability of the widget based on the evaluation of the associated setting from the USFSettingsSubsystem.
	*/
	void UpdateWidgetState();
#pragma endregion

#pragma region Navigation
public:
	/** @cond */
	UFUNCTION(BlueprintNativeEvent, Category = "SFSettingEntryWidget|Navigation")
	UWidget* GetPrimaryFocusTarget() const;
	virtual UWidget* GetPrimaryFocusTarget_Implementation() const;

protected:
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	/** @endcond */
#pragma endregion
};
