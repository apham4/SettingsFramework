

# Class USFSettingGroupWidget



[**ClassList**](annotated.md) **>** [**USFSettingGroupWidget**](classUSFSettingGroupWidget.md)



_The native base class for the widget displaying a setting group._ [More...](#detailed-description)

* `#include "UI/Components/SFSettingGroupWidget.h"`



Inherits the following classes: UCommonUserWidget


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddSettingEntry**](#function-addsettingentry) (class [**USFSettingEntryWidget**](classUSFSettingEntryWidget.md) \* EntryWidget) <br> |
|  void | [**DisplaySettingGroupInfo**](#function-displaysettinggroupinfo) (const struct [**FSFSettingGroup**](structFSFSettingGroup.md) & SettingGroup) <br> |
|  class [**USFSettingEntryWidget**](classUSFSettingEntryWidget.md) \* | [**GetFirstValidSettingEntry**](#function-getfirstvalidsettingentry) () const<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UPanelWidget &gt; | [**SettingEntryContainer**](#variable-settingentrycontainer)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**OnSettingEntryAdded**](#function-onsettingentryadded) (class UPanelSlot \* EntryAsPanelSlot, class [**USFSettingEntryWidget**](classUSFSettingEntryWidget.md) \* EntryAsSettingWidget) <br> |




## Detailed Description


The native base class for the widget displaying a setting group.


The widget blueprint implementing this class should be assigned to the SettingGroupWidgetClass in the Developer Settings at Project Settings &gt; Plugins &gt; SettingsFramework. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` 





    
## Public Functions Documentation




### function AddSettingEntry 

```C++
void USFSettingGroupWidget::AddSettingEntry (
    class USFSettingEntryWidget * EntryWidget
) 
```



Add an initialized setting entry widget to be displayed in this group. This is called by [**USFCategoryTab\_Leaf**](classUSFCategoryTab__Leaf.md) when initializing the display of its setting entries. 

**Parameters:**


* `EntryWidget` The initialized setting entry widget to be added to this group. 




        

<hr>



### function DisplaySettingGroupInfo 

```C++
void USFSettingGroupWidget::DisplaySettingGroupInfo (
    const struct FSFSettingGroup & SettingGroup
) 
```



Display the metadata of the associated setting group. If the given struct is empty, clear the display. 

**Parameters:**


* `SettingGroup` The struct containing the metadata of the associated setting group. 



**Note:**

`BlueprintImplementableEvent` 





        

<hr>



### function GetFirstValidSettingEntry 

```C++
class USFSettingEntryWidget * USFSettingGroupWidget::GetFirstValidSettingEntry () const
```



Get the first setting entry widget in this group that is valid for navigation (visible and enabled). Used for setting initial focus when displaying a leaf category tab. 

**Returns:**

The first setting entry widget in this group that is valid for navigation, nullptr if none is found. 





        

<hr>
## Protected Attributes Documentation




### variable SettingEntryContainer 

```C++
TObjectPtr<class UPanelWidget> USFSettingGroupWidget::SettingEntryContainer;
```



The container widget for setting entries within this group. Setting entry widgets are added to this container when initializing the display of a leaf category tab. 


        

<hr>
## Protected Functions Documentation




### function OnSettingEntryAdded 

```C++
void USFSettingGroupWidget::OnSettingEntryAdded (
    class UPanelSlot * EntryAsPanelSlot,
    class USFSettingEntryWidget * EntryAsSettingWidget
) 
```



Called when a setting entry widget is added to SettingEntryContainer. To be implemented in Blueprint to add any additional styling like padding and such. 

**Parameters:**


* `EntryAsPanelSlot` The added setting entry widget as a panel slot, used for styling. 
* `EntryAsSettingWidget` The added setting entry widget as a setting entry widget, used for any additional logic that may be needed. 



**Note:**

`BlueprintImplementableEvent` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/Components/SFSettingGroupWidget.h`

