// Copyright 2026 Anh Pham. All Rights Reserved.

#include "Core/SFSettingValue.h"
#include "Core/SFLogs.h"
#include "Misc/StringOutputDevice.h"

#pragma region USFSettingValue_Scalar
FString USFSettingValue_Scalar::SerializeToString() const
{
    // SanitizeFloat ensures consistent formatting regardless of locale
    return FString::SanitizeFloat(Value);
}

void USFSettingValue_Scalar::DeserializeFromString(const FString& InString)
{
    Value = FCString::Atof(*InString);
}

bool USFSettingValue_Scalar::Equals(const USFSettingValue* Other) const
{
    const USFSettingValue_Scalar* asScalar = Cast<USFSettingValue_Scalar>(Other);
    return asScalar && FMath::IsNearlyEqual(Value, asScalar->Value);
}
#pragma endregion  

#pragma region USFSettingValue_Boolean
FString USFSettingValue_Bool::SerializeToString() const
{
    return Value ? TEXT("1") : TEXT("0");
}

void USFSettingValue_Bool::DeserializeFromString(const FString& InString)
{
    Value = InString.ToBool();
}

bool USFSettingValue_Bool::Equals(const USFSettingValue* Other) const
{
    const USFSettingValue_Bool* asBool = Cast<USFSettingValue_Bool>(Other);
    return asBool && (Value == asBool->Value);
}
#pragma endregion

#pragma region USFSettingValue_Tag
FString USFSettingValue_Tag::SerializeToString() const
{
    return Value.ToString();
}

void USFSettingValue_Tag::DeserializeFromString(const FString& InString)
{
    Value = FGameplayTag::RequestGameplayTag(FName(*InString));
}

bool USFSettingValue_Tag::Equals(const USFSettingValue* Other) const
{
    const USFSettingValue_Tag* asTag = Cast<USFSettingValue_Tag>(Other);
    return asTag && (Value == asTag->Value);
}
#pragma endregion

#pragma region USFSettingValue_String
FString USFSettingValue_String::SerializeToString() const
{
    return Value;
}

void USFSettingValue_String::DeserializeFromString(const FString& InString)
{
    Value = InString;
}

bool USFSettingValue_String::Equals(const USFSettingValue* Other) const
{
    const USFSettingValue_String* asString = Cast<USFSettingValue_String>(Other);
    return asString && (Value.Equals(asString->Value, ESearchCase::IgnoreCase));
}
#pragma endregion

#pragma region USFSettingValue_Key
FString USFSettingValue_Key::SerializeToString() const
{
    FString OutString;
	FSFKeybindValueData::StaticStruct()->ExportText(OutString, &Value, nullptr, nullptr, EPropertyPortFlags::PPF_None, nullptr);
    return OutString;
}

void USFSettingValue_Key::DeserializeFromString(const FString& InString)
{
    if (InString.IsEmpty())
    {
        return;
    }
    // String output device to capture error messages from ExportText.
    FStringOutputDevice errorLog;
    FSFKeybindValueData::StaticStruct()->ImportText(*InString, &Value, nullptr, EPropertyPortFlags::PPF_None, &errorLog, TEXT("USFSettingValue_Key"));

    if (!errorLog.IsEmpty())
    {
        UE_LOG(LogSettingsFramework, Warning, TEXT("[SettingsFramework] Failed to deserialize keybind value from string: %s. Error: %s"), *InString, *errorLog);
    }
}

bool USFSettingValue_Key::Equals(const USFSettingValue* Other) const
{
    const USFSettingValue_Key* asKey = Cast<USFSettingValue_Key>(Other);
    return asKey && (Value == asKey->Value);
}
#pragma endregion
