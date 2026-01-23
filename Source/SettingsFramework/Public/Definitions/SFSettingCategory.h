// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "SFSettingCategory.generated.h"

UENUM(BlueprintType)
enum class ESFCategoryType : uint8
{
	Branch UMETA(ToolTip = "Contains other Sub-Categories"),
	Leaf   UMETA(ToolTip = "Contains individual Settings")
};

/**
 * Struct to visually group settings within a Leaf Category.
 * e.g. "Post-Processing" group inside "Graphics" category.
 */
USTRUCT(BlueprintType)
struct FSFSettingGroup
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingGroup")
    FText GroupDisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingGroup")
    TArray<TObjectPtr<class USFSettingDefinition>> Settings;
};

/**
 * Defines a Category that can contain either Sub-Categories or individual Settings.
 */
UCLASS(BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingCategory : public UDataAsset
{
	GENERATED_BODY()
	
public:
    // Identifying category tag
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory")
	FGameplayTag CategoryTag;

	// Does this Category contain Sub-Categories (Branch) or individual Settings (Leaf)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory")
    ESFCategoryType CategoryType = ESFCategoryType::Leaf;

	// User-facing category name
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Display")
    FText DisplayName;

    // Sub-categories for Branch categories
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Branch", meta = (EditCondition = "CategoryType == ESFCategoryType::Branch"))
    TArray<TObjectPtr<USFSettingCategory>> Subcategories;

	// Setting groups for Leaf categories
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Leaf", meta = (EditCondition = "CategoryType == ESFCategoryType::Leaf"))
    TArray<FSFSettingGroup> SettingGroups;

	// Individual settings for Leaf categories if grouping is not required.
	// Will only be used if SettingGroups is empty.
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Leaf", meta = (EditCondition = "CategoryType == ESFCategoryType::Leaf"))
    TArray<TObjectPtr<class USFSettingDefinition>> Settings;
};
