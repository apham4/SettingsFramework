

# Class USFSettingDefinition\_Bool



[**ClassList**](annotated.md) **>** [**USFSettingDefinition\_Bool**](classUSFSettingDefinition__Bool.md)



_Setting definition for setting a boolean value._ [More...](#detailed-description)

* `#include "Definitions/SFSettingDefinition.h"`



Inherits the following classes: [USFSettingDefinition](classUSFSettingDefinition.md)
























## Public Attributes inherited from USFSettingDefinition

See [USFSettingDefinition](classUSFSettingDefinition.md)

| Type | Name |
| ---: | :--- |
|  FText | [**Description**](classUSFSettingDefinition.md#variable-description)  <br> |
|  FText | [**DisplayName**](classUSFSettingDefinition.md#variable-displayname)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingCondition**](classUSFSettingCondition.md) &gt; &gt; | [**EditabilityConditions**](classUSFSettingDefinition.md#variable-editabilityconditions)  <br> |
|  FGameplayTag | [**SettingTag**](classUSFSettingDefinition.md#variable-settingtag)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingCondition**](classUSFSettingCondition.md) &gt; &gt; | [**VisibilityConditions**](classUSFSettingDefinition.md#variable-visibilityconditions)  <br> |






























## Public Functions

| Type | Name |
| ---: | :--- |
| virtual TSubclassOf&lt; [**USFSettingValue**](classUSFSettingValue.md) &gt; | [**GetValueClass**](#function-getvalueclass) () override const<br> |


## Public Functions inherited from USFSettingDefinition

See [USFSettingDefinition](classUSFSettingDefinition.md)

| Type | Name |
| ---: | :--- |
| virtual class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetDefaultValue**](classUSFSettingDefinition.md#function-getdefaultvalue) (const UObject \* WorldContextObject) const<br> |
| virtual TSubclassOf&lt; [**USFSettingValue**](classUSFSettingValue.md) &gt; | [**GetValueClass**](classUSFSettingDefinition.md#function-getvalueclass) () const<br> |
















## Protected Attributes inherited from USFSettingDefinition

See [USFSettingDefinition](classUSFSettingDefinition.md)

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class [**USFSettingValue**](classUSFSettingValue.md) &gt; | [**DefaultValue**](classUSFSettingDefinition.md#variable-defaultvalue)  <br> |






































## Detailed Description


Setting definition for setting a boolean value.


Blueprint display name: SF Bool Setting. 


    
## Public Functions Documentation




### function GetValueClass 

```C++
inline virtual TSubclassOf< USFSettingValue > USFSettingDefinition_Bool::GetValueClass () override const
```



Get the USFSettingValue-derived class of the value this setting uses. 

**Returns:**

The USFSettingValue-derived class of the value this setting uses.





 


        
Implements [*USFSettingDefinition::GetValueClass*](classUSFSettingDefinition.md#function-getvalueclass)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingDefinition.h`

