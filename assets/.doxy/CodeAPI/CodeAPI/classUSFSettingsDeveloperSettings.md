

# Class USFSettingsDeveloperSettings



[**ClassList**](annotated.md) **>** [**USFSettingsDeveloperSettings**](classUSFSettingsDeveloperSettings.md)



_Developer settings to define project-wide configurations for the SettingsFramework plugin._ [More...](#detailed-description)

* `#include "SFSettingsDeveloperSettings.h"`



Inherits the following classes: UDeveloperSettings


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  TSubclassOf&lt; class [**USFCategoryTabButtonBase**](classUSFCategoryTabButtonBase.md) &gt; | [**BranchTabButtonClass**](#variable-branchtabbuttonclass)  <br> |
|  TSubclassOf&lt; class [**USFCategoryTab\_Branch**](classUSFCategoryTab__Branch.md) &gt; | [**BranchTabContentClass**](#variable-branchtabcontentclass)  <br> |
|  [**ESFKeybindCollisionResolution**](SFCoreTypes_8h.md#enum-esfkeybindcollisionresolution) | [**DefaultKeybindCollisionResolution**](#variable-defaultkeybindcollisionresolution)   = `ESFKeybindCollisionResolution::Overwrite`<br> |
|  TSubclassOf&lt; class [**USFCategoryTab\_Leaf**](classUSFCategoryTab__Leaf.md) &gt; | [**LeafTabContentClass**](#variable-leaftabcontentclass)  <br> |
|  int32 | [**MaxUpdateDepth**](#variable-maxupdatedepth)   = `10`<br> |
|  TSubclassOf&lt; class [**USFCategoryTabButtonBase**](classUSFCategoryTabButtonBase.md) &gt; | [**RootTabButtonClass**](#variable-roottabbuttonclass)  <br> |
|  FString | [**SaveGameSlotName**](#variable-savegameslotname)   = `TEXT("SF\_SaveSlot")`<br> |
|  TMap&lt; TSubclassOf&lt; class [**USFSettingDefinition**](classUSFSettingDefinition.md) &gt;, TSubclassOf&lt; class [**USFSettingEntryWidget**](classUSFSettingEntryWidget.md) &gt; &gt; | [**SettingEntryWidgetClasses**](#variable-settingentrywidgetclasses)  <br> |
|  TSubclassOf&lt; class [**USFSettingGroupWidget**](classUSFSettingGroupWidget.md) &gt; | [**SettingGroupWidgetClass**](#variable-settinggroupwidgetclass)  <br> |
|  TSoftObjectPtr&lt; class [**USFSettingsRegistry**](classUSFSettingsRegistry.md) &gt; | [**SettingsRegistry**](#variable-settingsregistry)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
| virtual FName | [**GetCategoryName**](#function-getcategoryname) () override const<br> |




























## Detailed Description


Developer settings to define project-wide configurations for the SettingsFramework plugin. Accessed through **Project Settings** &gt; **Plugins** &gt; **SettingsFramework** in the Unreal Editor. 

**Note:**

`Config=Game` 





    
## Public Attributes Documentation




### variable BranchTabButtonClass 

```C++
TSubclassOf<class USFCategoryTabButtonBase> USFSettingsDeveloperSettings::BranchTabButtonClass;
```



The widget class for the Settings Screen UI's branch category tab buttons. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable BranchTabContentClass 

```C++
TSubclassOf<class USFCategoryTab_Branch> USFSettingsDeveloperSettings::BranchTabContentClass;
```



The widget class for displaying the content of a Branch category (containing sub-categories) in the Settings Screen UI. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable DefaultKeybindCollisionResolution 

```C++
ESFKeybindCollisionResolution USFSettingsDeveloperSettings::DefaultKeybindCollisionResolution;
```



The default keybind collision resolution policy when adding a new keybind that conflicts with an existing one. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable LeafTabContentClass 

```C++
TSubclassOf<class USFCategoryTab_Leaf> USFSettingsDeveloperSettings::LeafTabContentClass;
```



The widget class for displaying the content of a Leaf category (containing setting groups and setting entries) in the Settings Screen UI. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable MaxUpdateDepth 

```C++
int32 USFSettingsDeveloperSettings::MaxUpdateDepth;
```



The recursion guard for conditional dependencies: Maximum depth for updating setting dependencies to prevent infinite loops. If the depth is exceeded, a warning will be logged and the update will be halted. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable RootTabButtonClass 

```C++
TSubclassOf<class USFCategoryTabButtonBase> USFSettingsDeveloperSettings::RootTabButtonClass;
```



The widget class for the Settings Screen UI's root category tab buttons. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable SaveGameSlotName 

```C++
FString USFSettingsDeveloperSettings::SaveGameSlotName;
```



Save slot name for saving and loading setting values to and from disk. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable SettingEntryWidgetClasses 

```C++
TMap<TSubclassOf<class USFSettingDefinition>, TSubclassOf<class USFSettingEntryWidget> > USFSettingsDeveloperSettings::SettingEntryWidgetClasses;
```



The mapping of widget classes to display each variation of setting definition (e.g. a slider widget for a scalar setting) in the Settings Screen UI.
* 

**Note:**

`Config` `EditAnywhere` 







        

<hr>



### variable SettingGroupWidgetClass 

```C++
TSubclassOf<class USFSettingGroupWidget> USFSettingsDeveloperSettings::SettingGroupWidgetClass;
```



The widget class for displaying a setting group in the Settings Screen UI. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>



### variable SettingsRegistry 

```C++
TSoftObjectPtr<class USFSettingsRegistry> USFSettingsDeveloperSettings::SettingsRegistry;
```



The master registry asset containing setting hierarchy and definitions. Loaded asynchronously on [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) initialization. 

**Note:**

`Config` `EditAnywhere` 





        

<hr>
## Public Functions Documentation




### function GetCategoryName 

```C++
inline virtual FName USFSettingsDeveloperSettings::GetCategoryName () override const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/SFSettingsDeveloperSettings.h`

