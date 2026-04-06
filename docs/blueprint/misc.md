This guide covers the miscellaneous Blueprints that support the SettingsFramework skeletal UI suite. These include helper widgets for building complex UI elements, as well as the standard CommonUI and EnhancedInput configuration assets required to make the system fully functional.

**⚠️ Note:** Ensure **Show Plugin Content** is enabled in your Content Drawer's settings to locate these Blueprints.

---

## 1. WBP_TabList

* **Located in:** `/Plugins/SettingsFramework/UI/TabList/`
* **Native parent class:** `UCommonTabListWidgetBase`

This widget acts as the standard container for category tab buttons. It is utilized by both the main `WBP_SettingsScreen` (for navigating root categories) and `WBP_CategoryTab_Branch` (for navigating sub-categories). 

---

## 2. WBP_MajorTabButton & WBP_MinorTabButton

* **Located in:** `/Plugins/SettingsFramework/UI/TabList/`
* **Native parent class:** [USFCategoryTabButtonBase](../../CodeAPI/classUSFCategoryTabButtonBase/)
* **Project Setup:** Intended to be assigned to the `Root Tab Button Class` and `Branch Tab Button Class` in **Edit > Project Settings > Plugins > Settings Framework**.

These widgets serve as the clickable tab buttons populated inside the tab list widgets. `WBP_MajorTabButton` is intended for root-level categories on the main settings screen, while `WBP_MinorTabButton` is used for sub-categories within a branch tab. 

Both widgets override the parent class function `SetCategoryData` to automatically read the provided category asset and update their display text to match the category's assigned name.

---

## 3. Entry Widget Helpers

* **Located in:** `/Plugins/SettingsFramework/UI/SettingEntries/Components/`

These are modular helper widgets designed to build the interactive components of your Setting Entries.

**WBP_OptionRotator & WBP_OptionRotator_Pip:** Structural components used by `WBP_SettingEntryWidget_Rotator` to build a fully functional, navigable rotator widget for discrete settings.

**WBP_KeybindButton:** The core interactive component for `WBP_SettingEntryWidget_Keybind`. Its primary function is to interpret a structural `Key` value and display its name as a string on the UI.

---

## 4. Input Actions

* **Located in:** `/Plugins/SettingsFramework/UI/InputActions/`

These are Unreal Engine **Enhanced Input Actions** utilized for triggering specific subsystem commands directly from the UI (such as saving, reverting settings, or switching tabs). 

While they are already hooked up to their respective widgets (like `WBP_SettingsScreen`), they are not mapped to any keys by default. You must assign these Input Actions to specific keys or gamepad buttons inside your project's Input Mapping Context (IMC) for them to be triggered by the player.

---

## 5. Text & Button Styles

* **Located in:** `/Plugins/SettingsFramework/UI/Styles/`

These are foundational styling Data Assets used to enforce visual consistency across the skeletal UI, adhering strictly to the **CommonUI** styling paradigm. They control the default typography and button states (Normal, Hovered, Pressed) used throughout the plugin's widgets.