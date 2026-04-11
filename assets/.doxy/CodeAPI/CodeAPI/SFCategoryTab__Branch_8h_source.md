

# File SFCategoryTab\_Branch.h

[**File List**](files.md) **>** [**Components**](dir_d359c2365a038846f780cd493464dc51.md) **>** [**SFCategoryTab\_Branch.h**](SFCategoryTab__Branch_8h.md)

[Go to the documentation of this file](SFCategoryTab__Branch_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UI/Components/SFCategoryTabBase.h"
#include "SFCategoryTab_Branch.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTab_Branch : public USFCategoryTabBase
{
    GENERATED_BODY()

#pragma region Initialization
public:
    virtual void InitializeCategoryDisplay() override;

protected:
    virtual void NativeOnInitialized() override;

    UFUNCTION()
    void HandleSwitcherActiveIndexChanged(UWidget* ContentWidget, int32 Index);

    UFUNCTION()
    void HandleSubCategorySettingFocused(const struct FGameplayTag& SettingTag);

    bool bInitialized;
#pragma endregion

#pragma region Tab Navigation
protected:
    UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Branch|Tab Navigation", meta = (BindWidget))
    TObjectPtr<class UCommonTabListWidgetBase> SubCategoryTabList;

    UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Branch|Tab Navigation", meta = (BindWidget))
    TObjectPtr<class UCommonActivatableWidgetSwitcher> TabContentSwitcher;
#pragma endregion

#pragma region CommonUI Navigation
public:
    virtual UWidget* NativeGetDesiredFocusTarget() const override;
#pragma endregion
};
```


