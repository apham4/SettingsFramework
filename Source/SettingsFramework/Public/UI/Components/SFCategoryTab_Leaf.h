// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UI/Components/SFCategoryTabBase.h"
#include "SFCategoryTab_Leaf.generated.h"

/**
 * A tab content widget representing a leaf-type setting category that contains setting entries.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTab_Leaf : public USFCategoryTabBase
{
	GENERATED_BODY()

#pragma region Initialization
public:
	// Lazy loading on activated
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

	// Implement in Blueprint: add any additional styling like padding and such.
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
