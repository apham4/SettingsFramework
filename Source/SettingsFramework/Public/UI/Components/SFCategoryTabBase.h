// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Core/SFCoreTypes.h"
#include "SFCategoryTabBase.generated.h"

/**
 * @brief The native base class for the content widget representing a setting category.
 *
 * The native base class for the content widget representing a setting category. 
 * 
 * This is the superclass of USFCategoryTab_Branch, which displays a branch-type category with subcategories, and USFCategoryTab_Leaf, which displays a leaf-type category with setting entries.
 * @note @abstract @blueprinttype
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTabBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

#pragma region Initialization
public:
	/**
	* Assign the corresponding category asset to this widget.
	* @param InSettingCategory The category asset represented by this widget.
	*/
	void SetCategory(class USFSettingCategory* InSettingCategory);

	/**
	* Populate the widget with the data from the category asset. This is called when the widget is displayed for the first time to allow for lazy loading.
	*/
	virtual void InitializeCategoryDisplay() {};
#pragma endregion

#pragma region Setting Category Data
public:
	/**
	* Get the category asset assigned to this widget.
	* @return The category asset assigned to this widget.
	* @note @bp
	*/
	UFUNCTION(BlueprintPure, Category = "SFCategoryTabBase|Setting Category Data")
	const class USFSettingCategory* GetSettingCategory() const { return SettingCategory; }

	/**
	* Event fired when a setting entry within this category is hovered/focused in the UI, with the focused setting's tag as a parameter.
	*/
	UPROPERTY(BlueprintAssignable, Category = "SFCategoryTabBase")
	FOnSettingEntryFocused OnSettingFocused;

protected:
	/**
	* The transient pointer to the category asset represented by this widget.
	* @note @t
	*/
	UPROPERTY(Transient)
	TObjectPtr<class USFSettingCategory> SettingCategory;
#pragma endregion
};
