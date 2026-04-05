// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UI/Components/SFCategoryTabBase.h"
#include "SFCategoryTab_Branch.generated.h"

/**
 * @brief The native base class for the content widget representing a branch-type setting category (contains sub-categories).
 *
 * The native base class for the content widget representing a branch-type setting category (contains sub-categories).
 * This is a subclass of USFCategoryTabBase. It is added to USFSettingsScreen's TabContentSwitcher for branch-type categories.
 * 
 * The widget blueprint implementing this class should be assigned to the BranchTabContentClass in the Developer Settings at Project Settings > Plugins > SettingsFramework.
 * @note @abstract @blueprinttype @blueprintable
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTab_Branch : public USFCategoryTabBase
{
	GENERATED_BODY()

#pragma region Initialization
public:
	/**
	* @inheritdoc
	*/
	virtual void InitializeCategoryDisplay() override;

protected:
	/** @cond */
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void HandleSwitcherActiveIndexChanged(UWidget* ContentWidget, int32 Index);

	UFUNCTION()
	void HandleSubCategorySettingFocused(const struct FGameplayTag& SettingTag);

	bool bInitialized;
	/** @endcond */
#pragma endregion

#pragma region Tab Navigation
protected:
	/**
	* The Common Tab List widget containing tab buttons representing the sub-categories.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Branch|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonTabListWidgetBase> SubCategoryTabList;

	/**
	* The Common Activatable Widget Switcher containing the content for each sub-category, switched by the SubCategoryTabList.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Branch|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonActivatableWidgetSwitcher> TabContentSwitcher;
#pragma endregion

#pragma region CommonUI Navigation
public:
	/** @cond */
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
	/** @endcond */
#pragma endregion
};
