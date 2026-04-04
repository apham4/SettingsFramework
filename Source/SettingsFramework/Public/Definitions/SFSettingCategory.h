// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "SFSettingCategory.generated.h"

/**
 * Enum to define whether a Category is a Branch (contains sub-categories) or a Leaf (contains individual settings).
 */
UENUM(BlueprintType)
enum class ESFCategoryType : uint8
{
	Branch UMETA(ToolTip = "Contains other Sub-Categories"),
	Leaf   UMETA(ToolTip = "Contains individual Settings")
};

/**
 * @brief Struct to visually group settings within a Leaf Category.
 *
 * Struct to visually group settings within a Leaf Category (e.g. "Post-Processing" group inside "Graphics" category.).
 * This is optional and only for organizational and visual purposes. It does not affect the behavior of the settings in any way.
 * @note @blueprinttype
 */
USTRUCT(BlueprintType)
struct FSFSettingGroup
{
    GENERATED_BODY()

    /**
	* The player-facing name of this setting group, displayed on UI.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingGroup")
    FText GroupDisplayName;

    /**
    * The collection of settings to be displayed in this group.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingGroup")
    TArray<TObjectPtr<class USFSettingDefinition>> Settings;
};

/**
 * @brief Defines a Category that can contain either Sub-Categories (Branch) or individual Settings (Leaf).
 *
 * Defines a Category that can contain either Sub-Categories (Branch) or individual Settings (Leaf).
 * @note @blueprinttype
 */
UCLASS(BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingCategory : public UDataAsset
{
	GENERATED_BODY()
	
public:
    /**
    * The category's unique identifier.
    * @note @edo @bro
    */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory")
	FGameplayTag CategoryTag;

	/**
	* Is this a Branch category that contains sub-categories, or a Leaf category that contains individual settings?
	* @note @edo @bro
    */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory")
    ESFCategoryType CategoryType = ESFCategoryType::Leaf;

    /**
    * The player-facing name of this category, displayed on UI.
    * @note @edo @bro
    */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Display")
    FText DisplayName;

    /**
	* For Branch category. The collection of sub-categories under this category.
    * @note @edo @bro
    */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Branch", meta = (EditCondition = "CategoryType == ESFCategoryType::Branch"))
    TArray<TObjectPtr<USFSettingCategory>> Subcategories;

	/**
    * For Leaf category. The collection of setting groups under this category.
    * @note @edo @bro
    */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Leaf", meta = (EditCondition = "CategoryType == ESFCategoryType::Leaf"))
    TArray<FSFSettingGroup> SettingGroups;

	/**
	* For Leaf category. If setting groups are not desired, individual settings can be added directly to the category without grouping.
    * @note @edo @bro
    */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Leaf", meta = (EditCondition = "CategoryType == ESFCategoryType::Leaf"))
    TArray<TObjectPtr<class USFSettingDefinition>> Settings;
};