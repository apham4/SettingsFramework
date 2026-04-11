

# Struct FSFKeybindValueData



[**ClassList**](annotated.md) **>** [**FSFKeybindValueData**](structFSFKeybindValueData.md)



_A struct holding the three standard binding slots for an action._ [More...](#detailed-description)

* `#include "Core/SFCoreTypes.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FKey | [**Gamepad**](#variable-gamepad)  <br> |
|  FKey | [**KBMPrimary**](#variable-kbmprimary)  <br> |
|  FKey | [**KBMSecondary**](#variable-kbmsecondary)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**operator==**](#function-operator) (const [**FSFKeybindValueData**](structFSFKeybindValueData.md) & Other) const<br> |




























## Detailed Description


A struct holding the three standard binding slots for an action: KBM Primary, KBM Secondary, and Gamepad.


This struct is used as the underlying value for [**USFSettingValue\_Key**](classUSFSettingValue__Key.md). 

**Note:**

`BlueprintType` 





    
## Public Attributes Documentation




### variable Gamepad 

```C++
FKey FSFKeybindValueData::Gamepad;
```



The Gamepad key for this action. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` 





        

<hr>



### variable KBMPrimary 

```C++
FKey FSFKeybindValueData::KBMPrimary;
```



The primary KBM key for this action. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` 





        

<hr>



### variable KBMSecondary 

```C++
FKey FSFKeybindValueData::KBMSecondary;
```



The secondary KBM key for this action. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` 





        

<hr>
## Public Functions Documentation




### function operator== 

```C++
inline bool FSFKeybindValueData::operator== (
    const FSFKeybindValueData & Other
) const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Core/SFCoreTypes.h`

