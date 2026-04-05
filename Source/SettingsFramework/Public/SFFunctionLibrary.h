// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonInputTypeEnum.h"
#include "SFFunctionLibrary.generated.h"

/**
 * @brief Utility function library for the SettingsFramework.
 *
 * Utility function library for the SettingsFramework.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Get the USFSettingsSubsystem instance.
	* @param WorldContextObject World context object to get the world from. Can be any object that has a valid world, such as an actor, a component, a widget, etc.
	* @return The USFSettingsSubsystem instance.
	*/
	UFUNCTION(BlueprintPure, Category = "SFFunctionLibrary", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext))
	static class USFSettingsSubsystem* GetSettingsSubsystem(const UObject* WorldContextObject);

	/**
	* Retrieves the current CommonUI input method (e.g., Gamepad, MouseAndKeyboard).
	* @param WorldContextObject World context object to get the world from. Can be any object that has a valid world, such as an actor, a component, a widget, etc.
	* @return The active ECommonInputType. Defaults to MouseAndKeyboard if unable to determine.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Input|CommonUI", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext))
	static ECommonInputType GetCurrentInputMethod(const UObject* WorldContextObject);
};
