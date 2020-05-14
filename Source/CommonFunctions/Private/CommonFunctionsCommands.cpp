// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonFunctionsCommands.h"

#define LOCTEXT_NAMESPACE "FCommonFunctionsModule"

void FCommonFunctionsCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "CommonFunctions", "Execute CommonFunctions action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
