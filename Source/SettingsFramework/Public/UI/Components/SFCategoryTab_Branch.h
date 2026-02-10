// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UI/Components/SFCategoryTabBase.h"
#include "SFCategoryTab_Branch.generated.h"

/**
 * A tab content widget representing a branch-type setting category that contains subcategories.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTab_Branch : public USFCategoryTabBase
{
	GENERATED_BODY()

#pragma region Initialization
public:
	// Lazy loading on activated
	virtual void NativeOnActivated() override;

protected:
	UFUNCTION()
	void HandleSubCategorySettingFocused(const struct FGameplayTag& SettingTag);

	bool bInitialized;
#pragma endregion

#pragma region Tab Navigation
protected:
	UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Branch|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonTabListWidgetBase> SubCategoryTabList;

	UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Branch|Tab Navigation", meta = (BindWidget))
	TObjectPtr<class UCommonAnimatedSwitcher> TabContentSwitcher;
#pragma endregion

#pragma region CommonUI Navigation
protected:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
#pragma endregion
};
