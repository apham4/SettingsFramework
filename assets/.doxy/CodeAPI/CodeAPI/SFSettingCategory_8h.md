

# File SFSettingCategory.h



[**FileList**](files.md) **>** [**Definitions**](dir_49fd2e6d8d3cd0aca0d770534c763afe.md) **>** [**SFSettingCategory.h**](SFSettingCategory_8h.md)

[Go to the source code of this file](SFSettingCategory_8h_source.md)



* `#include "CoreMinimal.h"`
* `#include "Engine/DataAsset.h"`
* `#include "GameplayTagContainer.h"`
* `#include "SFSettingCategory.generated.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**FSFSettingGroup**](structFSFSettingGroup.md) <br>_Struct to visually group settings within a Leaf Category._  |
| class | [**USFSettingCategory**](classUSFSettingCategory.md) <br>_Defines a Category that can contain either Sub-Categories (Branch) or individual Settings (Leaf)._  |


## Public Types

| Type | Name |
| ---: | :--- |
| enum uint8 | [**ESFCategoryType**](#enum-esfcategorytype)  <br> |
















































## Public Types Documentation




### enum ESFCategoryType 

```C++
enum ESFCategoryType {
    UMETA =(ToolTip = "Contains other Sub-Categories"),
    UMETA =(ToolTip = "Contains individual Settings")
};
```



Enum to define whether a Category is a Branch (contains sub-categories) or a Leaf (contains individual settings). 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingCategory.h`

