// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "SFSaveGame.generated.h"

/**
 * @brief SaveGame object to serialize setting data.
 *
 * SaveGame object to serialize setting data.
 */
UCLASS()
class SETTINGSFRAMEWORK_API USFSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	/**
	* A map of setting Gameplay Tags to their serialized string values. The actual value objects are reconstructed from these strings when loading the save game.
	*/
	UPROPERTY(VisibleAnywhere, Category = "SFSaveGame")
	TMap<FGameplayTag, FString> SerializedSettings;
};
