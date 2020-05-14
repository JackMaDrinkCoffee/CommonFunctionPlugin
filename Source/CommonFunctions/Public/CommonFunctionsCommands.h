// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "CommonFunctionsStyle.h"

class FCommonFunctionsCommands : public TCommands<FCommonFunctionsCommands>
{
public:

	FCommonFunctionsCommands()
		: TCommands<FCommonFunctionsCommands>(TEXT("CommonFunctions"), NSLOCTEXT("Contexts", "CommonFunctions", "CommonFunctions Plugin"), NAME_None, FCommonFunctionsStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
