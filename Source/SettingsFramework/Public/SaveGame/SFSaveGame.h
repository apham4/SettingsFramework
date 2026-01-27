// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "SFSaveGame.generated.h"

/**
 * SaveGame to store settings data.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, Category = "SFSaveGame")
	TMap<FGameplayTag, FString> SerializedSettings;
};
