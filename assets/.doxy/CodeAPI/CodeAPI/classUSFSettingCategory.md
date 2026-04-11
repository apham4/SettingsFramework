

# Class USFSettingCategory



[**ClassList**](annotated.md) **>** [**USFSettingCategory**](classUSFSettingCategory.md)



_Defines a Category that can contain either Sub-Categories (Branch) or individual Settings (Leaf)._ [More...](#detailed-description)

* `#include "Definitions/SFSettingCategory.h"`



Inherits the following classes: UDataAsset


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FGameplayTag | [**CategoryTag**](#variable-categorytag)  <br> |
|  [**ESFCategoryType**](SFSettingCategory_8h.md#enum-esfcategorytype) | [**CategoryType**](#variable-categorytype)   = `ESFCategoryType::Leaf`<br> |
|  FText | [**DisplayName**](#variable-displayname)  <br> |
|  TArray&lt; [**FSFSettingGroup**](structFSFSettingGroup.md) &gt; | [**SettingGroups**](#variable-settinggroups)  <br> |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingDefinition**](classUSFSettingDefinition.md) &gt; &gt; | [**Settings**](#variable-settings)  <br> |
|  TArray&lt; TObjectPtr&lt; [**USFSettingCategory**](classUSFSettingCategory.md) &gt; &gt; | [**Subcategories**](#variable-subcategories)  <br> |












































## Detailed Description


Defines a Category that can contain either Sub-Categories (Branch) or individual Settings (Leaf). 

**Note:**

`BlueprintType` 





    
## Public Attributes Documentation




### variable CategoryTag 

```C++
FGameplayTag USFSettingCategory::CategoryTag;
```



The category's unique identifier. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable CategoryType 

```C++
ESFCategoryType USFSettingCategory::CategoryType;
```



Is this a Branch category that contains sub-categories, or a Leaf category that contains individual settings? 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable DisplayName 

```C++
FText USFSettingCategory::DisplayName;
```



The player-facing name of this category, displayed on UI. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable SettingGroups 

```C++
TArray<FSFSettingGroup> USFSettingCategory::SettingGroups;
```



For Leaf category. The collection of setting groups under this category. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable Settings 

```C++
TArray<TObjectPtr<class USFSettingDefinition> > USFSettingCategory::Settings;
```



For Leaf category. If setting groups are not desired, individual settings can be added directly to the category without grouping. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>



### variable Subcategories 

```C++
TArray<TObjectPtr<USFSettingCategory> > USFSettingCategory::Subcategories;
```



For Branch category. The collection of sub-categories under this category. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingCategory.h`

