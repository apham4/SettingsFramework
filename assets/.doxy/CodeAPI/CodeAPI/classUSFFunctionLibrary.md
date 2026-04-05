

# Class USFFunctionLibrary



[**ClassList**](annotated.md) **>** [**USFFunctionLibrary**](classUSFFunctionLibrary.md)



_Utility function library for the SettingsFramework._ [More...](#detailed-description)

* `#include "SFFunctionLibrary.h"`



Inherits the following classes: UBlueprintFunctionLibrary




































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  ECommonInputType | [**GetCurrentInputMethod**](#function-getcurrentinputmethod) (const UObject \* WorldContextObject) <br> |
|  class [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) \* | [**GetSettingsSubsystem**](#function-getsettingssubsystem) (const UObject \* WorldContextObject) <br> |


























## Detailed Description


Utility function library for the SettingsFramework. 


    
## Public Static Functions Documentation




### function GetCurrentInputMethod 

```C++
static ECommonInputType USFFunctionLibrary::GetCurrentInputMethod (
    const UObject * WorldContextObject
) 
```



Retrieves the current CommonUI input method (e.g., Gamepad, MouseAndKeyboard). 

**Parameters:**


* `WorldContextObject` World context object to get the world from. Can be any object that has a valid world, such as an actor, a component, a widget, etc. 



**Returns:**

The active ECommonInputType. Defaults to MouseAndKeyboard if unable to determine. 





        

<hr>



### function GetSettingsSubsystem 

```C++
static class USFSettingsSubsystem * USFFunctionLibrary::GetSettingsSubsystem (
    const UObject * WorldContextObject
) 
```



Get the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) instance. 

**Parameters:**


* `WorldContextObject` World context object to get the world from. Can be any object that has a valid world, such as an actor, a component, a widget, etc. 



**Returns:**

The [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) instance. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/SFFunctionLibrary.h`

