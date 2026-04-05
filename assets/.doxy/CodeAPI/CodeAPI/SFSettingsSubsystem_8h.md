

# File SFSettingsSubsystem.h



[**FileList**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**SFSettingsSubsystem.h**](SFSettingsSubsystem_8h.md)

[Go to the source code of this file](SFSettingsSubsystem_8h_source.md)



* `#include "CoreMinimal.h"`
* `#include "Subsystems/GameInstanceSubsystem.h"`
* `#include "SFSettingsSubsystem.generated.h"`















## Classes

| Type | Name |
| ---: | :--- |
| class | [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md) <br>_The subsystem that manages all settings data and logic at runtime._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE**](#function-declare_dynamic_multicast_delegate) (FOnSFSettingsInitialized) <br> |
|   | [**DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_TwoParams**](#function-declare_dynamic_multicast_delegate_twoparams) (FOnSFSettingChanged, const struct FGameplayTag &, SettingTag, class [**USFSettingValue**](classUSFSettingValue.md) \*, NewValue) <br> |
|   | [**DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_TwoParams**](#function-declare_dynamic_multicast_delegate_twoparams) (FOnSFSettingSaved, const struct FGameplayTag &, SettingTag, class [**USFSettingValue**](classUSFSettingValue.md) \*, SavedValue) <br> |




























## Public Functions Documentation




### function DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE 

```C++
DECLARE_DYNAMIC_MULTICAST_DELEGATE (
    FOnSFSettingsInitialized
) 
```




<hr>



### function DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_TwoParams 

```C++
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams (
    FOnSFSettingChanged,
    const struct FGameplayTag &,
    SettingTag,
    class USFSettingValue *,
    NewValue
) 
```




<hr>



### function DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_TwoParams 

```C++
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams (
    FOnSFSettingSaved,
    const struct FGameplayTag &,
    SettingTag,
    class USFSettingValue *,
    SavedValue
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/SFSettingsSubsystem.h`

