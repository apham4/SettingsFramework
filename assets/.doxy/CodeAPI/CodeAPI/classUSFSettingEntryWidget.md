

# Class USFSettingEntryWidget



[**ClassList**](annotated.md) **>** [**USFSettingEntryWidget**](classUSFSettingEntryWidget.md)



_The native base class for a single setting entry in the settings UI._ [More...](#detailed-description)

* `#include "UI/SettingEntries/SFSettingEntryWidget.h"`



Inherits the following classes: UCommonUserWidget


Inherited by the following classes: [USFSettingEntryWidget\_Checkbox](classUSFSettingEntryWidget__Checkbox.md),  [USFSettingEntryWidget\_Keybind](classUSFSettingEntryWidget__Keybind.md),  [USFSettingEntryWidget\_Rotator](classUSFSettingEntryWidget__Rotator.md),  [USFSettingEntryWidget\_Slider](classUSFSettingEntryWidget__Slider.md)
















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FOnSettingEntryFocused | [**OnSettingFocused**](#variable-onsettingfocused)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* | [**GetSettingDefinition**](#function-getsettingdefinition) () const<br> |
|  FGameplayTag | [**GetSettingTag**](#function-getsettingtag) () const<br> |
| virtual void | [**InitializeSettingEntry**](#function-initializesettingentry) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* InSettingDefinition) <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UCommonTextBlock &gt; | [**SettingLabel**](#variable-settinglabel)  <br> |
|  FGameplayTag | [**SettingTag**](#variable-settingtag)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**BP\_InitializeSettingEntry**](#function-bp_initializesettingentry) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* InSettingDefinition) <br> |
|  void | [**OnUserChangedValue**](#function-onuserchangedvalue) (class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
|  void | [**UpdateVisualValue**](#function-updatevisualvalue) (const class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
| virtual void | [**UpdateVisualValue\_Implementation**](#function-updatevisualvalue_implementation) (const class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
|  void | [**UpdateWidgetState**](#function-updatewidgetstate) () <br> |




## Detailed Description


The native base class for a single setting entry in the settings UI. This widget represents and displays a single setting definition from the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md), allowing the player to view and change the setting value. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` 





    
## Public Attributes Documentation




### variable OnSettingFocused 

```C++
FOnSettingEntryFocused USFSettingEntryWidget::OnSettingFocused;
```



Event fired when the setting entry is hovered/focused in the UI, used for bubbling up the focused setting's tag to the settings screen widget to display its info. 

**Note:**

`BlueprintAssignable` 





        

<hr>
## Public Functions Documentation




### function GetSettingDefinition 

```C++
class USFSettingDefinition * USFSettingEntryWidget::GetSettingDefinition () const
```



Get the setting definition asset represented by this entry widget. 

**Returns:**

The setting definition asset represented by this entry widget. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetSettingTag 

```C++
inline FGameplayTag USFSettingEntryWidget::GetSettingTag () const
```



Get the Gameplay Tag of the setting represented by this entry widget. 

**Returns:**

The Gameplay Tag of the setting represented by this entry widget. 




**Note:**

`BlueprintPure` 





        

<hr>



### function InitializeSettingEntry 

```C++
virtual void USFSettingEntryWidget::InitializeSettingEntry (
    const class USFSettingDefinition * InSettingDefinition
) 
```



Initializes the data and display of this setting entry widget based on the assigned setting definition asset. Subclasses can override this function to hook up any setting type-specific logic or display elements, but should call the parent implementation to ensure the base functionality is executed (e.g., binding to setting value change events from the subsystem). 

**Parameters:**


* `InSettingDefinition` The setting definition asset represented by this widget. 




        

<hr>
## Protected Attributes Documentation




### variable SettingLabel 

```C++
TObjectPtr<class UCommonTextBlock> USFSettingEntryWidget::SettingLabel;
```



Optional text block widget displaying the setting name/label. 

**Note:**

`BlueprintReadOnly` `BindWidgetOptional` 





        

<hr>



### variable SettingTag 

```C++
FGameplayTag USFSettingEntryWidget::SettingTag;
```



The Gameplay Tag of the setting represented by this entry widget, used to communication with the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md). 

**Note:**

`BlueprintReadOnly` 





        

<hr>
## Protected Functions Documentation




### function BP\_InitializeSettingEntry 

```C++
void USFSettingEntryWidget::BP_InitializeSettingEntry (
    const class USFSettingDefinition * InSettingDefinition
) 
```



Initializes the display of this setting entry widget based on the assigned setting definition asset, called after the native InitializeSettingEntry to allow for Blueprint implementations to run after the base logic. 

**Parameters:**


* `InSettingDefinition` The setting definition asset represented by this widget. 



**Note:**

`BlueprintImplementableEvent` 





        

<hr>



### function OnUserChangedValue 

```C++
void USFSettingEntryWidget::OnUserChangedValue (
    class USFSettingValue * NewValue
) 
```



Requests the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) to change the value of the setting represented by this entry widget. This should be called when the user interacts with the entry widget to change the setting value (e.g., moving a slider, checking/unchecking a checkbox, etc.). 

**Parameters:**


* `NewValue` The new value to set for the setting, represented as a [**USFSettingValue**](classUSFSettingValue.md) object. 



**Note:**

`BlueprintCallable` 





        

<hr>



### function UpdateVisualValue 

```C++
void USFSettingEntryWidget::UpdateVisualValue (
    const class USFSettingValue * NewValue
) 
```



Update the visual representation of the setting value (e.g., slider position, checkbox state) based on the given value. This is called in response to setting value change events from the subsystem to ensure the UI stays in sync with the actual setting values. When overriding in Blueprint, call the parent implementation if the native superclass has one. 

**Note:**

`BlueprintNativeEvent` 





        

<hr>



### function UpdateVisualValue\_Implementation 

```C++
inline virtual void USFSettingEntryWidget::UpdateVisualValue_Implementation (
    const class USFSettingValue * NewValue
) 
```



Native implementation of UpdateVisualValue, can be optionally overridden by C++ subclasses to handle setting value change events from the subsystem. 


        

<hr>



### function UpdateWidgetState 

```C++
void USFSettingEntryWidget::UpdateWidgetState () 
```



Internal function to update the visibility and editability of the widget based on the evaluation of the associated setting from the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md). 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/SettingEntries/SFSettingEntryWidget.h`

