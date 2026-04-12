

# Class USFSettingsRegistry



[**ClassList**](annotated.md) **>** [**USFSettingsRegistry**](classUSFSettingsRegistry.md)



_The central registry asset that contains the entire hierarchy of settings._ [More...](#detailed-description)

* `#include "Definitions/SFSettingsRegistry.h"`



Inherits the following classes: UDataAsset


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  TArray&lt; TObjectPtr&lt; class [**USFSettingCategory**](classUSFSettingCategory.md) &gt; &gt; | [**RootCategories**](#variable-rootcategories)  <br> |












































## Detailed Description


The central registry asset that contains the entire hierarchy of settings, starting from the root categories down to individual setting definitions. This needs to be assigned through the plugin's project-wide Developer Settings to be loaded on initialization by the [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md). 


    
## Public Attributes Documentation




### variable RootCategories 

```C++
TArray<TObjectPtr<class USFSettingCategory> > USFSettingsRegistry::RootCategories;
```



The collection of outer-most categories. Categories can contain sub-categories OR individual setting definitions. Any setting definitions that should be loaded by the plugin must be contained in this hierarchy starting from these root categories. 

**Note:**

`EditDefaultsOnly` `BlueprintReadOnly` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/Definitions/SFSettingsRegistry.h`

