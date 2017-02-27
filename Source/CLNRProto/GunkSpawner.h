// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GunkSpawner.generated.h"

UCLASS()
class CLNRPROTO_API AGunkSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunkSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AGunk> GunkBlueprint;

	TArray<AGunk*> GunkArray;
	int ArraySize;
	int GunkAmount = 1000000;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;
	
};
