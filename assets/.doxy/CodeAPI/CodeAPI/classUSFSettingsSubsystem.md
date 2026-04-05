

# Class USFSettingsSubsystem



[**ClassList**](annotated.md) **>** [**USFSettingsSubsystem**](classUSFSettingsSubsystem.md)



_The subsystem that manages all settings data and logic at runtime._ [More...](#detailed-description)

* `#include "SFSettingsSubsystem.h"`



Inherits the following classes: UGameInstanceSubsystem


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  FOnSFSettingChanged | [**OnSettingValueChanged**](#variable-onsettingvaluechanged)  <br> |
|  FOnSFSettingSaved | [**OnSettingValueSaved**](#variable-onsettingvaluesaved)  <br> |
|  FOnSFSettingsInitialized | [**OnSettingsInitialized**](#variable-onsettingsinitialized)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**AreAnySettingsDirty**](#function-areanysettingsdirty) () const<br> |
|  class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetDefaultSettingValue**](#function-getdefaultsettingvalue) (const struct FGameplayTag SettingTag) const<br> |
|  class [**USFSettingOptionSource**](classUSFSettingOptionSource.md) \* | [**GetDynamicOptionSource**](#function-getdynamicoptionsource) (const struct FGameplayTag & SettingTag) const<br> |
|  struct FGameplayTag | [**GetKeybindingCollision**](#function-getkeybindingcollision) (const struct FKey & Key, const struct FGameplayTagContainer & CollisionChannels, const struct FGameplayTag & SettingTagToIgnore) const<br> |
|  TArray&lt; [**USFSettingCategory**](classUSFSettingCategory.md) \* &gt; | [**GetRootCategories**](#function-getrootcategories) () const<br> |
|  class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetSavedSettingValue**](#function-getsavedsettingvalue) (const struct FGameplayTag SettingTag) const<br> |
|  class [**USFSettingDefinition**](classUSFSettingDefinition.md) \* | [**GetSettingDefinition**](#function-getsettingdefinition) (const struct FGameplayTag & SettingTag) const<br> |
|  class [**USFSettingValue**](classUSFSettingValue.md) \* | [**GetSettingValue**](#function-getsettingvalue) (const struct FGameplayTag SettingTag) const<br> |
|  bool | [**IsInitialized**](#function-isinitialized) () const<br> |
|  bool | [**IsSettingDirty**](#function-issettingdirty) (const struct FGameplayTag SettingTag) const<br> |
|  bool | [**IsSettingEditable**](#function-issettingeditable) (const struct FGameplayTag & SettingTag) const<br> |
|  bool | [**IsSettingVisible**](#function-issettingvisible) (const struct FGameplayTag & SettingTag) const<br> |
|  void | [**ResetSettingToDefault**](#function-resetsettingtodefault) (const struct FGameplayTag SettingTag) <br> |
|  void | [**ResetSettingsToDefault**](#function-resetsettingstodefault) () <br> |
|  void | [**RevertSetting**](#function-revertsetting) (const struct FGameplayTag SettingTag) <br> |
|  void | [**RevertSettings**](#function-revertsettings) () <br> |
|  void | [**SaveSettings**](#function-savesettings) () <br> |
|  void | [**SetSettingValue**](#function-setsettingvalue) (const struct FGameplayTag SettingTag, class [**USFSettingValue**](classUSFSettingValue.md) \* NewValue) <br> |
|  bool | [**UpdateKeybinding**](#function-updatekeybinding) (const struct FGameplayTag & SettingTag, struct [**FSFKeybindValueData**](structFSFKeybindValueData.md) & NewValue, const enum [**ESFKeybindCollisionResolution**](SFCoreTypes_8h.md#enum-esfkeybindcollisionresolution) & ResolutionPolicy) <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TMap&lt; struct FGameplayTag, TObjectPtr&lt; class [**USFSettingValue**](classUSFSettingValue.md) &gt; &gt; | [**CurrentValues**](#variable-currentvalues)  <br> |
|  TMap&lt; struct FGameplayTag, TObjectPtr&lt; class [**USFSettingOptionSource**](classUSFSettingOptionSource.md) &gt; &gt; | [**DynamicOptionSources**](#variable-dynamicoptionsources)  <br> |
|  TMap&lt; struct FGameplayTag, TObjectPtr&lt; class [**USFSettingDefinition**](classUSFSettingDefinition.md) &gt; &gt; | [**RegisteredSettings**](#variable-registeredsettings)  <br> |
|  TMap&lt; struct FGameplayTag, TObjectPtr&lt; class [**USFSettingValue**](classUSFSettingValue.md) &gt; &gt; | [**SavedValues**](#variable-savedvalues)  <br> |
|  TObjectPtr&lt; class [**USFSettingsRegistry**](classUSFSettingsRegistry.md) &gt; | [**SettingsRegistry**](#variable-settingsregistry)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**LoadSettingsFromSaveGame**](#function-loadsettingsfromsavegame) () <br> |
|  bool | [**ResolveKeybindingCollision**](#function-resolvekeybindingcollision) (const struct FGameplayTag & SettingBeingUpdated, const struct FKey & NewKey, const struct FKey & OldKey, const struct FGameplayTagContainer & CollisionChannels, const enum [**ESFKeybindCollisionResolution**](SFCoreTypes_8h.md#enum-esfkeybindcollisionresolution) & ResolutionPolicy) <br> |
|  void | [**SaveSettingsToSaveGame**](#function-savesettingstosavegame) () <br> |




## Detailed Description


This subsystem is responsible for managing all settings data and logic at runtime. This includes tasks such as:



* Asynchronously loads setting definitions and categories from the settings registry on initialization
* Manages current and saved setting values
* Checks conditions for settings' visibility and editability
* Handles saving and loading settings to disk.
* Among other things. 

**Note:**

`BlueprintType` 







    
## Public Attributes Documentation




### variable OnSettingValueChanged 

```C++
FOnSFSettingChanged USFSettingsSubsystem::OnSettingValueChanged;
```



Event fired when a setting's current active value is changed. 

**Note:**

`BlueprintAssignable` 





        

<hr>



### variable OnSettingValueSaved 

```C++
FOnSFSettingSaved USFSettingsSubsystem::OnSettingValueSaved;
```



Event fired when a setting's current active value is saved to disk. 

**Note:**

`BlueprintAssignable` 





        

<hr>



### variable OnSettingsInitialized 

```C++
FOnSFSettingsInitialized USFSettingsSubsystem::OnSettingsInitialized;
```



Event fired when the settings registry has finished loading and saved setting values have been loaded from disk, indicating that the subsystem is ready to be used. 


        

<hr>
## Public Functions Documentation




### function AreAnySettingsDirty 

```C++
bool USFSettingsSubsystem::AreAnySettingsDirty () const
```



Check if any setting has its current active value different from its saved value. 

**Returns:**

true if there is at least one setting that is dirty, false if all settings are clean or if there are no registered settings. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetDefaultSettingValue 

```C++
class USFSettingValue * USFSettingsSubsystem::GetDefaultSettingValue (
    const struct FGameplayTag SettingTag
) const
```



Get the default value of a setting associated with the given setting Gameplay Tag. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

The default value of the setting associated with the given setting Gameplay Tag. Returns nullptr if the tag is not found or if the value is invalid. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetDynamicOptionSource 

```C++
class USFSettingOptionSource * USFSettingsSubsystem::GetDynamicOptionSource (
    const struct FGameplayTag & SettingTag
) const
```



Get the dynamic option source object associated with the given setting Gameplay Tag if it is a discrete setting with dynamic options. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

The setting option source object associated with the given setting Gameplay Tag. Returns nullptr if invalid. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetKeybindingCollision 

```C++
struct FGameplayTag USFSettingsSubsystem::GetKeybindingCollision (
    const struct FKey & Key,
    const struct FGameplayTagContainer & CollisionChannels,
    const struct FGameplayTag & SettingTagToIgnore
) const
```



Check for keybinding collisions with a given input key and collision channels, excluding a specific setting. 

**Parameters:**


* `Key` The input key to check for collisions. 
* `CollisionChannels` The Gameplay Tag container of collision channels to check against. Only settings that have at least one of these tags in their collision channels will be checked for collision. 
* `SettingTagToIgnore` The Gameplay Tag of the setting to ignore during collision check. This is useful when updating a keybinding for a specific setting and you want to ignore collision with its current keybinding. 



**Returns:**

The Gameplay Tag of the setting that has a colliding keybinding, or an empty tag if there are no collisions. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetRootCategories 

```C++
TArray< USFSettingCategory * > USFSettingsSubsystem::GetRootCategories () const
```



Get the collection of root categories. 

**Returns:**

An array of root categories. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetSavedSettingValue 

```C++
class USFSettingValue * USFSettingsSubsystem::GetSavedSettingValue (
    const struct FGameplayTag SettingTag
) const
```



Get the saved value of a setting associated with the given setting Gameplay Tag. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

The saved value of the setting associated with the given setting Gameplay Tag. Returns the default setting if no saved value is found. Returns nullptr if the tag is not found or if the value is invalid. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetSettingDefinition 

```C++
class USFSettingDefinition * USFSettingsSubsystem::GetSettingDefinition (
    const struct FGameplayTag & SettingTag
) const
```



Get the setting definition associated with the given setting Gameplay Tag 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

The setting definition Data Asset associated with the given setting Gameplay Tag. Returns nullptr if the tag is not found or if the associated asset failed to load. 




**Note:**

`BlueprintPure` 





        

<hr>



### function GetSettingValue 

```C++
class USFSettingValue * USFSettingsSubsystem::GetSettingValue (
    const struct FGameplayTag SettingTag
) const
```



Get the current active value of a setting associated with the given setting Gameplay Tag. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

The current active value of the setting associated with the given setting Gameplay Tag. Returns the default setting if no saved value is found. Returns nullptr if the tag is not found or if the value is invalid. 




**Note:**

`BlueprintPure` 





        

<hr>



### function IsInitialized 

```C++
inline bool USFSettingsSubsystem::IsInitialized () const
```



Checks if the settings registry has finished loading and saved setting values have been loaded from disk. 

**Returns:**

true if the subsystem is ready to be used, false if the settings registry is still loading or if there was an error during initialization. 




**Note:**

`BlueprintPure` 





        

<hr>



### function IsSettingDirty 

```C++
bool USFSettingsSubsystem::IsSettingDirty (
    const struct FGameplayTag SettingTag
) const
```



Check if the current active value of the setting associated with the given setting Gameplay Tag is different from its saved value. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

true if they are different or if one of them is invalid, false if they are the same or if they are both invalid. 




**Note:**

`BlueprintPure` 





        

<hr>



### function IsSettingEditable 

```C++
bool USFSettingsSubsystem::IsSettingEditable (
    const struct FGameplayTag & SettingTag
) const
```



Check if a setting associated with the given setting Gameplay Tag should be editable/enabled based on its editability conditions defined in its setting definition. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

true if the setting should be editable/enabled, false if it should be disabled or if the tag's setting is not found. 




**Note:**

`BlueprintPure` 





        

<hr>



### function IsSettingVisible 

```C++
bool USFSettingsSubsystem::IsSettingVisible (
    const struct FGameplayTag & SettingTag
) const
```



Check if a setting associated with the given setting Gameplay Tag should be visible based on its visibility conditions defined in its setting definition. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Returns:**

true if the setting should be visible, false if it should be hidden or if the tag's setting is not found. 




**Note:**

`BlueprintPure` 





        

<hr>



### function ResetSettingToDefault 

```C++
void USFSettingsSubsystem::ResetSettingToDefault (
    const struct FGameplayTag SettingTag
) 
```



Discard current active value and reset to default value for the setting associated with the given setting Gameplay Tag. Does not change saved value. Fires OnSettingValueChanged if the value was reset. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Note:**

`BlueprintCallable` 





        

<hr>



### function ResetSettingsToDefault 

```C++
void USFSettingsSubsystem::ResetSettingsToDefault () 
```



Discard the current active value and reset to default value for all settings. Does not change saved values. 

**Note:**

`BlueprintCallable` 





        

<hr>



### function RevertSetting 

```C++
void USFSettingsSubsystem::RevertSetting (
    const struct FGameplayTag SettingTag
) 
```



Discard current active value and revert to saved value for the setting associated with the given setting Gameplay Tag. Does not change saved value. Fires OnSettingValueChanged if the value was reverted. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Note:**

`BlueprintCallable` 





        

<hr>



### function RevertSettings 

```C++
void USFSettingsSubsystem::RevertSettings () 
```



Discard the current active value and revert to saved value for all settings that have unsaved changes. Does not change saved values. 

**Note:**

`BlueprintCallable` 





        

<hr>



### function SaveSettings 

```C++
void USFSettingsSubsystem::SaveSettings () 
```



Save and serialize all current active setting values to disk, overwriting previous saved values. 

**Note:**

`BlueprintCallable` 





        

<hr>



### function SetSettingValue 

```C++
void USFSettingsSubsystem::SetSettingValue (
    const struct FGameplayTag SettingTag,
    class USFSettingValue * NewValue
) 
```



Update the current active value of a setting associated with the given setting Gameplay Tag. Does not save value to disk. 

**Parameters:**


* `SettingTag` The Gameplay Tag associated with the setting. 



**Note:**

`BlueprintCallable` 





        

<hr>



### function UpdateKeybinding 

```C++
bool USFSettingsSubsystem::UpdateKeybinding (
    const struct FGameplayTag & SettingTag,
    struct FSFKeybindValueData & NewValue,
    const enum ESFKeybindCollisionResolution & ResolutionPolicy
) 
```



Update a keybinding for a setting with specific collision handling. If the new keybinding collides with existing keybindings based on the given collision channels, the collision will be resolved according to the specified resolution policy. 

**Parameters:**


* `SettingTag` The Gameplay Tag of the setting to update the keybinding for. 
* `NewValue` The new keybinding value data to apply to the setting. 
* `ResolutionPolicy` The policy to use for resolving keybinding collisions if the new keybinding collides with existing keybindings. **AllowDuplicate** means the new keybinding will be applied even if there is a collision. **Overwrite** means the existing conflicting keybind will be removed. **Swap** means the existing conflicting keybind will be changed to the new keybinding's old value. 



**Returns:**

true if the keybinding was updated successfully, false if there was an error such as the setting tag not being found, the new value being invalid, or if collision resolution failed. 




**Note:**

`BlueprintCallable` 





        

<hr>
## Protected Attributes Documentation




### variable CurrentValues 

```C++
TMap<struct FGameplayTag, TObjectPtr<class USFSettingValue> > USFSettingsSubsystem::CurrentValues;
```



The map of setting GameplayTag to current active value for registered settings. Used for managing current setting values at runtime. 

**Note:**

`Transient` 





        

<hr>



### variable DynamicOptionSources 

```C++
TMap<struct FGameplayTag, TObjectPtr<class USFSettingOptionSource> > USFSettingsSubsystem::DynamicOptionSources;
```



The map of setting GameplayTag to setting setting option source object for registered discrete settings wtih dynamic options. 

**Note:**

`Transient` 





        

<hr>



### variable RegisteredSettings 

```C++
TMap<struct FGameplayTag, TObjectPtr<class USFSettingDefinition> > USFSettingsSubsystem::RegisteredSettings;
```



The map of setting GameplayTag to setting definition Data Asset for registered settings. Used for quick lookup of setting definitions at runtime. 

**Note:**

`Transient` 





        

<hr>



### variable SavedValues 

```C++
TMap<struct FGameplayTag, TObjectPtr<class USFSettingValue> > USFSettingsSubsystem::SavedValues;
```



The map of setting GameplayTag to saved value for registered settings. Used for managing saved setting values at runtime and for saving/loading settings to disk. 

**Note:**

`Transient` 





        

<hr>



### variable SettingsRegistry 

```C++
TObjectPtr<class USFSettingsRegistry> USFSettingsSubsystem::SettingsRegistry;
```



Transient pointer to the loaded settings registry asset. 

**Note:**

`Transient` 





        

<hr>
## Protected Functions Documentation




### function LoadSettingsFromSaveGame 

```C++
void USFSettingsSubsystem::LoadSettingsFromSaveGame () 
```



Load saved setting values from disk and update CurrentValues and SavedValues maps accordingly. Called during initialization after settings registry is loaded. 


        

<hr>



### function ResolveKeybindingCollision 

```C++
bool USFSettingsSubsystem::ResolveKeybindingCollision (
    const struct FGameplayTag & SettingBeingUpdated,
    const struct FKey & NewKey,
    const struct FKey & OldKey,
    const struct FGameplayTagContainer & CollisionChannels,
    const enum ESFKeybindCollisionResolution & ResolutionPolicy
) 
```



Check for keybinding collisions with a given new keybinding for a specific setting and resolve them according to the specified resolution policy. 

**Parameters:**


* `SettingBeingUpdated` The Gameplay Tag of the setting that is being updated with the new keybinding. 
* `NewKey` The new keybinding value that is being applied to the setting. 
* `OldKey` The old keybinding value that is being replaced by the new keybinding for the setting. 
* `CollisionChannels` The Gameplay Tag container of collision channels to check against. Only settings that have at least one of these tags in their collision channels will be checked for collision. 
* `ResolutionPolicy` The policy to use for resolving keybinding collisions if the new keybinding collides with existing keybindings. **AllowDuplicate** means the new keybinding will be applied even if there is a collision. **Overwrite** means the existing conflicting keybind will be removed. **Swap** means the existing conflicting keybind will be changed to the new keybinding's old value. 



**Returns:**

true if the collision was resolved successfully, false if resolution failed. 





        

<hr>



### function SaveSettingsToSaveGame 

```C++
void USFSettingsSubsystem::SaveSettingsToSaveGame () 
```



Save current active setting values to disk and update SavedValues map accordingly. Called when SaveSettings is called. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/SettingsFramework/Public/SFSettingsSubsystem.h`

