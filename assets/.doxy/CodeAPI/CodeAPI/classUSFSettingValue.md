

# Class USFSettingValue



[**ClassList**](annotated.md) **>** [**USFSettingValue**](classUSFSettingValue.md)



_Abstract base class for all setting values._ [More...](#detailed-description)

* `#include "Core/SFSettingValue.h"`



Inherits the following classes: UObject


Inherited by the following classes: [USFSettingValue\_Bool](classUSFSettingValue__Bool.md),  [USFSettingValue\_Key](classUSFSettingValue__Key.md),  [USFSettingValue\_Scalar](classUSFSettingValue__Scalar.md),  [USFSettingValue\_String](classUSFSettingValue__String.md),  [USFSettingValue\_Tag](classUSFSettingValue__Tag.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**DeserializeFromString**](#function-deserializefromstring) (const FString & InString) <br> |
| virtual [**USFSettingValue**](classUSFSettingValue.md) \* | [**Duplicate**](#function-duplicate) (UObject \* Outer) const<br> |
| virtual bool | [**Equals**](#function-equals) (const [**USFSettingValue**](classUSFSettingValue.md) \* Other) const<br> |
| virtual FString | [**SerializeToString**](#function-serializetostring) () const<br> |
| virtual FString | [**ToString**](#function-tostring) () const<br> |




























## Detailed Description


Abstract base class for all setting values. Wraps raw data (float, bool, key) into a generic UObject for safe transport. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` `EditInlineNew` `DefaultToInstanced` 





    
## Public Functions Documentation




### function DeserializeFromString 

```C++
virtual void USFSettingValue::DeserializeFromString (
    const FString & InString
) 
```



Load value from string 

**Parameters:**


* `InString` The string to parse the value from, typically loaded from disk. 




        

<hr>



### function Duplicate 

```C++
inline virtual USFSettingValue * USFSettingValue::Duplicate (
    UObject * Outer
) const
```



Creates a deep copy of this value 

**Parameters:**


* `Outer` The outer for the new duplicated object. Typically the caller should pass in itself as the outer, so that the duplicated value will be owned by the same object that owns this value. 



**Returns:**

A deep copy of this value object. 





        

<hr>



### function Equals 

```C++
virtual bool USFSettingValue::Equals (
    const USFSettingValue * Other
) const
```



Checks equality with another value object. 

**Parameters:**


* `Other` The other value object to compare with. 



**Returns:**

true if the two value objects are considered equal in terms of their underlying value, false otherwise. 





        

<hr>



### function SerializeToString 

```C++
virtual FString USFSettingValue::SerializeToString () const
```



Convert current value to string for saving 

**Returns:**

The string representation of the current value. Should be parseable by [**DeserializeFromString()**](classUSFSettingValue.md#function-deserializefromstring). 





        

<hr>



### function ToString 

```C++
inline virtual FString USFSettingValue::ToString () const
```



Helper function for debugging. Simply calls [**SerializeToString()**](classUSFSettingValue.md#function-serializetostring). 

**Returns:**

The string representation of the current value, same as [**SerializeToString()**](classUSFSettingValue.md#function-serializetostring). 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Core/SFSettingValue.h`

