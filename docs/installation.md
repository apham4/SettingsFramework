# Setup

Guide on the requirements, installation, and usage scenarios for the SettingsFramework plugin.

## 1 - Requirements

* **Engine Version:** Unreal Engine 5.6 or later.
* **Required Engine Plugins:** The following built-in engine plugins must be enabled in your project (`Edit > Plugins`):
    * `CommonUI`
    * `EnhancedInput`



## 2 - Installation

You can install the SettingsFramework plugin either via the Fab/Unreal Engine Marketplace (recommended for Blueprint-only projects) or by compiling it from source code (for C++ projects).



### 2.1 Install via Fab/Unreal Engine Marketplace

1. Download the plugin from [Fab/Marketplace](/Placeholder/).
2. Open your project in the Unreal Editor.
3. Navigate to **Edit > Plugins**.
4. Search for "SettingsFramework" in the Installed section and check the box to enable it.
5. Install plugin prerequisites if prompted.
6. Restart the editor when prompted.



### 2.2 Install via Source Code

1. Download the plugin source code repository from [GitHub](https://github.com/apham4/SettingsFramework).
2. Navigate to your project's `Plugins` directory. It is in your root directory, on the same level as your `.uproject` file. Create a `Plugins` folder if there isn't one.
3. Extract/Drop the plugin source code into the `Plugins` directory so that `SettingsFramework.uplugin` is in `Plugins/SettingsFramework/`.
4. Right-click your `.uproject` file and select **Generate Visual Studio project files**.
5. After building and opening the Unreal Editor, the plugin should be automatically enabled.



## 3 - Getting Started & Usage Scenarios

The SettingsFramework is designed to be highly modular. Whether you just want the backend data management, want to use the skeletal UI widgets, or want to extend the system with C++, follow the path that matches your use case.



### 3.1 Scenario 1: Settings Data & Management Only

*Best for users who want to handle all UI themselves but want the plugin to manage setting definitions, values, and serialization.*

1. **Create setting definitions:** In the Content Browser, right-click > **Miscellaneous** > **Data Asset**. Select between `SF Bool Setting`, `SF Discrete Setting`, `SF Keybind Setting`, or `SF Scalar Setting` based on your needs.
2. **Create categories:** In the Content Browser, right-click > **Miscellaneous** > **Data Asset** and select `SF Setting Category`. Leaf Categories contain your setting definition assets. Branch categories contain other setting category assets.
3. **Create the registry:** In the Content Browser, right-click > **Miscellaneous** > **Data Asset** and select `SF Settings Registry`. Add your root categories to this registry.
4. **Configure Project Settings:** Navigate to **Edit** > **Project Settings** > **Settings Framework**.
    * Set the **Settings Registry** field to the asset you created in step 3.
    * Properties like Save Game Slot Name, Max Update Depth, and Default Keybind Collision Resolution have default values provided, but can be tweaked here if needed.
5. **Manage data at runtime:** The `SFSettingsSubsystem` handles the backend. It provides public API functions for saving, reverting, and resetting settings to default, which you can call explicitly via Blueprint or C++.
    * Refer to the `SFSettingsSubsystem`'s [Blueprint Guide](/Placeholder/) or [C++ API Reference](../CodeAPI/classUSFSettingsSubsystem/) for details.



### 3.2 Scenario 2: Skeletal UI Widgets

*Best for users who want a basic but functional settings menu out-of-the-box using CommonUI with the backend integrated.*

1. **Follow the steps in Scenario 1** to set up your Data Assets.
2. **Locate the provided widget blueprints:** In the Content Browser, enable **Show Plugin Content**. Navigate to `/Plugins/SettingsFramework/UI/` to find the skeletal CommonUI widget blueprints provided by the plugin.
3. **Configure UI in Project Settings:** In **Edit** > **Project Settings** > **SettingsFramework**, you must fill in all the fields located under the **Settings UI** category to point to your desired widget classes. This is for the widgets to know which inner widget classes to populate themselves with.
4. **Map Input Actions:** The plugin provides Input Actions (located in `/Plugins/SettingsFramework/UI/InputActions/`) that are already hooked up to the skeletal widgets. However, they need to be mapped to specific inputs in your project's Input Mapping Context to be triggered.
5. **Display the menu:** Integrate the `WBP_SettingsScreen` widget into your project's UI layout so that it can be pushed to your `CommonActivatableWidgetStack`.



**⚠️ Note on CommonUI dependency:** The skeletal widgets rely heavily on Unreal Engine's `CommonUI` plugin. Because Epic Games frequently updates and refactors `CommonUI` with each major engine release, migrating this plugin to future Unreal Engine versions (e.g., UE 5.7+) may require manual updates to the provided widget Blueprints to resolve deprecations or structural changes.



### 3.3 Scenario 3: Custom Extensions in C++

*Best for programmers who want to create custom setting types, override subsystem behavior, or interact with the plugin natively.*

1. **Follow the Steps in Scenario 1 & 2** as needed for your project's baseline setup.
2. **Modify Build.cs:** To expose the plugin's classes to your project's native code, you must add `"SettingsFramework"` to your module's dependencies. Open your project's `[ProjectName].Build.cs` file and update the `PublicDependencyModuleNames`:

        ```csharp
        PublicDependencyModuleNames.AddRange(new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "SettingsFramework" // <-- Add this line
        });
        ```

3. **Recompile:** Generate project files and recompile your project. You can now include SettingsFramework headers and extend its base C++ classes.
    * Refer to the full [C++ API Reference](/api) for details.