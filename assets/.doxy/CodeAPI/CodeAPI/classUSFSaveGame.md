

# Class USFSaveGame



[**ClassList**](annotated.md) **>** [**USFSaveGame**](classUSFSaveGame.md)



_SaveGame object to serialize setting data._ [More...](#detailed-description)

* `#include "SaveGame/SFSaveGame.h"`



Inherits the following classes: USaveGame


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  TMap&lt; FGameplayTag, FString &gt; | [**SerializedSettings**](#variable-serializedsettings)  <br> |












































## Detailed Description


SaveGame object to serialize setting data. 


    
## Public Attributes Documentation




### variable SerializedSettings 

```C++
TMap<FGameplayTag, FString> USFSaveGame::SerializedSettings;
```



A map of setting Gameplay Tags to their serialized string values. The actual value objects are reconstructed from these strings when loading the save game.
* 

**Note:**

`VisibleAnywhere` 







        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/SaveGame/SFSaveGame.h`

