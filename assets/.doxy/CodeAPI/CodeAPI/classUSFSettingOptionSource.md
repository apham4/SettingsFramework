

# Class USFSettingOptionSource



[**ClassList**](annotated.md) **>** [**USFSettingOptionSource**](classUSFSettingOptionSource.md)



_Base class for providing a dynamic runtime list of options for a setting._ [More...](#detailed-description)

* `#include "Definitions/SFSettingOptionSource.h"`



Inherits the following classes: UObject


































## Public Functions

| Type | Name |
| ---: | :--- |
|  TArray&lt; struct [**FSFSettingOption**](structFSFSettingOption.md) &gt; | [**GetAvailableOptions**](#function-getavailableoptions) (const UObject \* WorldContextObject) const<br> |
| virtual TArray&lt; struct [**FSFSettingOption**](structFSFSettingOption.md) &gt; | [**GetAvailableOptions\_Implementation**](#function-getavailableoptions_implementation) (const UObject \* WorldContextObject) const<br> |
|  class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetDefaultValue**](#function-getdefaultvalue) (const UObject \* WorldContextObject) const<br> |
| virtual class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetDefaultValue\_Implementation**](#function-getdefaultvalue_implementation) (const UObject \* WorldContextObject) const<br> |




























## Detailed Description


Base class for providing a dynamic runtime list of options for a setting.


This class is used in [**USFSettingDefinition\_Discrete**](classUSFSettingDefinition__Discrete.md) when UseDynamicOptions is true. 

**Note:**

`Abstract` `Blueprintable` `EditInlineNew` 





    
## Public Functions Documentation




### function GetAvailableOptions 

```C++
TArray< struct FSFSettingOption > USFSettingOptionSource::GetAvailableOptions (
    const UObject * WorldContextObject
) const
```



Get the list of options to choose from for this setting 

**Parameters:**


* `WorldContextObject` The world context object from which to get the world object. 



**Returns:**

The list of options to choose from for this setting. The value should be of the type specified by the setting definition's ValueWrapperClass. 




**Note:**

`BlueprintNativeEvent` 





        

<hr>



### function GetAvailableOptions\_Implementation 

```C++
inline virtual TArray< struct FSFSettingOption > USFSettingOptionSource::GetAvailableOptions_Implementation (
    const UObject * WorldContextObject
) const
```



Native implementation of GetAvailableOptions. 


        

<hr>



### function GetDefaultValue 

```C++
class USFSettingValue * USFSettingOptionSource::GetDefaultValue (
    const UObject * WorldContextObject
) const
```



Get the default value for this setting. This is optional to implement, and if not implemented, the setting will use the fallback default value defined in the DefaultValue property of the setting definition. 

**Parameters:**


* `WorldContextObject` The world context object from which to get the world object. 



**Returns:**

The default value for this setting. The value should be of the type specified by the setting definition's ValueWrapperClass. 




**Note:**

`BlueprintNativeEvent` 





        

<hr>



### function GetDefaultValue\_Implementation 

```C++
inline virtual class USFSettingValue * USFSettingOptionSource::GetDefaultValue_Implementation (
    const UObject * WorldContextObject
) const
```



Native implementation of GetDefaultValue. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingOptionSource.h`

