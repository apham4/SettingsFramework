

# Class USFCategoryTabBase



[**ClassList**](annotated.md) **>** [**USFCategoryTabBase**](classUSFCategoryTabBase.md)



_The native base class for the content widget representing a setting category._ [More...](#detailed-description)

* `#include "UI/Components/SFCategoryTabBase.h"`



Inherits the following classes: UCommonActivatableWidget


Inherited by the following classes: [USFCategoryTab\_Branch](classUSFCategoryTab__Branch.md),  [USFCategoryTab\_Leaf](classUSFCategoryTab__Leaf.md)
















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FOnSettingEntryFocused | [**OnSettingFocused**](#variable-onsettingfocused)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  const class [**USFSettingCategory**](classUSFSettingCategory.md) \* | [**GetSettingCategory**](#function-getsettingcategory) () const<br> |
| virtual void | [**InitializeCategoryDisplay**](#function-initializecategorydisplay) () <br> |
|  void | [**SetCategory**](#function-setcategory) (class [**USFSettingCategory**](classUSFSettingCategory.md) \* InSettingCategory) <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TObjectPtr&lt; class [**USFSettingCategory**](classUSFSettingCategory.md) &gt; | [**SettingCategory**](#variable-settingcategory)  <br> |




















## Detailed Description


The native base class for the content widget representing a setting category.


This is the superclass of [**USFCategoryTab\_Branch**](classUSFCategoryTab__Branch.md), which displays a branch-type category with subcategories, and [**USFCategoryTab\_Leaf**](classUSFCategoryTab__Leaf.md), which displays a leaf-type category with setting entries. 

**Note:**

`Abstract` `BlueprintType` 





    
## Public Attributes Documentation




### variable OnSettingFocused 

```C++
FOnSettingEntryFocused USFCategoryTabBase::OnSettingFocused;
```



Event fired when a setting entry within this category is hovered/focused in the UI, with the focused setting's tag as a parameter. 


        

<hr>
## Public Functions Documentation




### function GetSettingCategory 

```C++
inline const class USFSettingCategory * USFCategoryTabBase::GetSettingCategory () const
```



Get the category asset assigned to this widget. 

**Returns:**

The category asset assigned to this widget. 




**Note:**

`BlueprintPure` 





        

<hr>



### function InitializeCategoryDisplay 

```C++
inline virtual void USFCategoryTabBase::InitializeCategoryDisplay () 
```



Populate the widget with the data from the category asset. This is called when the widget is displayed for the first time to allow for lazy loading. 


        

<hr>



### function SetCategory 

```C++
void USFCategoryTabBase::SetCategory (
    class USFSettingCategory * InSettingCategory
) 
```



Assign the corresponding category asset to this widget. 

**Parameters:**


* `InSettingCategory` The category asset represented by this widget. 




        

<hr>
## Protected Attributes Documentation




### variable SettingCategory 

```C++
TObjectPtr<class USFSettingCategory> USFCategoryTabBase::SettingCategory;
```



The transient pointer to the category asset represented by this widget. 

**Note:**

`Transient` 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/UI/Components/SFCategoryTabBase.h`

