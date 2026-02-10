// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Core/SFCoreTypes.h"
#include "SFSettingEntryWidget.generated.h"

/**
 * Base class for a single setting entry (e.g., a slider or checkbox) in the settings UI.
 * Handles binding to the Subsystem events automatically.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFSettingEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	void InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);

	UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget")
	FGameplayTag GetSettingTag() const { return SettingTag; }

	UFUNCTION(BlueprintPure, Category = "SFSettingEntryWidget")
	class USFSettingDefinition* GetSettingDefinition() const;

	UPROPERTY(BlueprintAssignable, Category = "SFSettingEntryWidget")
	FOnSettingEntryFocused OnSettingFocused;
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "SFSettingEntryWidget", meta = (DisplayName = "Initialize Setting Entry"))
	void BP_InitializeSettingEntry(const class USFSettingDefinition* InSettingDefinition);

	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	UPROPERTY(BlueprintReadOnly, Category = "SFSettingEntryWidget")
	FGameplayTag SettingTag;
};
