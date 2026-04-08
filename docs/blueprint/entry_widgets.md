This guide covers the setting entry widgets provided in the SettingsFramework basic UI suite. It explains their primary functions, the native C++ classes they extend, and any additional Blueprint functionality they introduce on top of their parent classes. Each setting entry widget class corresponds to a different setting data type.

* All setting entry widgets are located in `/Plugins/SettingsFramework/UI/SettingEntries`.
* All setting entry widgets have the optional Bind Widget element `SettingLabel` (UCommonTextBlock) for displaying the setting's name.

**⚠️ Note:** Ensure **Show Plugin Content** is enabled in your Content Drawer's settings to locate these Blueprints.

---

## 1 - WBP_SettingEntry_Checkbox

* **Native parent class:** [USFSettingEntryWidget_Checkbox](../../CodeAPI/classUSFSettingEntryWidget__Checkbox/).
* **Bind Widget Requirements:** 
    * `CheckboxWidget` (UCheckbox): The checkbox widget representing the boolean setting value.
* **Project Setup:** Intended to be assigned to the `Setting Entry Widget Classes` map in **Edit > Project Settings > Plugins > Settings Framework** with `SFSettingDefinition_Bool` as the key.

A checkbox reflecting the state of a bool setting.

---

## 2 - WBP_SettingEntry_Slider

* **Native parent class:** [USFSettingEntryWidget_Slider](../../CodeAPI/classUSFSettingEntryWidget__Slider/).
* **Bind Widget Requirements:** 
    * `SliderWidget` (UUAnalogSlider):  The analog slider widget representing the scalar setting value.
* **Project Setup:** Intended to be assigned to the `Setting Entry Widget Classes` map in **Edit > Project Settings > Plugins > Settings Framework** with `SFSettingDefinition_Scalar` as the key.

A number slider reflecting the state of a scalar/numeric setting.

---

## 3 - WBP_SettingEntry_Rotator

* **Native parent class:** [USFSettingEntryWidget_Rotator](../../CodeAPI/classUSFSettingEntryWidget__Rotator/).
* **Bind Widget Requirements:** 
    * `RotatorWidget` (UCommonRotator): The checkbox widget representing the boolean setting value.
* **Project Setup:** Intended to be assigned to the `Setting Entry Widget Classes` map in **Edit > Project Settings > Plugins > Settings Framework** with `SFSettingDefinition_Discrete` as the key.

A rotator button that cycles through the options of a discrete setting.

---

## 4 - WBP_SettingEntry_Keybind

* **Native parent class:** [USFSettingEntryWidget_Keybind](../../CodeAPI/classUSFSettingEntryWidget__Keybind/).
* **Bind Widget Requirements:** 
    * `KBMPrimaryButton` (UCommonButtonBase): Button widget for displaying and changing the primary KBM keybind.
    * `KBMSecondaryButton` (UCommonButtonBase): Button widget for displaying and changing the secondary KBM keybind.
    * `GamepadButton` (UCommonButtonBase): Button widget for displaying and changing the gamepad keybind.
* **Project Setup:** Intended to be assigned to the `Setting Entry Widget Classes` map in **Edit > Project Settings > Plugins > Settings Framework** with `SFSettingDefinition_Key` as the key.

Keybinding buttons for a keybind setting. Each button corresponds to a slot of the keybind data structure. After a keybind button is clicked, the widget listens to the next input from the user and register that as the new keybind. The property `Is Focusable` must be true on the `WBP_SettingEntry_Keybind` widget for this to work.

When using mouse and keyboard, only the `KBMPrimaryButton` and `KBMSecondaryButton` buttons are visible. Similarly, when using a gamepad, only the `GamepadButton` is visible.