

# Class USFCategoryTab\_Leaf



[**ClassList**](annotated.md) **>** [**USFCategoryTab\_Leaf**](classUSFCategoryTab__Leaf.md)



_The native base class for the content widget representing a leaf-type setting category (contains setting entries)._ [More...](#detailed-description)

* `#include "UI/Components/SFCategoryTab_Leaf.h"`



Inherits the following classes: [USFCategoryTabBase](classUSFCategoryTabBase.md)
























## Public Attributes inherited from USFCategoryTabBase

See [USFCategoryTabBase](classUSFCategoryTabBase.md)

| Type | Name |
| ---: | :--- |
|  FOnSettingEntryFocused | [**OnSettingFocused**](classUSFCategoryTabBase.md#variable-onsettingfocused)  <br> |






























## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**InitializeCategoryDisplay**](#function-initializecategorydisplay) () override<br> |


## Public Functions inherited from USFCategoryTabBase

See [USFCategoryTabBase](classUSFCategoryTabBase.md)

| Type | Name |
| ---: | :--- |
|  const class [**USFSettingCategory**](classUSFSettingCategory.md) \* | [**GetSettingCategory**](classUSFCategoryTabBase.md#function-getsettingcategory) () const<br> |
| virtual void | [**InitializeCategoryDisplay**](classUSFCategoryTabBase.md#function-initializecategorydisplay) () <br> |
|  void | [**SetCategory**](classUSFCategoryTabBase.md#function-setcategory) (class [**USFSettingCategory**](classUSFSettingCategory.md) \* InSettingCategory) <br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TMap&lt; FGameplayTag, TObjectPtr&lt; class [**USFSettingEntryWidget**](classUSFSettingEntryWidget.md) &gt; &gt; | [**EntryWidgetMap**](#variable-entrywidgetmap)  <br> |
|  TObjectPtr&lt; class UPanelWidget &gt; | [**SettingGroupContainer**](#variable-settinggroupcontainer)  <br> |


## Protected Attributes inherited from USFCategoryTabBase

See [USFCategoryTabBase](classUSFCategoryTabBase.md)

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class [**USFSettingCategory**](classUSFSettingCategory.md) &gt; | [**SettingCategory**](classUSFCategoryTabBase.md#variable-settingcategory)  <br> |






























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**OnGroupWidgetAdded**](#function-ongroupwidgetadded) (class UPanelSlot \* WidgetAsPanelSlot, class [**USFSettingGroupWidget**](classUSFSettingGroupWidget.md) \* WidgetAsGroupWidget) <br> |








## Detailed Description


The native base class for the content widget representing a leaf-type setting category (contains setting entries). This is a subclass of [**USFCategoryTabBase**](classUSFCategoryTabBase.md). It is added to [**USFSettingsScreen**](classUSFSettingsScreen.md)'s TabContentSwitcher for leaf-type categories.


The widget blueprint implementing this class should be assigned to the LeafTabContentClass in the Developer Settings at Project Settings &gt; Plugins &gt; SettingsFramework. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` 





    
## Public Functions Documentation




### function InitializeCategoryDisplay 

```C++
virtual void USFCategoryTab_Leaf::InitializeCategoryDisplay () override
```



Populate the widget with the data from the category asset. This is called when the widget is displayed for the first time to allow for lazy loading.


 


        
Implements [*USFCategoryTabBase::InitializeCategoryDisplay*](classUSFCategoryTabBase.md#function-initializecategorydisplay)


<hr>
## Protected Attributes Documentation




### variable EntryWidgetMap 

```C++
TMap<FGameplayTag, TObjectPtr<class USFSettingEntryWidget> > USFCategoryTab_Leaf::EntryWidgetMap;
```



The transient mapping of setting Gameplay Tags to their corresponding setting entry widgets, used for quick lookup. 

**Note:**

`Transient` 





        

<hr>



### variable SettingGroupContainer 

```C++
TObjectPtr<class UPanelWidget> USFCategoryTab_Leaf::SettingGroupContainer;
```



The container widget for setting groups within this category. Setting entry widgets are added to this container through their group widgets. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>
## Protected Functions Documentation




### function OnGroupWidgetAdded 

```C++
void USFCategoryTab_Leaf::OnGroupWidgetAdded (
    class UPanelSlot * WidgetAsPanelSlot,
    class USFSettingGroupWidget * WidgetAsGroupWidget
) 
```



Called when a [**USFSettingGroupWidget**](classUSFSettingGroupWidget.md) is added to SettingGroupContainer. To be implemented in Blueprint to add any additional styling like padding and such. 

**Parameters:**


* `WidgetAsPanelSlot` The added group widget as a panel slot, used for styling. 



**Note:**

`BlueprintImplementableEvent` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/Components/SFCategoryTab_Leaf.h`

