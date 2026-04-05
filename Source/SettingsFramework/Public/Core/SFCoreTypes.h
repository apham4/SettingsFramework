// Copyright 2026 Anh Pham. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/InputChord.h"
#include "SFCoreTypes.generated.h"

#pragma region Backend
/**
 * @brief A struct representing a single discrete option in a list for a setting.
 *
 * A struct representing a single discrete option in a list for a setting (e.g. "High", "1920x1080", "Monitor 1"), with a localized display name and an associated value object of the abstract type USFSettingValue. 
 * This allows for great flexibility in defining what each option represents and how it behaves when selected.
 * 
 * This struct is used as the value for USFSettingDefinition_Discrete.
 * @note @blueprinttype
 */
USTRUCT(BlueprintType)
struct FSFSettingOption
{
    GENERATED_BODY()

    /**
    * The player-facing name of the option.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFSettingOption")
    FText DisplayName;

	/**
	* The value associated with this option, can be of any USFSettingValue-derived type.
	* @note @ea @brw @i
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "SFSettingOption")
	TObjectPtr<class USFSettingValue> Value;
};

/**
 * @brief A struct holding the three standard binding slots for an action.
 *
 * A struct holding the three standard binding slots for an action: KBM Primary, KBM Secondary, and Gamepad. 
 * 
 * This struct is used as the underlying value for USFSettingValue_Key.
 * @note @blueprinttype
 */
USTRUCT(BlueprintType)
struct FSFKeybindValueData
{
    GENERATED_BODY()

    /** 
	* The primary KBM key for this action.
	* @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFKeybindValueData")
    FKey KBMPrimary;

    /**
    * The secondary KBM key for this action.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFKeybindValueData")
    FKey KBMSecondary;

    /**
    * The Gamepad key for this action.
    * @note @ea @brw
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFKeybindValueData")
    FKey Gamepad;

    bool operator==(const FSFKeybindValueData& Other) const
    {
        return KBMPrimary == Other.KBMPrimary
            && KBMSecondary == Other.KBMSecondary
            && Gamepad == Other.Gamepad;
    }
};

/**
 * Enum defining how to resolve keybind collisions when adding a new keybind.
 */
UENUM(BlueprintType)
enum class ESFKeybindCollisionResolution : uint8
{
	// If collision found, allow the new binding to be added alongside the existing one, even if they are the same action or same input.
	AllowDuplicate      UMETA(DisplayName = "Allow Duplicate Bindings"),
	// If collision found, allow the new binding but remove the existing one(s) that conflict with it.
	Overwrite           UMETA(DisplayName = "Overwrite Existing Binding"),
    // If collision found, allow the new binding but also change the conflicting existing binding to the new binding's old value.
	Swap                UMETA(DisplayName = "Swap Bindings"),
};
#pragma endregion

#pragma region UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSettingEntryFocused, const struct FGameplayTag&, SettingTag);
#pragma endregion