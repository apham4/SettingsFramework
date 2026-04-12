

# Class USFSettingEntryWidget\_Keybind



[**ClassList**](annotated.md) **>** [**USFSettingEntryWidget\_Keybind**](classUSFSettingEntryWidget__Keybind.md)



_The native base class for a setting entry widget for a key bind setting, represented as buttons that listen for the next key press in the UI._ [More...](#detailed-description)

* `#include "UI/SettingEntries/SFSettingEntryWidget_Keybind.h"`



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
|  [**FSFKeybindValueData**](structFSFKeybindValueData.md) | [**CurrentKeybindData**](#variable-currentkeybinddata)  <br> |
|  [**ESFKeybindSlot**](SFSettingEntryWidget__Keybind_8h.md#enum-esfkeybindslot) | [**CurrentListeningSlot**](#variable-currentlisteningslot)   = `ESFKeybindSlot::None`<br> |
|  TObjectPtr&lt; class UCommonButtonBase &gt; | [**GamepadButton**](#variable-gamepadbutton)  <br> |
|  TObjectPtr&lt; class UCommonButtonBase &gt; | [**KBMPrimaryButton**](#variable-kbmprimarybutton)  <br> |
|  TObjectPtr&lt; class UCommonButtonBase &gt; | [**KBMSecondaryButton**](#variable-kbmsecondarybutton)  <br> |


## Protected Attributes inherited from USFSettingEntryWidget

See [USFSettingEntryWidget](classUSFSettingEntryWidget.md)

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UCommonTextBlock &gt; | [**SettingLabel**](classUSFSettingEntryWidget.md#variable-settinglabel)  <br> |
|  FGameplayTag | [**SettingTag**](classUSFSettingEntryWidget.md#variable-settingtag)  <br> |






























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**ApplyNewKeybind**](#function-applynewkeybind) (FKey NewKey) <br> |
|  void | [**CancelListening**](#function-cancellistening) () <br> |
|  void | [**ClearSlot**](#function-clearslot) ([**ESFKeybindSlot**](SFSettingEntryWidget__Keybind_8h.md#enum-esfkeybindslot) SlotToClear) <br> |
| virtual void | [**InitializeSettingEntry**](#function-initializesettingentry) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* InSettingDefinition) override<br> |
|  void | [**SetSlotText**](#function-setslottext) ([**ESFKeybindSlot**](SFSettingEntryWidget__Keybind_8h.md#enum-esfkeybindslot) SlotToSet, FKey Key, bool bIsListening) <br> |
| virtual void | [**SetSlotText\_Implementation**](#function-setslottext_implementation) ([**ESFKeybindSlot**](SFSettingEntryWidget__Keybind_8h.md#enum-esfkeybindslot) SlotToSet, FKey Key, bool bIsListening) <br> |
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


Setting entry widget for keybind settings, represented as buttons that listens for the next key press in the UI. 


The native base class for a setting entry widget for a key bind setting, represented as buttons that listen for the next key press in the UI.


The widget blueprint implementing this class should be assigned as a value to the SettingEntryWidgetClasses map with the key bind setting definition class ([**USFSettingDefinition\_Key**](classUSFSettingDefinition__Key.md)) as the key in the Developer Settings at Project Settings &gt; Plugins &gt; SettingsFramework. 


    
## Protected Attributes Documentation




### variable CurrentKeybindData 

```C++
FSFKeybindValueData USFSettingEntryWidget_Keybind::CurrentKeybindData;
```



The cached current keybind data for this setting entry, used to compare against new input and determine whether the value has actually changed and whether to apply the change to the subsystem. 


        

<hr>



### variable CurrentListeningSlot 

```C++
ESFKeybindSlot USFSettingEntryWidget_Keybind::CurrentListeningSlot;
```



Transient variable to track which keybind slot is currently listening for input for rebinding. 


        

<hr>



### variable GamepadButton 

```C++
TObjectPtr<class UCommonButtonBase> USFSettingEntryWidget_Keybind::GamepadButton;
```



Button widget for displaying and changing the gamepad keybind. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>



### variable KBMPrimaryButton 

```C++
TObjectPtr<class UCommonButtonBase> USFSettingEntryWidget_Keybind::KBMPrimaryButton;
```



Button widget for displaying and changing the primary KBM keybind. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>



### variable KBMSecondaryButton 

```C++
TObjectPtr<class UCommonButtonBase> USFSettingEntryWidget_Keybind::KBMSecondaryButton;
```



Button widget for displaying and changing the secondary KBM keybind. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>
## Protected Functions Documentation




### function ApplyNewKeybind 

```C++
void USFSettingEntryWidget_Keybind::ApplyNewKeybind (
    FKey NewKey
) 
```



Apply the given key as the new keybind for the currently listening slot (specified by CurrentListeningSlot) and update it in the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) instance. 

**Parameters:**


* `NewKey` The new keybind to apply for the currently listening slot. 




        

<hr>



### function CancelListening 

```C++
void USFSettingEntryWidget_Keybind::CancelListening () 
```



If the widget is in listening state, cancel it and update the button display to show the current keybind. 


        

<hr>



### function ClearSlot 

```C++
void USFSettingEntryWidget_Keybind::ClearSlot (
    ESFKeybindSlot SlotToClear
) 
```



Set the specified slot to have no keybind, update it in the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) instance, and update the button display accordingly. 

**Parameters:**


* `SlotToClear` The keybind slot to clear the keybind for. 




        

<hr>



### function InitializeSettingEntry 

```C++
virtual void USFSettingEntryWidget_Keybind::InitializeSettingEntry (
    const class USFSettingDefinition * InSettingDefinition
) override
```



Initializes the data and display of this setting entry widget based on the assigned setting definition asset. Subclasses can override this function to hook up any setting type-specific logic or display elements, but should call the parent implementation to ensure the base functionality is executed (e.g., binding to setting value change events from the subsystem). 

**Parameters:**


* `InSettingDefinition` The setting definition asset represented by this widget.




 


        
Implements [*USFSettingEntryWidget::InitializeSettingEntry*](classUSFSettingEntryWidget.md#function-initializesettingentry)


<hr>



### function SetSlotText 

```C++
void USFSettingEntryWidget_Keybind::SetSlotText (
    ESFKeybindSlot SlotToSet,
    FKey Key,
    bool bIsListening
) 
```



Cosmetically display the given key in the button widget for the specified slot, and update the display to indicate that the widget is currently listening for input if bIsListening is true. 

**Parameters:**


* `SlotToSet` The keybind slot for which to set the button text. 
* `Key` The key to display in the button widget for the specified slot. 
* `bIsListening` Whether the button widget for the specified slot should display as currently listening for input. 




        

<hr>



### function SetSlotText\_Implementation 

```C++
inline virtual void USFSettingEntryWidget_Keybind::SetSlotText_Implementation (
    ESFKeybindSlot SlotToSet,
    FKey Key,
    bool bIsListening
) 
```



Native implementation of SetSlotText, can be optionally overridden by C++ subclasses. 


        

<hr>



### function UpdateVisualValue\_Implementation 

```C++
virtual void USFSettingEntryWidget_Keybind::UpdateVisualValue_Implementation (
    const class USFSettingValue * NewValue
) override
```



Native implementation of UpdateVisualValue, can be optionally overridden by C++ subclasses to handle setting value change events from the subsystem.


 


        
Implements [*USFSettingEntryWidget::UpdateVisualValue\_Implementation*](classUSFSettingEntryWidget.md#function-updatevisualvalue_implementation)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/SettingEntries/SFSettingEntryWidget_Keybind.h`

