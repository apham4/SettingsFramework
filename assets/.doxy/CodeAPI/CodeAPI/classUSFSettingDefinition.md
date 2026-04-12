

# Class USFSettingDefinition



[**ClassList**](annotated.md) **>** [**USFSettingDefinition**](classUSFSettingDefinition.md)



_Abstract base class for all setting definitions._ [More...](#detailed-description)

* `#include "Definitions/SFSettingDefinition.h"`



Inherits the following classes: UDataAsset


Inherited by the following classes: [USFSettingDefinition\_Bool](classUSFSettingDefinition__Bool.md),  [USFSettingDefinition\_Discrete](classUSFSettingDefinition__Discrete.md),  [USFSettingDefinition\_Key](classUSFSettingDefinition__Key.md),  [USFSettingDefinition\_Scalar](classUSFSettingDefinition__Scalar.md)
















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FText | [**Description**](#variable-description)  <br> |
|  FText | [**DisplayName**](#variable-displayname)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingCondition**](classUSFSettingCondition.md) &gt; &gt; | [**EditabilityConditions**](#variable-editabilityconditions)  <br> |
|  FGameplayTag | [**SettingTag**](#variable-settingtag)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingCondition**](classUSFSettingCondition.md) &gt; &gt; | [**VisibilityConditions**](#variable-visibilityconditions)  <br> |
|  bool | [**bRevertToDefaultOnDisable**](#variable-breverttodefaultondisable)   = `false`<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
| virtual class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetDefaultValue**](#function-getdefaultvalue) (const UObject \* WorldContextObject) const<br> |
| virtual TSubclassOf&lt; [**USFSettingValue**](classUSFSettingValue.md) &gt; | [**GetValueClass**](#function-getvalueclass) () const<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class [**USFSettingValue**](classUSFSettingValue.md) &gt; | [**DefaultValue**](#variable-defaultvalue)  <br> |




















## Detailed Description


Abstract base class for all setting definitions. Has the basic metadata such as setting Gameplay Tag, display name, description, conditions, etc. 

**Note:**

`Abstract` `BlueprintType` 





    
## Public Attributes Documentation




### variable Description 

```C++
FText USFSettingDefinition::Description;
```



The setting's player-facing description, displayed on UI. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable DisplayName 

```C++
FText USFSettingDefinition::DisplayName;
```



The setting's player-facing name, displayed on UI. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable EditabilityConditions 

```C++
TArray<TObjectPtr<class USFSettingCondition> > USFSettingDefinition::EditabilityConditions;
```



The collection of condition evaluators that determine whether this setting is editable/active. If any condition in the array is not met, the setting will be disabled but still visible. The check is triggered on any setting value change. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable SettingTag 

```C++
FGameplayTag USFSettingDefinition::SettingTag;
```



The setting's unique identifier. Used for listening to value changes from this setting. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable VisibilityConditions 

```C++
TArray<TObjectPtr<class USFSettingCondition> > USFSettingDefinition::VisibilityConditions;
```



The collection of condition evaluators that determine whether this setting is visible. If any condition in the array is not met, the setting will be hidden. The check is triggered on any setting value change. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable bRevertToDefaultOnDisable 

```C++
bool USFSettingDefinition::bRevertToDefaultOnDisable;
```



Should this setting be reverted to its default value if its VisibilityConditions or EditabilityConditions are not met. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>
## Public Functions Documentation




### function GetDefaultValue 

```C++
inline virtual class USFSettingValue * USFSettingDefinition::GetDefaultValue (
    const UObject * WorldContextObject
) const
```



Get the default value for this setting. 

**Parameters:**


* `WorldContextObject` The world context object from which to get the world object. 



**Returns:**

The default value for this setting. 





        

<hr>



### function GetValueClass 

```C++
inline virtual TSubclassOf< USFSettingValue > USFSettingDefinition::GetValueClass () const
```



Get the USFSettingValue-derived class of the value this setting uses. 

**Returns:**

The USFSettingValue-derived class of the value this setting uses. 





        

<hr>
## Protected Attributes Documentation




### variable DefaultValue 

```C++
TObjectPtr<class USFSettingValue> USFSettingDefinition::DefaultValue;
```



The static default value for this setting. This is returned by [**GetDefaultValue()**](classUSFSettingDefinition.md#function-getdefaultvalue) if it is not overridden by the subclass. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingDefinition.h`

