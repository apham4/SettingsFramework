// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SFFunctionLibrary.generated.h"

/**
 * Utility function library for Settings Framework.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "SFFunctionLibrary", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext))
	static class USFSettingsSubsystem* GetSettingsSubsystem(const UObject* WorldContextObject);
};
