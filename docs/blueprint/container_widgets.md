This guide covers the container widgets provided in the SettingsFramework skeletal UI suite. It explains their primary functions, the native C++ classes they extend, and any additional Blueprint functionality they introduce on top of their parent classes.

**⚠️ Note:** Ensure **Show Plugin Content** is enabled in your Content Drawer's settings to locate these Blueprints.

---

## 1 - WBP_SettingsScreen

* **Located in:*** `/Plugins/Settings Framework/UI/`.
* ***Native parent class:** [USFSettingsScreen](/CodeAPI/classUSFSettingsScreen/).
* **Bind Widget Requirements:** 
    * `CategoryTabList` (UCommonTabListWidgetBase): Displays the buttons used to navigate between root categories.
    * `TabContentSwitcher` (UCommonActivatableWidgetSwitcher): Displays the content corresponding to the currently selected root category.

This is the primary entry point and root container for the settings UI, designed to be pushed to your project's CommonUI Activatable Widget Stack. Upon initialization, this widget queries the Settings Subsystem for your defined categories and settings, automatically generating and populating the appropriate tabs and setting entries.

**Category Nesting:** The provided skeletal UI intentionally supports only one level of category nesting for UX reason. This means only root categories can be Branch-type categories. Any Branch-type categories placed deeper in the hierarchy will be ignored during UI construction.

**Input Actions:** This widget provides fields to map Input Actions for subsystem commands (Saving, Reverting, and Resetting to Default). By default, these are populated with `IA_UI_Save`, `IA_UI_Revert`, and `IA_UI_ResetToDefault`. **Note:** You must map these Input Actions to actual keys/buttons inside your project's Input Mapping Context (IMC) for them to function.

---

## 2 - WBP_SettingInfoDisplay

* **Located in:*** `/Plugins/Settings Framework/UI/Components/`.
* ***Native parent class:** [USFSettingInfoDisplay](/CodeAPI/classUSFSettingInfoDisplay/).

Positioned on the right side of the `WBP_SettingsScreen`, this widget displays metadata (Name and Description) for the currently focused setting entry. It automatically hides itself when the focused setting is a Keybind, as those generally do not require detailed descriptions.

It overrides the `DisplaySettingByDefinition` function from its parent class to update the on-screen text with the `Display Name` and `Description` from the provided setting definition.

---

## 3 - WBP_CategoryTab_Branch

* **Located in:*** `/Plugins/Settings Framework/UI/Components/`.
* ***Native parent class:** [USFCategoryTab_Branch](/CodeAPI/classUSFCategoryTab__Branch/).
* **Bind Widget Requirements:** 
    * `SubCategoryTabList` (UCommonTabListWidgetBase): Displays the buttons used to navigate between sub-categories.
    * `TabContentSwitcher` (UCommonActivatableWidgetSwitcher): Displays the content corresponding to the currently selected sub-category.
* **Project Setup:** Intended to be assigned to the `Branch Tab Content Class` in **Edit > Project Settings > Plugins > Settings Framework**.

This widget represents the content area for a Branch-type setting category. It is dynamically added to the `TabContentSwitcher` inside `WBP_SettingsScreen` and generates sub-tabs for each of its child categories. 

Because the skeletal UI is restricted to one level of nesting, any child category that is also a Branch-type will be ignored by this widget.

---

## 4 - WBP_CategoryTab_Leaf

* **Located in:*** `/Plugins/Settings Framework/UI/Components/`.
* ***Native parent class:** [USFCategoryTab_Leaf](/CodeAPI/classUSFCategoryTab__Leaf/).
* **Project Setup:** Intended to be assigned to the `Leaf Tab Content Class` in **Edit** > **Project Settings** > **Plugins** > **Settings Framework**.

This widget represents the content area for a Leaf-type setting category. It can be dynamically added to the `TabContentSwitcher` of either the main `WBP_SettingsScreen` (if the root is a leaf) or a `WBP_CategoryTab_Branch` widget. It is responsible for displaying the category's actual settings by spawning one or more `WBP_SettingGroup` widgets.

---

## 5 - WBP_SettingGroup

* **Located in:*** `/Plugins/Settings Framework/UI/Components/`.
* ***Native parent class:** [USFSettingGroupWidget](/CodeAPI/classUSFSettingGroupWidget/).
* **Project Setup:** Intended to be assigned to the `Setting Group Widget Class` in **Edit** > **Project Settings** > **Plugins** > **Settings Framework**.

This widget displays a group's setting entries in a vertical box, with the group name on top. It's displayed inside WBP_CategoryTab_Leaf. If a leaf-type category does not use setting groups, then all of its settings are displayed in one group without a name.

This widget acts as a visual wrapper, displaying a formatted group name above a vertical list of setting entries. It is spawned directly inside `WBP_CategoryTab_Leaf`. If a Leaf-type category does not utilize grouped settings, all of its settings will simply be displayed inside a single `WBP_SettingGroup` with its header name hidden.