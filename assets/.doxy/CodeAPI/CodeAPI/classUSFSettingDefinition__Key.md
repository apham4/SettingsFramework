

# Class USFSettingDefinition\_Key



[**ClassList**](annotated.md) **>** [**USFSettingDefinition\_Key**](classUSFSettingDefinition__Key.md)



_Setting definition for setting keybind for an action._ [More...](#detailed-description)

* `#include "Definitions/SFSettingDefinition.h"`



Inherits the following classes: [USFSettingDefinition](classUSFSettingDefinition.md)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FGameplayTagContainer | [**CollisionChannels**](#variable-collisionchannels)  <br> |
|  FName | [**GamepadName**](#variable-gamepadname)  <br> |
|  FName | [**KBMPrimaryName**](#variable-kbmprimaryname)  <br> |
|  FName | [**KBMSecondaryName**](#variable-kbmsecondaryname)  <br> |


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


Setting definition for setting keybind for an action.


Blueprint display name: SF Keybind Setting. 


    
## Public Attributes Documentation




### variable CollisionChannels 

```C++
FGameplayTagContainer USFSettingDefinition_Key::CollisionChannels;
```



Channels identified by Gameplay Tags for collision checking. Only settings that share at least one channel will trigger collision warnings. Useful for categorizing keybinds into different groups such as "Global", "Combat", "UI", etc., so that only keybinds in the same group will trigger collision warnings. 

**Note:**

`EditDefaultsOnly` 





        

<hr>



### variable GamepadName 

```C++
FName USFSettingDefinition_Key::GamepadName;
```



The identifier for the gamepad keybind in the Input Mapping Context. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable KBMPrimaryName 

```C++
FName USFSettingDefinition_Key::KBMPrimaryName;
```



The identifier for the primary KBM keybind in the Input Mapping Context. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable KBMSecondaryName 

```C++
FName USFSettingDefinition_Key::KBMSecondaryName;
```



The identifier for the secondary KBM keybind in the Input Mapping Context. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>
## Public Functions Documentation




### function GetValueClass 

```C++
inline virtual TSubclassOf< USFSettingValue > USFSettingDefinition_Key::GetValueClass () override const
```



Get the USFSettingValue-derived class of the value this setting uses. 

**Returns:**

The USFSettingValue-derived class of the value this setting uses.





 


        
Implements [*USFSettingDefinition::GetValueClass*](classUSFSettingDefinition.md#function-getvalueclass)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingDefinition.h`

