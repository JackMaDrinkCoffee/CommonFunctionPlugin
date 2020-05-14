// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonFunctions.h"
#include "CommonFunctionsStyle.h"
#include "CommonFunctionsCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "Misc/FileHelper.h"

static const FName CommonFunctionsTabName("CommonFunctions");

#define LOCTEXT_NAMESPACE "FCommonFunctionsModule"

void FCommonFunctionsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FCommonFunctionsStyle::Initialize();
	FCommonFunctionsStyle::ReloadTextures();

	FCommonFunctionsCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FCommonFunctionsCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FCommonFunctionsModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FCommonFunctionsModule::RegisterMenus));
}

void FCommonFunctionsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FCommonFunctionsStyle::Shutdown();

	FCommonFunctionsCommands::Unregister();
}

void FCommonFunctionsModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	// FText DialogText = FText::Format(
	// 						LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
	// 						FText::FromString(TEXT("FCommonFunctionsModule::PluginButtonClicked()")),
	// 						FText::FromString(TEXT("CommonFunctions.cpp"))
	// 				   );
	// FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FCommonFunctionsModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FCommonFunctionsCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FCommonFunctionsCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

bool FCommonFunctionsModule::SaveStringasFile(FString Str,  FString FileName)
{
	if (FFileHelper::SaveStringToFile(Str,*FileName,FFileHelper::EEncodingOptions::ForceUTF8))
	{
		UE_LOG(LogTemp,Warning,TEXT("Save Str Success!"));
		return true;
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("Save Str Failed!"));
		return false;
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCommonFunctionsModule, CommonFunctions)