// Copyright 2026 Anh Pham. All Rights Reserved.


#include "SFFunctionLibrary.h"
#include "SFSettingsSubsystem.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "GameFramework/PlayerController.h"
#include "Engine/LocalPlayer.h"
#include "CommonInputSubsystem.h"
#include "CommonInputTypeEnum.h"

USFSettingsSubsystem* USFFunctionLibrary::GetSettingsSubsystem(const UObject* WorldContextObject)
{
	const UWorld* world = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	const UGameInstance* gameInstance = IsValid(world) ? world->GetGameInstance() : nullptr;
	USFSettingsSubsystem* settingsSubsystem = IsValid(gameInstance) ? gameInstance->GetSubsystem<USFSettingsSubsystem>() : nullptr;
	return settingsSubsystem;
}

ECommonInputType USFFunctionLibrary::GetCurrentInputMethod(const UObject* WorldContextObject)
{
	const UWorld* world = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	APlayerController* playerController = IsValid(world) ? world->GetFirstPlayerController() : nullptr;
	ULocalPlayer* localPlayer = IsValid(playerController) ? playerController->GetLocalPlayer() : nullptr;
	UCommonInputSubsystem* commonInputSubsystem = IsValid(localPlayer) ? localPlayer->GetSubsystem<UCommonInputSubsystem>() : nullptr;
	return IsValid(commonInputSubsystem) ? commonInputSubsystem->GetCurrentInputType() : ECommonInputType::MouseAndKeyboard;
}

