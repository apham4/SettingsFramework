

# Class USFSettingCondition



[**ClassList**](annotated.md) **>** [**USFSettingCondition**](classUSFSettingCondition.md)



_Base class for evaluating conditions determining a setting's state._ [More...](#detailed-description)

* `#include "Definitions/SFSettingCondition.h"`



Inherits the following classes: UObject


































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**IsConditionMet**](#function-isconditionmet) (const UObject \* WorldContextObject) const<br> |
| virtual bool | [**IsConditionMet\_Implementation**](#function-isconditionmet_implementation) (const UObject \* WorldContextObject) const<br> |




























## Detailed Description


Base class for evaluating conditions determining a setting's state. The setting Data Asset has a list of VisibilityConditions, and a list of EditabilityConditions, which will be used to evaluate its specific active/disabled/hidden state. 

**Note:**

`Abstract` `Blueprintable` `EditInlineNew` `DefaultToInstanced` 





    
## Public Functions Documentation




### function IsConditionMet 

```C++
bool USFSettingCondition::IsConditionMet (
    const UObject * WorldContextObject
) const
```



Evaluate the condition. 

**Parameters:**


* `WorldContextObject` The world context object from which to get the world object. 



**Returns:**

true if the condition is met, false otherwise. 




**Note:**

`BlueprintNativeEvent` 





        

<hr>



### function IsConditionMet\_Implementation 

```C++
inline virtual bool USFSettingCondition::IsConditionMet_Implementation (
    const UObject * WorldContextObject
) const
```



Native implementation of IsConditionMet. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingCondition.h`

