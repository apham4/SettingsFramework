

# File SFSettingsScreen.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**UI**](dir_c0d111a2beff4c46a32685df6daadb0f.md) **>** [**SFSettingsScreen.h**](SFSettingsScreen_8h.md)

[Go to the documentation of this file](SFSettingsScreen_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SFSettingsScreen.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingsScreen : public UCommonActivatableWidget
{
    GENERATED_BODY()
    
#pragma region Initialization
protected:
    virtual void NativeOnInitialized() override;

    // Lazy loading on activated
    virtual void NativeOnActivated() override;
    UFUNCTION()
    void InitializeSettingsScreen();

    bool bTabsInitialized;
#pragma endregion

#pragma region Tab Navigation
protected:
    UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Tab Navigation", meta = (BindWidget))
    TObjectPtr<class UCommonTabListWidgetBase> CategoryTabList;

    UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Tab Navigation", meta = (BindWidget))
    TObjectPtr<class UCommonActivatableWidgetSwitcher> TabContentSwitcher;

protected:
    UFUNCTION()
    void HandleSwitcherActiveIndexChanged(UWidget* ContentWidget, int32 Index);
#pragma endregion

#pragma region Display
protected:
    UFUNCTION()
    void HandleSettingFocused(const struct FGameplayTag& SettingTag);
    UPROPERTY(BlueprintReadOnly, Category = "SFSettingsScreen|Display", meta = (BindWidget))
    TObjectPtr<class USFSettingInfoDisplay> SettingInfoDisplay;
#pragma endregion

#pragma region Setting Actions
protected:
    UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
    void SaveSettings();

    UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
    void RevertSettings();

    UFUNCTION(BlueprintCallable, Category = "SFSettingsScreen|Setting Actions")
    void ResetSettingsToDefault();
#pragma endregion

#pragma region CommonUI Navigation
protected:
    virtual UWidget* NativeGetDesiredFocusTarget() const override;
#pragma endregion

#pragma region Input Action
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsScreen|Input Action")
    TObjectPtr<class UInputAction> SaveAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsScreen|Input Action")
    TObjectPtr<class UInputAction> RevertAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFSettingsScreen|Input Action")
    TObjectPtr<class UInputAction> ResetToDefaultAction;
#pragma endregion
};
```


