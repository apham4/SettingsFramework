// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SFSettingEntryWidget.generated.h"

/**
 * Base class for a single setting entry (e.g., a slider or checkbox) in the settings UI.
 * Handles binding to the Subsystem events automatically.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSettingEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget")
	TObjectPtr<class USFSettingDefinition> SettingDefinition;
};
