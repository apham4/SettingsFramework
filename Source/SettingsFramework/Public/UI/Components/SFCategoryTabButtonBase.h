// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "SFCategoryTabButtonBase.generated.h"

/**
 * @brief Base widget class for tab buttons used in the CategoryTabList of USFSettingsScreen and USFCategoryTab_Branch.
 *
 * Base widget class for tab buttons used in the CategoryTabList of USFSettingsScreen and USFCategoryTab_Branch.
 * The widget blueprints implementing this class should be assigned to the RootTabButtonClass and BranchTabButtonClass in the Developer Settings at Project Settings > Plugins > SettingsFramework.
 * @note @abstract @blueprinttype @blueprintable
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTabButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()
	
public:
	/**
	* Sets the tab button's display provided the setting category it represents.
	* @param InCategory The setting category represented by this tab button.
	* @note @bne
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "SFCategoryTabButtonBase")
	void SetCategoryData(const class USFSettingCategory* InCategory);

	/**
	* Native implementation of SetCategoryData.
	*/
	virtual void SetCategoryData_Implementation(const class USFSettingCategory* InCategory) {};
};
