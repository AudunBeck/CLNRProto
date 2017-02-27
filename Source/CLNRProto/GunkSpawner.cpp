// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNRProto.h"
#include "GunkSpawner.h"


// Sets default values
AGunkSpawner::AGunkSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Create a camera and a visible object

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	// Attach our camera and visible object to our root component. Offset and rotate the camera.

	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGunkSpawner::BeginPlay()
{
	Super::BeginPlay();

	/*UWorld* World = GetWorld();

	if (World)
	{
		for (int i{ 0 }; i <= GunkAmount; i++)
		{
			FVector SpawnLocation = GetActorLocation() + FVector(FMath::FRandRange(-50.f, 50.f), FMath::FRandRange(-50.f, 50.f), 0);
			AGunk *tempGunk = World->SpawnActor<AGunk>(GunkBlueprint, SpawnLocation, FRotator::ZeroRotator);
			tempGunk->PlaceInArray = ArraySize;
			GunkArray.Add(tempGunk);
			ArraySize++;
		}
	}

	Destroy();*/
	
}

// Called every frame
void AGunkSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

