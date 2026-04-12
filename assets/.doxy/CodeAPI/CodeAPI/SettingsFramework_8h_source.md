

# File SettingsFramework.h

[**File List**](files.md) **>** [**Public**](dir_f5fe102898a9b0642bc955593c0a287a.md) **>** [**SettingsFramework.h**](SettingsFramework_8h.md)

[Go to the documentation of this file](SettingsFramework_8h.md)


```C++
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FSettingsFrameworkModule : public IModuleInterface
{
public:

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
```


