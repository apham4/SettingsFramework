

# Class USFSettingEntryWidget\_Rotator



[**ClassList**](annotated.md) **>** [**USFSettingEntryWidget\_Rotator**](classUSFSettingEntryWidget__Rotator.md)



_The native base class for a setting entry widget for a discrete setting, represented as a rotator in the UI._ [More...](#detailed-description)

* `#include "UI/SettingEntries/SFSettingEntryWidget_Rotator.h"`



Inherits the following classes: [USFSettingEntryWidget](classUSFSettingEntryWidget.md)
























## Public Attributes inherited from USFSettingEntryWidget

See [USFSettingEntryWidget](classUSFSettingEntryWidget.md)

| Type | Name |
| ---: | :--- |
|  FOnSettingEntryFocused | [**OnSettingFocused**](classUSFSettingEntryWidget.md#variable-onsettingfocused)  <br> |






























## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**RefreshOptions**](#function-refreshoptions) () <br> |


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
|  TArray&lt; struct [**FSFSettingOption**](structFSFSettingOption.md) &gt; | [**Options**](#variable-options)  <br> |
|  TObjectPtr&lt; class UCommonRotator &gt; | [**RotatorWidget**](#variable-rotatorwidget)  <br> |


## Protected Attributes inherited from USFSettingEntryWidget

See [USFSettingEntryWidget](classUSFSettingEntryWidget.md)

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UCommonTextBlock &gt; | [**SettingLabel**](classUSFSettingEntryWidget.md#variable-settinglabel)  <br> |
|  FGameplayTag | [**SettingTag**](classUSFSettingEntryWidget.md#variable-settingtag)  <br> |






























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**CheckForDeterminantSettings**](#function-checkfordeterminantsettings) (const FGameplayTag & ChangedSettingTag, class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
| virtual void | [**InitializeSettingEntry**](#function-initializesettingentry) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* InSettingDefinition) override<br> |
|  void | [**PopulateOptions**](#function-populateoptions) (const TArray&lt; struct [**FSFSettingOption**](structFSFSettingOption.md) &gt; & SettingOptions) <br> |
|  bool | [**SelectOptionByValue**](#function-selectoptionbyvalue) (const class [**USFSettingValue**](classUSFSettingValue.md) \* Value) <br> |
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


The native base class for a setting entry widget for a discrete setting, represented as a rotator in the UI.


The widget blueprint implementing this class should be assigned as a value to the SettingEntryWidgetClasses map with the discrete setting definition class ([**USFSettingDefinition\_Discrete**](classUSFSettingDefinition__Discrete.md)) as the key in the Developer Settings at Project Settings &gt; Plugins &gt; SettingsFramework. 


    
## Public Functions Documentation




### function RefreshOptions 

```C++
void USFSettingEntryWidget_Rotator::RefreshOptions () 
```



Re-evaluate and repopulate the available options. Intended for discrete settings with dynamic options at runtime. 

**Note:**

`BlueprintCallable` 





        

<hr>
## Protected Attributes Documentation




### variable Options 

```C++
TArray<struct FSFSettingOption> USFSettingEntryWidget_Rotator::Options;
```



The transient list of options currently displayed by the rotator widget. This is to keep track of the full [**FSFSettingOption**](structFSFSettingOption.md) data structs since the rotator widget only stores the display text and index int. 

**Note:**

`Transient` 





        

<hr>



### variable RotatorWidget 

```C++
TObjectPtr<class UCommonRotator> USFSettingEntryWidget_Rotator::RotatorWidget;
```



The rotator widget representing the discrete setting value in the UI. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>
## Protected Functions Documentation




### function CheckForDeterminantSettings 

```C++
void USFSettingEntryWidget_Rotator::CheckForDeterminantSettings (
    const FGameplayTag & ChangedSettingTag,
    class USFSettingValue * NewValue
) 
```



Intended for discrete settings with dynamic options at runtime. Refresh the available options when there is a value change from a determinant setting (specified in this discrete setting's definition asset). 


        

<hr>



### function InitializeSettingEntry 

```C++
virtual void USFSettingEntryWidget_Rotator::InitializeSettingEntry (
    const class USFSettingDefinition * InSettingDefinition
) override
```



Initializes the data and display of this setting entry widget based on the assigned setting definition asset. Subclasses can override this function to hook up any setting type-specific logic or display elements, but should call the parent implementation to ensure the base functionality is executed (e.g., binding to setting value change events from the subsystem). 

**Parameters:**


* `InSettingDefinition` The setting definition asset represented by this widget.




 


        
Implements [*USFSettingEntryWidget::InitializeSettingEntry*](classUSFSettingEntryWidget.md#function-initializesettingentry)


<hr>



### function PopulateOptions 

```C++
void USFSettingEntryWidget_Rotator::PopulateOptions (
    const TArray< struct FSFSettingOption > & SettingOptions
) 
```



Populate the rotator widget with the provided list of setting options. This will also update the internal Options array to keep track of the full data for each option. 

**Parameters:**


* `SettingOptions` The list of setting options to populate the rotator widget with. 




        

<hr>



### function SelectOptionByValue 

```C++
bool USFSettingEntryWidget_Rotator::SelectOptionByValue (
    const class USFSettingValue * Value
) 
```



Set the selected option in the rotator widget based on the provided setting value. 

**Parameters:**


* `Value` The setting value to match against the available options to select the appropriate one in the rotator widget. 



**Returns:**

True if a matching option was found and selected, false otherwise. 





        

<hr>



### function UpdateVisualValue\_Implementation 

```C++
virtual void USFSettingEntryWidget_Rotator::UpdateVisualValue_Implementation (
    const class USFSettingValue * NewValue
) override
```



Native implementation of UpdateVisualValue, can be optionally overridden by C++ subclasses to handle setting value change events from the subsystem.


 


        
Implements [*USFSettingEntryWidget::UpdateVisualValue\_Implementation*](classUSFSettingEntryWidget.md#function-updatevisualvalue_implementation)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/SettingEntries/SFSettingEntryWidget_Rotator.h`

