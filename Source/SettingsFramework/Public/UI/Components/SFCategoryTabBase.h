// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Core/SFCoreTypes.h"
#include "SFCategoryTabBase.generated.h"

/**
 * A tab content widget representing a setting category. Can have subcategories (tabbed) or setting entries.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTabBase : public UCommonUserWidget
{
	GENERATED_BODY()

#pragma region Initialization
public:
	// Assign the category asset
	void SetCategory(class USFSettingCategory* InSettingCategory);

	// Call this when the Category Tab is displayed
	virtual void InitializeCategoryDisplay() {};
#pragma endregion

#pragma region Setting Category Data
public:
	UFUNCTION(BlueprintPure, Category = "SFCategoryTabBase|Setting Category Data")
	const class USFSettingCategory* GetSettingCategory() const { return SettingCategory; }

	UPROPERTY(BlueprintAssignable, Category = "SFCategoryTabBase")
	FOnSettingEntryFocused OnSettingFocused;

protected:
	UPROPERTY(Transient)
	TObjectPtr<class USFSettingCategory> SettingCategory;
#pragma endregion

#pragma region CommonUI Navigation
public:
	virtual UWidget* GetDesiredFocusTarget() const;
#pragma endregion
};
