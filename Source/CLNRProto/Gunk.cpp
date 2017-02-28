// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNRProto.h"
#include "Gunk.h"
#include "PlayerPawn.h"
#include "CLNRProtoGameModeBase.h"


// Sets default values
AGunk::AGunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SquareComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SquareComponent;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &AGunk::OnOverlap);
	Cast<UShapeComponent>(RootComponent)->OnComponentEndOverlap.AddDynamic(this, &AGunk::EndOnOverlap);

}

// Called when the game starts or when spawned
void AGunk::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetAuthGameMode<ACLNRProtoGameModeBase>()->maxPoints += 1;
	
}

// Called every frame
void AGunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (OverlapPlayer == true)
	{
		APlayerPawn* Player = Cast<APlayerPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (Player->Interacting == true)
		{
			AmountLeft -= DeltaTime * 30;
		}
	}


	if (AmountLeft <= 0)
	{
		GetWorld()->GetAuthGameMode<ACLNRProtoGameModeBase>()->currentPoints += 1;
		Destroy();
	}
	SetActorScale3D(FVector(AmountLeft / 100, AmountLeft / 100, AmountLeft / 100));
}

void AGunk::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APlayerPawn::StaticClass()))
	{
		OverlapPlayer = true;
	}
}

void AGunk::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
	if (OtherActor->IsA(APlayerPawn::StaticClass()))
	{
		OverlapPlayer = false;
	}
	
}