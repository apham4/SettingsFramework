

# Class USFCategoryTabButtonBase



[**ClassList**](annotated.md) **>** [**USFCategoryTabButtonBase**](classUSFCategoryTabButtonBase.md)



_Base widget class for tab buttons used in the CategoryTabList of_ [_**USFSettingsScreen**_](classUSFSettingsScreen.md) _and_[_**USFCategoryTab\_Branch**_](classUSFCategoryTab__Branch.md) _._[More...](#detailed-description)

* `#include "UI/Components/SFCategoryTabButtonBase.h"`



Inherits the following classes: UCommonButtonBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**SetCategoryData**](#function-setcategorydata) (const class [**USFSettingCategory**](classUSFSettingCategory.md) \* InCategory) <br> |
| virtual void | [**SetCategoryData\_Implementation**](#function-setcategorydata_implementation) (const class [**USFSettingCategory**](classUSFSettingCategory.md) \* InCategory) <br> |




























## Detailed Description


Base widget class for tab buttons used in the CategoryTabList of [**USFSettingsScreen**](classUSFSettingsScreen.md) and [**USFCategoryTab\_Branch**](classUSFCategoryTab__Branch.md). The widget blueprints implementing this class should be assigned to the RootTabButtonClass and BranchTabButtonClass in the Developer Settings at Project Settings &gt; Plugins &gt; SettingsFramework. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` 





    
## Public Functions Documentation




### function SetCategoryData 

```C++
void USFCategoryTabButtonBase::SetCategoryData (
    const class USFSettingCategory * InCategory
) 
```



Sets the tab button's display provided the setting category it represents. 

**Parameters:**


* `InCategory` The setting category represented by this tab button. 



**Note:**

`BlueprintNativeEvent` 





        

<hr>



### function SetCategoryData\_Implementation 

```C++
inline virtual void USFCategoryTabButtonBase::SetCategoryData_Implementation (
    const class USFSettingCategory * InCategory
) 
```



Native implementation of SetCategoryData. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/Components/SFCategoryTabButtonBase.h`

