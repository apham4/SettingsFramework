

# File SFSettingCategory.h

[**File List**](files.md) **>** [**Definitions**](dir_49fd2e6d8d3cd0aca0d770534c763afe.md) **>** [**SFSettingCategory.h**](SFSettingCategory_8h.md)

[Go to the documentation of this file](SFSettingCategory_8h.md)


```C++
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

USTRUCT(BlueprintType)
struct FSFSettingGroup
{
    GENERATED_BODY()

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingGroup")
    FText GroupDisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingGroup")
    TArray<TObjectPtr<class USFSettingDefinition>> Settings;
};

UCLASS(BlueprintType)
class SETTINGSFRAMEWORK_API USFSettingCategory : public UDataAsset
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory")
    FGameplayTag CategoryTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory")
    ESFCategoryType CategoryType = ESFCategoryType::Leaf;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Display")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Branch", meta = (EditCondition = "CategoryType == ESFCategoryType::Branch"))
    TArray<TObjectPtr<USFSettingCategory>> Subcategories;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Leaf", meta = (EditCondition = "CategoryType == ESFCategoryType::Leaf"))
    TArray<FSFSettingGroup> SettingGroups;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingCategory|Leaf", meta = (EditCondition = "CategoryType == ESFCategoryType::Leaf"))
    TArray<TObjectPtr<class USFSettingDefinition>> Settings;
};
```


