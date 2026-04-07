// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Components/SFCategoryTabBase.h"
#include "GameplayTagContainer.h"
#include "SFCategoryTab_Leaf.generated.h"

/**
 * @brief The native base class for the content widget representing a leaf-type setting category (contains setting entries).
 *
 * The native base class for the content widget representing a leaf-type setting category (contains setting entries).
 * This is a subclass of USFCategoryTabBase. It is added to USFSettingsScreen's TabContentSwitcher for leaf-type categories.
 * 
 * The widget blueprint implementing this class should be assigned to the LeafTabContentClass in the Developer Settings at Project Settings > Plugins > SettingsFramework.
 * @note @abstract @blueprinttype @blueprintable
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class SETTINGSFRAMEWORK_API USFCategoryTab_Leaf : public USFCategoryTabBase
{
	GENERATED_BODY()

#pragma region Initialization
public:
	/**
	* @inheritdoc
	*/
	virtual void InitializeCategoryDisplay() override;

protected:
	/** @cond */
	UFUNCTION()
	void HandleSettingEntryFocused(const FGameplayTag& SettingTag);

	void CreateSettingEntryAndAddToGroup(const class USFSettingDefinition* SettingDefinition, class USFSettingGroupWidget* GroupWidget);

	bool bInitialized;
	/** @endcond */
#pragma endregion

#pragma region Setting Display
protected:
	/**
	* The container widget for setting groups within this category. Setting entry widgets are added to this container through their group widgets.
	* @note @bro @bw
	*/
	UPROPERTY(BlueprintReadOnly, Category = "SFCategoryTab_Leaf", meta = (BindWidget))
	TObjectPtr<class UPanelWidget> SettingGroupContainer;

	/**
	* The transient mapping of setting Gameplay Tags to their corresponding setting entry widgets, used for quick lookup.
	* @note @t
	*/
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<class USFSettingEntryWidget>> EntryWidgetMap;

	/**
	* Called when a USFSettingGroupWidget is added to SettingGroupContainer. To be implemented in Blueprint to add any additional styling like padding and such.
	* @param WidgetAsPanelSlot The added group widget as a panel slot, used for styling.
	* @note @bie
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "SFCategoryTab_Leaf")
	void OnGroupWidgetAdded(class UPanelSlot* WidgetAsPanelSlot, class USFSettingGroupWidget* WidgetAsGroupWidget);
#pragma endregion

#pragma region CommonUI Navigation
	/** @cond */
public:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;

protected:
	TWeakObjectPtr<class USFSettingEntryWidget> LastFocusedEntry;
	/** @endcond */
#pragma endregion
};
