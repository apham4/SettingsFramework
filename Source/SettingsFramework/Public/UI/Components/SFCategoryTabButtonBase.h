// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "SFCategoryTabButtonBase.generated.h"

/**
 * Base class for tab buttons used in SFSettingsScreen and SFCategoryTab_Branch.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTabButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, Category = "SFCategoryTabButtonBase")
	void SetCategoryData(const class USFSettingCategory* InCategory);
	virtual void SetCategoryData_Implementation(const class USFSettingCategory* InCategory) {};
};
