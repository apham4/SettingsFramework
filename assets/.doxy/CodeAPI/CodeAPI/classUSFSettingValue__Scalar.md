

# Class USFSettingValue\_Scalar



[**ClassList**](annotated.md) **>** [**USFSettingValue\_Scalar**](classUSFSettingValue__Scalar.md)



_Setting value representing a numeric value (int/float)._ [More...](#detailed-description)

* `#include "Core/SFSettingValue.h"`



Inherits the following classes: [USFSettingValue](classUSFSettingValue.md)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  float | [**Value**](#variable-value)   = `0.0f`<br> |
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**DeserializeFromString**](#function-deserializefromstring) (const FString & InString) override<br> |
| virtual bool | [**Equals**](#function-equals) (const [**USFSettingValue**](classUSFSettingValue.md) \* Other) override const<br> |
| virtual FString | [**SerializeToString**](#function-serializetostring) () override const<br> |


## Public Functions inherited from USFSettingValue

See [USFSettingValue](classUSFSettingValue.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**DeserializeFromString**](classUSFSettingValue.md#function-deserializefromstring) (const FString & InString) <br> |
| virtual [**USFSettingValue**](classUSFSettingValue.md) \* | [**Duplicate**](classUSFSettingValue.md#function-duplicate) (UObject \* Outer) const<br> |
| virtual bool | [**Equals**](classUSFSettingValue.md#function-equals) (const [**USFSettingValue**](classUSFSettingValue.md) \* Other) const<br> |
| virtual FString | [**SerializeToString**](classUSFSettingValue.md#function-serializetostring) () const<br> |
| virtual FString | [**ToString**](classUSFSettingValue.md#function-tostring) () const<br> |






















































## Detailed Description


Setting value representing a numeric value (int/float).


Blueprint display name: SF Scalar Value. 


    
## Public Attributes Documentation




### variable Value 

```C++
float USFSettingValue_Scalar::Value;
```



The underlying numeric value. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` 





        

<hr>
## Public Functions Documentation




### function DeserializeFromString 

```C++
virtual void USFSettingValue_Scalar::DeserializeFromString (
    const FString & InString
) override
```



Load value from string 

**Parameters:**


* `InString` The string to parse the value from, typically loaded from disk.




 


        
Implements [*USFSettingValue::DeserializeFromString*](classUSFSettingValue.md#function-deserializefromstring)


<hr>



### function Equals 

```C++
virtual bool USFSettingValue_Scalar::Equals (
    const USFSettingValue * Other
) override const
```



Checks equality with another value object. 

**Parameters:**


* `Other` The other value object to compare with. 



**Returns:**

true if the two value objects are considered equal in terms of their underlying value, false otherwise.





 


        
Implements [*USFSettingValue::Equals*](classUSFSettingValue.md#function-equals)


<hr>



### function SerializeToString 

```C++
virtual FString USFSettingValue_Scalar::SerializeToString () override const
```



Convert current value to string for saving 

**Returns:**

The string representation of the current value. Should be parseable by [**DeserializeFromString()**](classUSFSettingValue.md#function-deserializefromstring).





 


        
Implements [*USFSettingValue::SerializeToString*](classUSFSettingValue.md#function-serializetostring)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Core/SFSettingValue.h`

