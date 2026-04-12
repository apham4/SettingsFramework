

# File SFSettingEntryWidget\_Keybind.h



[**FileList**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**UI**](dir_c0d111a2beff4c46a32685df6daadb0f.md) **>** [**SettingEntries**](dir_ee82e1fcdef3b55cd27efecd9a182f3f.md) **>** [**SFSettingEntryWidget\_Keybind.h**](SFSettingEntryWidget__Keybind_8h.md)

[Go to the source code of this file](SFSettingEntryWidget__Keybind_8h_source.md)



* `#include "CoreMinimal.h"`
* `#include "UI/SettingEntries/SFSettingEntryWidget.h"`
* `#include "Core/SFCoreTypes.h"`
* `#include "CommonInputTypeEnum.h"`
* `#include "SFSettingEntryWidget_Keybind.generated.h"`















## Classes

| Type | Name |
| ---: | :--- |
| class | [**USFSettingEntryWidget\_Keybind**](classUSFSettingEntryWidget__Keybind.md) <br>_The native base class for a setting entry widget for a key bind setting, represented as buttons that listen for the next key press in the UI._  |


## Public Types

| Type | Name |
| ---: | :--- |
| enum uint8 | [**ESFKeybindSlot**](#enum-esfkeybindslot)  <br> |
















































## Public Types Documentation




### enum ESFKeybindSlot 

```C++
enum ESFKeybindSlot {
    None,
    KBMPrimary,
    KBMSecondary,
    Gamepad
};
```



Enum to track which keybind slot is currently listening for input for rebinding. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/SettingEntries/SFSettingEntryWidget_Keybind.h`

