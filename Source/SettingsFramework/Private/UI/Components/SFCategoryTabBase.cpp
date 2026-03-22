// Copyright 2026 Anh Pham. All Rights Reserved.


#include "UI/Components/SFCategoryTabBase.h"

#pragma region Initialization
void USFCategoryTabBase::SetCategory(class USFSettingCategory* InSettingCategory)
{
	SettingCategory = InSettingCategory;
}
#pragma endregion

#pragma region CommonUI Navigation
UWidget* USFCategoryTabBase::GetDesiredFocusTarget() const
{
	return nullptr;
}
#pragma endregion