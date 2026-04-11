

# Struct FSFSettingOption



[**ClassList**](annotated.md) **>** [**FSFSettingOption**](structFSFSettingOption.md)



_A struct representing a single discrete option in a list for a setting._ [More...](#detailed-description)

* `#include "Core/SFCoreTypes.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FText | [**DisplayName**](#variable-displayname)  <br> |
|  TObjectPtr&lt; class [**USFSettingValue**](classUSFSettingValue.md) &gt; | [**Value**](#variable-value)  <br> |












































## Detailed Description


A struct representing a single discrete option in a list for a setting (e.g. "High", "1920x1080", "Monitor 1"), with a localized display name and an associated value object of the abstract type [**USFSettingValue**](classUSFSettingValue.md). This allows for great flexibility in defining what each option represents and how it behaves when selected.


This struct is used as the value for [**USFSettingDefinition\_Discrete**](classUSFSettingDefinition__Discrete.md). 

**Note:**

`BlueprintType` 





    
## Public Attributes Documentation




### variable DisplayName 

```C++
FText FSFSettingOption::DisplayName;
```



The player-facing name of the option. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` 





        

<hr>



### variable Value 

```C++
TObjectPtr<class USFSettingValue> FSFSettingOption::Value;
```



The value associated with this option, can be of any USFSettingValue-derived type. 

**Note:**

`EditAnywhere` `BlueprintReadWrite` `Instanced` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Core/SFCoreTypes.h`

