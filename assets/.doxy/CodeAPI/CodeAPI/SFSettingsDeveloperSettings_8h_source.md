

# File SFSettingsDeveloperSettings.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**SFSettingsDeveloperSettings.h**](SFSettingsDeveloperSettings_8h.md)

[Go to the documentation of this file](SFSettingsDeveloperSettings_8h.md)


```C++
// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingsDeveloperSettings.generated.h"

UCLASS(Config = Game, meta = (DisplayName = "Settings Framework", ToolTip = "Developer settings to define project-wide configurations for the SettingsFramework plugin."))
class SETTINGSFRAMEWORK_API USFSettingsDeveloperSettings : public UDeveloperSettings
{
    GENERATED_BODY()
    
public:
    UPROPERTY(Config, EditAnywhere, Category = "Settings Registry")
    TSoftObjectPtr<class USFSettingsRegistry> SettingsRegistry;

    UPROPERTY(Config, EditAnywhere, Category = "Settings Serialization")
    FString SaveGameSlotName = TEXT("SF_SaveSlot");

    UPROPERTY(Config, EditAnywhere, Category = "Settings Conditions")
    int32 MaxUpdateDepth = 10;

    UPROPERTY(Config, EditAnywhere, Category = "Settings Logic")
    ESFKeybindCollisionResolution DefaultKeybindCollisionResolution = ESFKeybindCollisionResolution::Overwrite;

    UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
    TSubclassOf<class USFCategoryTabButtonBase> RootTabButtonClass;

    UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
    TSubclassOf<class USFCategoryTabButtonBase> BranchTabButtonClass;

    UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
    TSubclassOf<class USFCategoryTab_Branch> BranchTabContentClass;

    UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
    TSubclassOf<class USFCategoryTab_Leaf> LeafTabContentClass;

    UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
    TSubclassOf<class USFSettingGroupWidget> SettingGroupWidgetClass;

    UPROPERTY(Config, EditAnywhere, Category = "Settings UI")
    TMap<TSubclassOf<class USFSettingDefinition>, TSubclassOf<class USFSettingEntryWidget>> SettingEntryWidgetClasses;

public:
    virtual FName GetCategoryName() const override
    {
        return FName("Plugins");
    }
};
```


