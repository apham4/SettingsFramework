

# File SFCoreTypes.h



[**FileList**](files.md) **>** [**Core**](dir_39651220af2aa02d3a35c23742da36c9.md) **>** [**SFCoreTypes.h**](SFCoreTypes_8h.md)

[Go to the source code of this file](SFCoreTypes_8h_source.md)



* `#include "CoreMinimal.h"`
* `#include "Framework/Commands/InputChord.h"`
* `#include "InputCoreTypes.h"`
* `#include "SFCoreTypes.generated.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**FSFKeybindValueData**](structFSFKeybindValueData.md) <br>_A struct holding the three standard binding slots for an action._  |
| struct | [**FSFSettingOption**](structFSFSettingOption.md) <br>_A struct representing a single discrete option in a list for a setting._  |


## Public Types

| Type | Name |
| ---: | :--- |
| enum uint8 | [**ESFKeybindCollisionResolution**](#enum-esfkeybindcollisionresolution)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam**](#function-declare_dynamic_multicast_delegate_oneparam) (FOnSettingEntryFocused, const struct FGameplayTag &, SettingTag) <br> |




























## Public Types Documentation




### enum ESFKeybindCollisionResolution 

```C++
enum ESFKeybindCollisionResolution {
    UMETA =(DisplayName = "Allow Duplicate Bindings"),
    UMETA =(DisplayName = "Overwrite Existing Binding"),
    UMETA =(DisplayName = "Swap Bindings")
};
```



Enum defining how to resolve keybind collisions when adding a new keybind. 


        

<hr>
## Public Functions Documentation




### function DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam 

```C++
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam (
    FOnSettingEntryFocused,
    const struct FGameplayTag &,
    SettingTag
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Core/SFCoreTypes.h`

