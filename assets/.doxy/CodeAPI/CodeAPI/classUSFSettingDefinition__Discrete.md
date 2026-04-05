

# Class USFSettingDefinition\_Discrete



[**ClassList**](annotated.md) **>** [**USFSettingDefinition\_Discrete**](classUSFSettingDefinition__Discrete.md)



_Setting definition for setting an option among a list._ [More...](#detailed-description)

* `#include "Definitions/SFSettingDefinition.h"`



Inherits the following classes: [USFSettingDefinition](classUSFSettingDefinition.md)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FGameplayTagContainer | [**DeterminantSettingTags**](#variable-determinantsettingtags)  <br> |
|  TSubclassOf&lt; class [**USFSettingOptionSource**](classUSFSettingOptionSource.md) &gt; | [**OptionSource**](#variable-optionsource)  <br> |
|  TArray&lt; struct [**FSFSettingOption**](structFSFSettingOption.md) &gt; | [**StaticOptions**](#variable-staticoptions)  <br> |
|  TSubclassOf&lt; [**USFSettingValue**](classUSFSettingValue.md) &gt; | [**ValueWrapperClass**](#variable-valuewrapperclass)  <br> |
|  bool | [**bUseDynamicOptions**](#variable-busedynamicoptions)   = `false`<br> |


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
| virtual class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetDefaultValue**](#function-getdefaultvalue) (const UObject \* WorldContextObject) override const<br> |
|  TArray&lt; struct [**FSFSettingOption**](structFSFSettingOption.md) &gt; | [**GetSettingOptions**](#function-getsettingoptions) (const UObject \* WorldContextObject) const<br> |
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


Setting definition for setting an option among a list. This is usually used for a dropdown or a rotator.


Blueprint display name: SF Discrete Setting. 


    
## Public Attributes Documentation




### variable DeterminantSettingTags 

```C++
FGameplayTagContainer USFSettingDefinition_Discrete::DeterminantSettingTags;
```



For dynamic options. The collection of settings that this setting should listen to to refresh its dynamic options. If the setting has a different refresh condition, explicitly call [**GetSettingOptions()**](classUSFSettingDefinition__Discrete.md#function-getsettingoptions) for a new set of options. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable OptionSource 

```C++
TSubclassOf<class USFSettingOptionSource> USFSettingDefinition_Discrete::OptionSource;
```



For dynamic options. The evaluator class that generates the options for this setting. The object created from this class is stored in [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md), and the logic from that object is run in [**GetSettingOptions()**](classUSFSettingDefinition__Discrete.md#function-getsettingoptions) and [**GetDefaultValue()**](classUSFSettingDefinition__Discrete.md#function-getdefaultvalue). 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable StaticOptions 

```C++
TArray<struct FSFSettingOption> USFSettingDefinition_Discrete::StaticOptions;
```



For static options. The list of options to choose from for this setting. Each option has a display name and an underlying value. The value should be of the type specified by ValueWrapperClass. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable ValueWrapperClass 

```C++
TSubclassOf<USFSettingValue> USFSettingDefinition_Discrete::ValueWrapperClass;
```



The underlying value type for the options in this setting. 

**Note:**

`EditDefaultsOnly` 





        

<hr>



### variable bUseDynamicOptions 

```C++
bool USFSettingDefinition_Discrete::bUseDynamicOptions;
```



Does this setting have options that are generated dynamically at runtime? 

**Note:**

`EditDefaultsOnly` 





        

<hr>
## Public Functions Documentation




### function GetDefaultValue 

```C++
virtual class USFSettingValue * USFSettingDefinition_Discrete::GetDefaultValue (
    const UObject * WorldContextObject
) override const
```



Get the default value for this setting. 

**Returns:**

If UseDynamicOptions is set to true, return the default value evaluated from the OptionSource. Else, return the fallback default value defined in the DefaultValue property. 





        
Implements [*USFSettingDefinition::GetDefaultValue*](classUSFSettingDefinition.md#function-getdefaultvalue)


<hr>



### function GetSettingOptions 

```C++
TArray< struct FSFSettingOption > USFSettingDefinition_Discrete::GetSettingOptions (
    const UObject * WorldContextObject
) const
```



Get the option list for this setting. 

**Returns:**

If UseDynamicOptions is set to true, return the option list evaluated from the OptionSource. Else, return the static option list defined in the StaticOptions property. 





        

<hr>



### function GetValueClass 

```C++
virtual TSubclassOf< USFSettingValue > USFSettingDefinition_Discrete::GetValueClass () override const
```



Get the USFSettingValue-derived class of the value this setting uses. 

**Returns:**

The USFSettingValue-derived class of the value this setting uses.





 


        
Implements [*USFSettingDefinition::GetValueClass*](classUSFSettingDefinition.md#function-getvalueclass)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingDefinition.h`

