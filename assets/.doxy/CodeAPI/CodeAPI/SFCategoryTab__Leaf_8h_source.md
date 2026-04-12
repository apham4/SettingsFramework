

# File SFCategoryTab\_Leaf.h

[**File List**](files.md) **>** [**Components**](dir_d359c2365a038846f780cd493464dc51.md) **>** [**SFCategoryTab\_Leaf.h**](SFCategoryTab__Leaf_8h.md)

[Go to the documentation of this file](SFCategoryTab__Leaf_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Components/SFCategoryTabBase.h"
#include "GameplayTagContainer.h"
#include "SFCategoryTab_Leaf.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTab_Leaf : public USFCategoryTabBase
{
    GENERATED_BODY()

#pragma region Initialization
public:
    virtual void InitializeCategoryDisplay() override;

protected:
    UFUNCTION()
    void HandleSettingEntryFocused(const FGameplayTag& SettingTag);

    void CreateSettingEntryAndAddToGroup(const class USFSettingDefinition* SettingDefinition, class USFSettingGroupWidget* GroupWidget);

    bool bInitialized;
#pragma endregion

#pragma region Setting Display
protected:
    UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Leaf", meta = (BindWidget))
    TObjectPtr<class UPanelWidget> SettingGroupContainer;

    UPROPERTY(Transient)
    TMap<FGameplayTag, TObjectPtr<class USFSettingEntryWidget>> EntryWidgetMap;

    UFUNCTION(BlueprintImplementableEvent, Category = "SFCategoryTab_Leaf")
    void OnGroupWidgetAdded(class UPanelSlot* WidgetAsPanelSlot, class USFSettingGroupWidget* WidgetAsGroupWidget);
#pragma endregion

#pragma region CommonUI Navigation
public:
    virtual UWidget* NativeGetDesiredFocusTarget() const override;

protected:
    TWeakObjectPtr<class USFSettingEntryWidget> LastFocusedEntry;
#pragma endregion
};
```


