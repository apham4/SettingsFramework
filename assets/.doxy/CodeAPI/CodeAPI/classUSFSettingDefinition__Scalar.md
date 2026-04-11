

# Class USFSettingDefinition\_Scalar



[**ClassList**](annotated.md) **>** [**USFSettingDefinition\_Scalar**](classUSFSettingDefinition__Scalar.md)



_Setting definition for setting a numeric value (int/float)._ [More...](#detailed-description)

* `#include "Definitions/SFSettingDefinition.h"`



Inherits the following classes: [USFSettingDefinition](classUSFSettingDefinition.md)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  float | [**MaxValue**](#variable-maxvalue)   = `100.0f`<br> |
|  float | [**MinValue**](#variable-minvalue)   = `0.0f`<br> |
|  float | [**StepSize**](#variable-stepsize)   = `1.0f`<br> |


## Public Attributes inherited from USFSettingDefinition

See [USFSettingDefinition](classUSFSettingDefinition.md)

| Type | Name |
| ---: | :--- |
|  FText | [**Description**](classUSFSettingDefinition.md#variable-description)  <br> |
|  FText | [**DisplayName**](classUSFSettingDefinition.md#variable-displayname)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingCondition**](classUSFSettingCondition.md) &gt; &gt; | [**EditabilityConditions**](classUSFSettingDefinition.md#variable-editabilityconditions)  <br> |
|  FGameplayTag | [**SettingTag**](classUSFSettingDefinition.md#variable-settingtag)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingCondition**](classUSFSettingCondition.md) &gt; &gt; | [**VisibilityConditions**](classUSFSettingDefinition.md#variable-visibilityconditions)  <br> |
|  bool | [**bRevertToDefaultOnDisable**](classUSFSettingDefinition.md#variable-breverttodefaultondisable)   = `false`<br> |






























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


Setting definition for setting a numeric value (int/float).


Blueprint display name: SF Scalar Setting. 


    
## Public Attributes Documentation




### variable MaxValue 

```C++
float USFSettingDefinition_Scalar::MaxValue;
```



Maximum allowed value. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable MinValue 

```C++
float USFSettingDefinition_Scalar::MinValue;
```



Minimum allowed value. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable StepSize 

```C++
float USFSettingDefinition_Scalar::StepSize;
```



The step size at which the value can be increased/decreased. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>
## Public Functions Documentation




### function GetValueClass 

```C++
inline virtual TSubclassOf< USFSettingValue > USFSettingDefinition_Scalar::GetValueClass () override const
```



Get the USFSettingValue-derived class of the value this setting uses. 

**Returns:**

The USFSettingValue-derived class of the value this setting uses.





 


        
Implements [*USFSettingDefinition::GetValueClass*](classUSFSettingDefinition.md#function-getvalueclass)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingDefinition.h`

