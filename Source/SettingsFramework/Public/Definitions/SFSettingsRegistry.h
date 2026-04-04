// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SFSettingsRegistry.generated.h"

/**
 * @brief The central registry asset that contains the entire hierarchy of settings.
 *
 * The central registry asset that contains the entire hierarchy of settings, starting from the root categories down to individual setting definitions.
 * This needs to be assigned through the plugin's project-wide Developer Settings to be loaded on initialization by the USFSettingsSubsystem.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingsRegistry : public UDataAsset
{
	GENERATED_BODY()
	
public:
	/**
	* The collection of outer-most categories. Categories can contain sub-categories OR individual setting definitions.
	* Any setting definitions that should be loaded by the plugin must be contained in this hierarchy starting from these root categories.
	* @note @edo @bro
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsRegistry")
	TArray<TObjectPtr<class USFSettingCategory>> RootCategories;
};
