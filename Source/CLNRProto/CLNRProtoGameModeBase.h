// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "CLNRProtoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CLNRPROTO_API ACLNRProtoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		int maxPoints = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		int currentPoints = 0;
	
	
};
