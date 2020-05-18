// Fill out your copyright notice in the Description page of Project Settings.


#include "JM_FunctionLib.h"

#include "Misc/FileHelper.h"

bool UJM_FunctionLib::SaveStrAsFile(FString Str, FString Path)
{
    
    if (FFileHelper::SaveStringToFile(Str,*Path,FFileHelper::EEncodingOptions::ForceUTF8))
    {
        UE_LOG(LogTemp,Warning,TEXT("Save Str Success!"));
        return true;
    }else
    {
        UE_LOG(LogTemp,Warning,TEXT("Save Str Failed!"));
        return false;
    }

    
}
