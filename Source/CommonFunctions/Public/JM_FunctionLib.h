// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/ObjectMacros.h"

#include "JM_FunctionLib.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class COMMONFUNCTIONS_API UJM_FunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static bool SaveStrAsFile(FString Str,FString Path);
//  UFUNCTION(BlueprintCallable,Category="CommonFunctions")

	
	
};
