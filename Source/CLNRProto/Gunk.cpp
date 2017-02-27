// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNRProto.h"
#include "Gunk.h"


// Sets default values
AGunk::AGunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGunk::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

