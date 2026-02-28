// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingEntryWidget.generated.h"

/**
 * Base class for a single setting entry (e.g., a slider or checkbox) in the settings UI.
 * Handles binding to the Subsystem events automatically.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

#pragma region Initialization
public:
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingEntryWidget|Initialization", meta = (DisplayName = "Initialize Setting Entry"))
	void BP_InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);

	UFUNCTION()
	void HandleOnSettingValueChanged(const FGameplayTag& ChangedSettingTag, class USFSettingValue* NewValue);
#pragma endregion

#pragma region Widgets
protected:
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget|Widgets", meta = (BindWidgetOptional))
	TObjectPtr<class UCommonTextBlock> SettingLabel;
#pragma endregion

#pragma region Setting Data
public:
	UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget|Setting Data")
	FGameplayTag GetSettingTag() const { return SettingTag; }

	UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget|Setting Data")
	class USFSettingDefinition* GetSettingDefinition() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget")
	FGameplayTag SettingTag;
#pragma endregion

#pragma region Setting Value & State
protected:
	// Call this when the user interacts with the entry widget to change the setting value.
	UFUNCTION(BlueprintCallable, Category = "SFSettingEntryWidget|Setting Value & State")
	void OnUserChangedValue(class USFSettingValue* NewValue);

	// Update the visual representation of the setting value (e.g., slider position, checkbox state) based on the new value from SFSettingsSubsystem.
	UFUNCTION(BlueprintNativeEvent, Category = "SFSettingEntryWidget|Setting Value & State")
	void UpdateVisualValue(const class USFSettingValue* NewValue);
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) {};

	void UpdateWidgetState();
#pragma endregion

#pragma region Navigation
public:
	UPROPERTY(BlueprintAssignable, Category = "SFSettingEntryWidget|Navigation")
	FOnSettingEntryFocused OnSettingFocused;

protected:
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
#pragma endregion
};
