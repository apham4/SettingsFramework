// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/SettingEntries/SFSettingEntryWidget.h"
#include "SFSettingEntryWidget_Rotator.generated.h"

/**
 * Setting entry widget for discrete settings, represented as a button cycling through options in the UI.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget_Rotator : public USFSettingEntryWidget
{
	GENERATED_BODY()

public:
	// Intended for discrete settings with dynamic options. Call this to re-evaluate and repopulate the options
	UFUNCTION(BlueprintCallable, Category = "SFSettingEntryWidget_Rotator")
	void RefreshOptions();

protected:
	virtual void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition) override;
	virtual void UpdateVisualValue_Implementation(const class USFSettingValue* NewValue) override;

	UFUNCTION()
	void HandleRotatorRotated(int32 NewValue, enum ERotatorDirection RotatorDirection);

	UFUNCTION()
	void CheckForDeterminantSettings(const FGameplayTag& ChangedSettingTag, class USFSettingValue* NewValue);

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget_Rotator", meta = (BindWidget))
	TObjectPtr<class UCommonRotator> RotatorWidget;

	UPROPERTY(Transient)
	TArray<struct FSFSettingOption> Options;

#pragma region Helpers
protected:
	void PopulateOptions(const TArray<struct FSFSettingOption>& SettingOptions);
	bool SelectOptionByValue(const class USFSettingValue* Value);
#pragma endregion
};
