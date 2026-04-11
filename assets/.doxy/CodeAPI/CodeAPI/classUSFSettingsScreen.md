

# Class USFSettingsScreen



[**ClassList**](annotated.md) **>** [**USFSettingsScreen**](classUSFSettingsScreen.md)



_The native base class for the outer-most widget of the settings screen UI. A widget blueprint subclass of this is to be added to a project's CommonUI widget stack._ [More...](#detailed-description)

* `#include "UI/SFSettingsScreen.h"`



Inherits the following classes: UCommonActivatableWidget










































## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UCommonTabListWidgetBase &gt; | [**CategoryTabList**](#variable-categorytablist)  <br> |
|  TObjectPtr&lt; class UInputAction &gt; | [**ResetToDefaultAction**](#variable-resettodefaultaction)  <br> |
|  TObjectPtr&lt; class UInputAction &gt; | [**RevertAction**](#variable-revertaction)  <br> |
|  TObjectPtr&lt; class UInputAction &gt; | [**SaveAction**](#variable-saveaction)  <br> |
|  TObjectPtr&lt; class [**USFSettingInfoDisplay**](classUSFSettingInfoDisplay.md) &gt; | [**SettingInfoDisplay**](#variable-settinginfodisplay)  <br> |
|  TObjectPtr&lt; class UCommonActivatableWidgetSwitcher &gt; | [**TabContentSwitcher**](#variable-tabcontentswitcher)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**InitializeSettingsScreen**](#function-initializesettingsscreen) () <br> |
|  void | [**ResetSettingsToDefault**](#function-resetsettingstodefault) () <br> |
|  void | [**RevertSettings**](#function-revertsettings) () <br> |
|  void | [**SaveSettings**](#function-savesettings) () <br> |




## Detailed Description


On initialization, this widget queries the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) instance for setting categories and definitions, constructs and populates itself with the appropriate tabs and setting widgets.


The skeletal settings screen UI in Settings Framework only allows for one level of category nesting, meaning only root categories are allowed to be branch-type categories (containing sub-categories). Any branch-type categories under that level are ignored when constructing the UI.


This widget also requests the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) instance to perform actions such as saving, reverting, or resetting settings when initiated by the player from the UI. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` 





    
## Protected Attributes Documentation




### variable CategoryTabList 

```C++
TObjectPtr<class UCommonTabListWidgetBase> USFSettingsScreen::CategoryTabList;
```



The Common Tab List widget containing tab buttons representing the root setting categories. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>



### variable ResetToDefaultAction 

```C++
TObjectPtr<class UInputAction> USFSettingsScreen::ResetToDefaultAction;
```



The optional EnhancedInput action to automatically call ResetSettingsToDefault. Requires Enhanced Input support to be enabled in Common Input settings. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable RevertAction 

```C++
TObjectPtr<class UInputAction> USFSettingsScreen::RevertAction;
```



The optional EnhancedInput action to automatically call RevertSettings. Requires Enhanced Input support to be enabled in Common Input settings. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable SaveAction 

```C++
TObjectPtr<class UInputAction> USFSettingsScreen::SaveAction;
```



The optional EnhancedInput action to automatically call SaveSettings. Requires Enhanced Input support to be enabled in Common Input settings. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable SettingInfoDisplay 

```C++
TObjectPtr<class USFSettingInfoDisplay> USFSettingsScreen::SettingInfoDisplay;
```



The widget displaying detailed information about the currently focused setting, such as its display name, description, etc. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>



### variable TabContentSwitcher 

```C++
TObjectPtr<class UCommonActivatableWidgetSwitcher> USFSettingsScreen::TabContentSwitcher;
```



The Common Activatable Widget Switcher containing the content for each root setting category, switched by the CategoryTabList. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>
## Protected Functions Documentation




### function InitializeSettingsScreen 

```C++
void USFSettingsScreen::InitializeSettingsScreen () 
```



Initializes the settings screen by querying the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) for setting categories and definitions, constructing and populating tabs and setting widgets, and binding to subsystem events. Called on widget activation to allow for lazy loading. 


        

<hr>



### function ResetSettingsToDefault 

```C++
void USFSettingsScreen::ResetSettingsToDefault () 
```



Requests the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) to reset all setting values to their default values. Can be called manually or bound to ResetToDefaultAction. 

**Note:**

`BlueprintPure` 





        

<hr>



### function RevertSettings 

```C++
void USFSettingsScreen::RevertSettings () 
```



Requests the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) to revert all setting values to their saved values. Can be called manually or bound to RevertAction. 

**Note:**

`BlueprintPure` 





        

<hr>



### function SaveSettings 

```C++
void USFSettingsScreen::SaveSettings () 
```



Requests the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) to save all setting values. Can be called manually or bound to SaveAction. 

**Note:**

`BlueprintPure` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/SFSettingsScreen.h`

