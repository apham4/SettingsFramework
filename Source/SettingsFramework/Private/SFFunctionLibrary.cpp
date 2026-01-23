// Copyright 2026 Anh Pham. All Rights Reserved.


#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"

USFSettingsSubsystem* USFFunctionLibrary::GetSettingsSubsystem(const UObject* WorldContextObject)
{
	const UWorld* world = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	const UGameInstance* gameInstance = IsValid(world) ? world->GetGameInstance() : nullptr;
	USFSettingsSubsystem* settingsSubsystem = IsValid(gameInstance) ? gameInstance->GetSubsystem<USFSettingsSubsystem>() : nullptr;
	return settingsSubsystem;
}