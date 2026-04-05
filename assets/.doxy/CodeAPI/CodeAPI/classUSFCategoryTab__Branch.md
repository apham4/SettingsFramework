

# Class USFCategoryTab\_Branch



[**ClassList**](annotated.md) **>** [**USFCategoryTab\_Branch**](classUSFCategoryTab__Branch.md)



_The native base class for the content widget representing a branch-type setting category (contains sub-categories)._ [More...](#detailed-description)

* `#include "UI/Components/SFCategoryTab_Branch.h"`



Inherits the following classes: [USFCategoryTabBase](classUSFCategoryTabBase.md)
























## Public Attributes inherited from USFCategoryTabBase

See [USFCategoryTabBase](classUSFCategoryTabBase.md)

| Type | Name |
| ---: | :--- |
|  FOnSettingEntryFocused | [**OnSettingFocused**](classUSFCategoryTabBase.md#variable-onsettingfocused)  <br> |






























## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**InitializeCategoryDisplay**](#function-initializecategorydisplay) () override<br> |


## Public Functions inherited from USFCategoryTabBase

See [USFCategoryTabBase](classUSFCategoryTabBase.md)

| Type | Name |
| ---: | :--- |
|  const class [**USFSettingCategory**](classUSFSettingCategory.md) \* | [**GetSettingCategory**](classUSFCategoryTabBase.md#function-getsettingcategory) () const<br> |
| virtual void | [**InitializeCategoryDisplay**](classUSFCategoryTabBase.md#function-initializecategorydisplay) () <br> |
|  void | [**SetCategory**](classUSFCategoryTabBase.md#function-setcategory) (class [**USFSettingCategory**](classUSFSettingCategory.md) \* InSettingCategory) <br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class UCommonTabListWidgetBase &gt; | [**SubCategoryTabList**](#variable-subcategorytablist)  <br> |
|  TObjectPtr&lt; class UCommonActivatableWidgetSwitcher &gt; | [**TabContentSwitcher**](#variable-tabcontentswitcher)  <br> |


## Protected Attributes inherited from USFCategoryTabBase

See [USFCategoryTabBase](classUSFCategoryTabBase.md)

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class [**USFSettingCategory**](classUSFSettingCategory.md) &gt; | [**SettingCategory**](classUSFCategoryTabBase.md#variable-settingcategory)  <br> |






































## Detailed Description


The native base class for the content widget representing a branch-type setting category (contains sub-categories). This is a subclass of [**USFCategoryTabBase**](classUSFCategoryTabBase.md). It is added to [**USFSettingsScreen**](classUSFSettingsScreen.md)'s TabContentSwitcher for branch-type categories.


The widget blueprint implementing this class should be assigned to the BranchTabContentClass in the Developer Settings at Project Settings &gt; Plugins &gt; SettingsFramework. 

**Note:**

`Abstract` `BlueprintType` `Blueprintable` 





    
## Public Functions Documentation




### function InitializeCategoryDisplay 

```C++
virtual void USFCategoryTab_Branch::InitializeCategoryDisplay () override
```



Populate the widget with the data from the category asset. This is called when the widget is displayed for the first time to allow for lazy loading.


 


        
Implements [*USFCategoryTabBase::InitializeCategoryDisplay*](classUSFCategoryTabBase.md#function-initializecategorydisplay)


<hr>
## Protected Attributes Documentation




### variable SubCategoryTabList 

```C++
TObjectPtr<class UCommonTabListWidgetBase> USFCategoryTab_Branch::SubCategoryTabList;
```



The Common Tab List widget containing tab buttons representing the sub-categories. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>



### variable TabContentSwitcher 

```C++
TObjectPtr<class UCommonActivatableWidgetSwitcher> USFCategoryTab_Branch::TabContentSwitcher;
```



The Common Activatable Widget Switcher containing the content for each sub-category, switched by the SubCategoryTabList. 

**Note:**

`BlueprintReadOnly` `BindWidget` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/Components/SFCategoryTab_Branch.h`

