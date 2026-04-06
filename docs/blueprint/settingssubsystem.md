The Settings Subsystem (`USFSettingsSubsystem`) is the core backend engine of the Settings Framework. It is the singleton with which you interact at runtime to manage the runtime states of your settings, listen to setting changes, check their visibility/editability conditions, and save or load them from disk.

This guide goes over the Settings Subsystem's functionalities in Blueprint. For more details about `USFSettingsSubsystem`, refer to its full [C++ API reference](../../CodeAPI/classUSFSettingsSubsystem/).

---

## 1 - Accessing the Settings Subsystem

The Settings Subsystem is a **Game Instance Subsystem**, meaning it is automatically created when the game starts and persists throughout the entire game session. You do not need to spawn or initialize it yourself.


To access it in any Blueprint, use Unreal Editor's default node for getting game instance subsystems (top node) or the included library helper function (bottom node) as shown below.


<iframe src="https://blueprintue.com/render/fl4z90vr/" width="100%" height="250" scrolling="yes" allowfullscreen></iframe>

---

## 2 - Core Event Dispatchers

You can bind to these event dispatchers on the Settings Subsystem to react to setting changes globally. This is useful for updating UI or applying settings in your game logic (like changing the volume when the volume setting changes).

* **On Settings Initialized:** Fired when the settings registry has finished loading and saved values have been retrieved from disk. Do not attempt to read or apply settings before this is fired.
* **On Setting Value Changed:** Fired whenever a setting's current active value is modified, reverted, or reset to default. **Provides:** `Setting Tag`, `New Value`.
* **On Setting Value Saved:** Fired when a setting is permanently written to disk. **Provides:** `Setting Tag`, `Saved Value`.

<iframe src="https://blueprintue.com/render/ge2c15o3/" width="100%" height="300" scrolling="yes" allowfullscreen></iframe>

---

## 3 - Accessing Data Assets

These functions allow you to retrieve the underlying Data Assets from your Settings Registry. If you want to get categories' and settings' info to populate your UI, or if you just want to access a specific setting asset to get its properties, use these functions:

* **Get Root Categories:** Returns an array of all top-level setting category Data Assets defined in your active Settings Registry. This is useful for building the main navigation level of your settings menu.
* **Get Setting Definition:** Takes a setting Gameplay Tag and returns its associated setting definition Data Asset. You can use this to read static information directly from the asset, such as its Display Name, Description, or specific sub-class data. Returns null if the tag isn't registered.

<iframe src="https://blueprintue.com/render/efp1y9f4/" width="100%" height="250" scrolling="no" allowfullscreen></iframe>

---

## 4 - Reading Setting Values

If you simply want to know the value of a setting to apply it to your game, use these functions:

* **Is Initialized:** Returns true if the subsystem is fully loaded and ready.
* **Get Setting Value:** Returns the *current active value* of the setting associated with a specific Gameplay Tag. (If the user changed a setting but hasn't saved it yet, this returns the new unsaved value).
* **Get Saved Setting Value:** Returns the value currently written to the save file on disk.
* **Get Default Setting Value:** Returns the default value defined in the Data Asset.

<iframe src="https://blueprintue.com/render/9anrgl7g/" width="100%" height="550" scrolling="no" allowfullscreen></iframe>

---

## 5 - Modifying & Saving Setting Values

These functions are typically used by Settings Menu widgets to manipulate setting data.

* **Set Setting Value:** Updates the current active value of a setting. **Note: This does NOT save to disk.** 
* **Is Setting Dirty:** Returns true if the current active value is different from the saved value.
* **Are Any Settings Dirty:** Returns true if *any* setting in the registry has unsaved changes. Useful for enabling/disabling a global "Apply Changes" button.
* **Save Settings:** Serializes and saves all current active setting values to disk, overwriting the old save file.
* **Revert Setting / Revert Settings:** Discards the current active value(s) and reverts back to the last saved value(s). **Note: This does NOT save to disk.**
* **Reset Setting To Default / Reset Settings To Default:** Discards the current active value(s) and resets to the default value(s). **Note: This does NOT save to disk.** 

<iframe src="https://blueprintue.com/render/whce62hf/" width="100%" height="650" scrolling="no" allowfullscreen></iframe>

---

## 6 - Conditions & Validation

The subsystem automatically evaluates the setting condition logic you set up in the **Visibility Conditions** and **Editability Conditions** fileds in your stting definition Data Assets.

* **Is Setting Visible:** Evaluates the visibility conditions. Returns true if the setting should currently be shown in the UI.
* **Is Setting Editable:** Evaluates the editability conditions. Returns true if the setting should be enabled/interactable.

<iframe src="https://blueprintue.com/render/ezyf0h4g/" width="100%" height="300" scrolling="no" allowfullscreen></iframe>

---

## 7 - Keybinding Utilities
If you are building a custom Keybinding UI, the subsystem provides functions to handle input conflicts.

* **Get Keybinding Collision:** Checks if a specific `Key` value is already bound to another setting within the provided Collision Channels. You can pass a `SettingTagToIgnore` so a setting doesn't collide with itself.
* **Update Keybinding:** Attempts to apply a new keybinding. If a collision is detected, it handles it based on your chosen `ResolutionPolicy` (Allow Duplicate, Overwrite, or Swap).

<iframe src="https://blueprintue.com/render/89rsx66t/" width="100%" height="450" scrolling="no" allowfullscreen></iframe>