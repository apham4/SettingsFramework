# 1 - Project Overview

UE5 plugin SettingsFramework for game settings management with skeletal settings screen widgets using CommonUI and EnhancedInput.

Widgets support KBM and Gamepad.

Example host project: https://github.com/apham4/SFHost



# 2 - Engine Version

Unreal Engine 5.6+



# 3 - Set Up Instructions

* Install Unreal Editor (version 5.6+) through the Epic Game Launcher and start a blank C++ project or open an existing one (instructions from Epic: https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-cpp-quick-start).
* Drop the content of the plugin into the host project's directory under /Plugins/SettingsFramework.
* Open the host project in Unreal Editor.
* Navigate to Edit > Plugins > search for SettingsFramework and make sure it is enabled. Restart the Editor if prompted.
* After the Editor has been restarted, open the Content Drawer (bottom left). Make sure "Plugin Content" is enabled in options (gear icon on top right of Content Drawer).
* In the Content Drawer, to create new setting defintion assets, right click > Miscellaneous > Data Asset. Select between SF Bool Setting/SF Discrete Setting/SF Keybind Setting/SF Scalar Setting depending on your desired data type.
* In the Content Drawer, to create new setting category assets, right click > Miscellaneous > Data Asset. Select SF Setting Category. A leaf category can contain setting definition assets, and a branch category can contain setting category assets.
* In the Content Drawer, to create a new setting registry asset, right click > Miscellaneous > Data Asset. Select SF Settings Registry. This is the main registry that should contain your root categories.
* Navigate to Edit > Project Settings > Settings Framework. Set your SettingsRegistry asset, as well as any other desired configuration options. The Settings UI section is required for setting up CommonUI widgets.
* In the directory structure on the left side of the Content Drawer, navigate to /Plugins/SettingsFramework/UI/. This folder contains all the skeletal CommonUI widgets demonstrating the usage of the data assets and Settings Subsystem. 
* If you want to use these widgets directly, set them in the previously mentioned Project Settings field. Integrate the WBP\_SettingsScreen widget into the CommonUI interface of your project so that it can be added to your CommonActivatableWidgetStack.
* The plugin should now be functional.

