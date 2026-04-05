

# Class USFSettingEntryWidget\_Checkbox



[**ClassList**](annotated.md) **>** [**USFSettingEntryWidget\_Checkbox**](classUSFSettingEntryWidget__Checkbox.md)



_The native base class for a setting entry widget for a boolean setting, represented as a checkbox in the UI._ [More...](#detailed-description)

* `#include "UI/SettingEntries/SFSettingEntryWidget_Checkbox.h"`



Inherits the following classes: [USFSettingEntryWidget](classUSFSettingEntryWidget.md)
























## Public Attributes inherited from USFSettingEntryWidget

See [USFSettingEntryWidget](classUSFSettingEntryWidget.md)

| Type | Name |
| ---: | :--- |
|  FOnSettingEntryFocused | [**OnSettingFocused**](classUSFSettingEntryWidget.md#variable-onsettingfocused)  <br> |
































## Public Functions inherited from USFSettingEntryWidget

See [USFSettingEntryWidget](classUSFSettingEntryWidget.md)

| Type | Name |
| ---: | :--- |
|  class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* | [**GetSettingDefinition**](classUSFSettingEntryWidget.md#function-getsettingdefinition) () const<br> |
|  FGameplayTag | [**GetSettingTag**](classUSFSettingEntryWidget.md#function-getsettingtag) () const<br> |
| virtual void | [**InitializeSettingEntry**](classUSFSettingEntryWidget.md#function-initializesettingentry) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* InSettingDefinition) <br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UCheckBox &gt; | [**CheckboxWidget**](#variable-checkboxwidget)  <br> |


## Protected Attributes inherited from USFSettingEntryWidget

See [USFSettingEntryWidget](classUSFSettingEntryWidget.md)

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UCommonTextBlock &gt; | [**SettingLabel**](classUSFSettingEntryWidget.md#variable-settinglabel)  <br> |
|  FGameplayTag | [**SettingTag**](classUSFSettingEntryWidget.md#variable-settingtag)  <br> |






























## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**InitializeSettingEntry**](#function-initializesettingentry) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* InSettingDefinition) override<br> |
| virtual void | [**UpdateVisualValue\_Implementation**](#function-updatevisualvalue_implementation) (const class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) override<br> |


## Protected Functions inherited from USFSettingEntryWidget

See [USFSettingEntryWidget](classUSFSettingEntryWidget.md)

| Type | Name |
| ---: | :--- |
|  void | [**BP\_InitializeSettingEntry**](classUSFSettingEntryWidget.md#function-bp_initializesettingentry) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* InSettingDefinition) <br> |
|  void | [**OnUserChangedValue**](classUSFSettingEntryWidget.md#function-onuserchangedvalue) (class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
|  void | [**UpdateVisualValue**](classUSFSettingEntryWidget.md#function-updatevisualvalue) (const class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
| virtual void | [**UpdateVisualValue\_Implementation**](classUSFSettingEntryWidget.md#function-updatevisualvalue_implementation) (const class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
|  void | [**UpdateWidgetState**](classUSFSettingEntryWidget.md#function-updatewidgetstate) () <br> |






## Detailed Description


The native base class for a setting entry widget for a boolean setting, represented as a checkbox in the UI.


The widget blueprint implementing this class should be assigned as a value to the SettingEntryWidgetClasses map with the boolean setting definition class ([**USFSettingDefinition\_Bool**](classUSFSettingDefinition__Bool.md)) as the key in the Developer Settings at Project Settings &gt; Plugins &gt; SettingsFramework. 


    
## Protected Attributes Documentation




### variable CheckboxWidget 

```C++
TObjectPtr<class UCheckBox> USFSettingEntryWidget_Checkbox::CheckboxWidget;
```



The checkbox widget representing the boolean setting value in the UI. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>
## Protected Functions Documentation




### function InitializeSettingEntry 

```C++
virtual void USFSettingEntryWidget_Checkbox::InitializeSettingEntry (
    const class USFSettingDefinition * InSettingDefinition
) override
```



Initializes the data and display of this setting entry widget based on the assigned setting definition asset. Subclasses can override this function to hook up any setting type-specific logic or display elements, but should call the parent implementation to ensure the base functionality is executed (e.g., binding to setting value change events from the subsystem). 

**Parameters:**


* `InSettingDefinition` The setting definition asset represented by this widget.




 


        
Implements [*USFSettingEntryWidget::InitializeSettingEntry*](classUSFSettingEntryWidget.md#function-initializesettingentry)


<hr>



### function UpdateVisualValue\_Implementation 

```C++
virtual void USFSettingEntryWidget_Checkbox::UpdateVisualValue_Implementation (
    const class USFSettingValue * NewValue
) override
```



Native implementation of UpdateVisualValue, can be optionally overridden by C++ subclasses to handle setting value change events from the subsystem.


 


        
Implements [*USFSettingEntryWidget::UpdateVisualValue\_Implementation*](classUSFSettingEntryWidget.md#function-updatevisualvalue_implementation)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/SettingEntries/SFSettingEntryWidget_Checkbox.h`

