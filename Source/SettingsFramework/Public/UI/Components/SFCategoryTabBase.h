// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Core/SFCoreTypes.h"
#include "SFCategoryTabBase.generated.h"

/**
 * A tab content widget representing a setting category. Can have subcategories (tabbed) or setting entries.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTabBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

#pragma region Initialization
public:
	// Initialize the tab with its corresponding setting category data. Should be called immediately after creation.
	void InitializeWithCategory(class USFSettingCategory* InSettingCategory);
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
};
