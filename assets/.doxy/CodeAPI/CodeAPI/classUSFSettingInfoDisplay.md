

# Class USFSettingInfoDisplay



[**ClassList**](annotated.md) **>** [**USFSettingInfoDisplay**](classUSFSettingInfoDisplay.md)



_Base widget class for displaying detailed information of a setting (name, description, etc.) when its entry widget is focused/hovered._ [More...](#detailed-description)

* `#include "UI/Components/SFSettingInfoDisplay.h"`



Inherits the following classes: UCommonUserWidget


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**DisplaySetting**](#function-displaysetting) (const struct FGameplayTag & SettingTag) <br> |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**DisplaySettingByDefinition**](#function-displaysettingbydefinition) (const class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* SettingDefinition) <br> |




## Detailed Description


Base widget class for displaying detailed information of a setting (name, description, etc.) when its entry widget is focused/hovered. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` 





    
## Public Functions Documentation




### function DisplaySetting 

```C++
void USFSettingInfoDisplay::DisplaySetting (
    const struct FGameplayTag & SettingTag
) 
```



Display the information of the setting represented by the given setting Gameplay Tag. 

**Parameters:**


* `SettingTag` The Gameplay Tag representing the setting to display. 




        

<hr>
## Protected Functions Documentation




### function DisplaySettingByDefinition 

```C++
void USFSettingInfoDisplay::DisplaySettingByDefinition (
    const class USFSettingDefinition * SettingDefinition
) 
```



Display the information of the setting represented by the given setting definition. Internal and intended to be overridden in Blueprint subclass for actual info display. 

**Parameters:**


* `SettingDefinition` The setting definition representing the setting to display. 



**Note:**

`BlueprintImplementableEvent` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/Components/SFSettingInfoDisplay.h`

