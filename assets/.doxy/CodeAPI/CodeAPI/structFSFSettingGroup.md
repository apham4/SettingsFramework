

# Struct FSFSettingGroup



[**ClassList**](annotated.md) **>** [**FSFSettingGroup**](structFSFSettingGroup.md)



_Struct to visually group settings within a Leaf Category._ [More...](#detailed-description)

* `#include "Definitions/SFSettingCategory.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FText | [**GroupDisplayName**](#variable-groupdisplayname)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingDefinition**](classUSFSettingDefinition.md) &gt; &gt; | [**Settings**](#variable-settings)  <br> |












































## Detailed Description


Struct to visually group settings within a Leaf Category (e.g. "Post-Processing" group inside "Graphics" category.). This is optional and only for organizational and visual purposes. It does not affect the behavior of the settings in any way. 

**Note:**

`BlueprintType` 





    
## Public Attributes Documentation




### variable GroupDisplayName 

```C++
FText FSFSettingGroup::GroupDisplayName;
```



The player-facing name of this setting group, displayed on UI. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` 





        

<hr>



### variable Settings 

```C++
TArray<TObjectPtr<class USFSettingDefinition> > FSFSettingGroup::Settings;
```



The collection of settings to be displayed in this group. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingCategory.h`

