// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SFSettingsRegistry.generated.h"

/**
 * Central Setting Collection containing all setting definitions and their hierarchies to be loaded by the FSSettingsSubsystem.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingsRegistry : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// The outermost categories. Categories can contain sub-categories OR individual setting definitions.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsRegistry")
	TArray<TObjectPtr<class USFSettingCategory>> RootCategories;
};
