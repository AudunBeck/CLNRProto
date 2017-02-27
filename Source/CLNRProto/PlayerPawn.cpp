// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNRProto.h"
#include "PlayerPawn.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Create a camera and a visible object

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	// Attach our camera and visible object to our root component. Offset and rotate the camera.

	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!CurrentVelocity.IsZero())
		{
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			FVector Direction = NewLocation - GetActorLocation();
			FRotator Rot = FRotationMatrix::MakeFromX(Direction).Rotator();
			SetActorRotation(Rot);
			SetActorLocation(NewLocation);

		}
	}

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerPawn::InteractPressed);
	InputComponent->BindAction("Interact", IE_Released, this, &APlayerPawn::InteractReleased);

	InputComponent->BindAxis("Move_X", this, &APlayerPawn::Move_X);
	InputComponent->BindAxis("Move_Y", this, &APlayerPawn::Move_Y);

}

void APlayerPawn::InteractPressed()
{
	Interacting = true;
}

void APlayerPawn::InteractReleased()
{
	Interacting = false;
}

void APlayerPawn::Move_X(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * MoveSpeed;
}

void APlayerPawn::Move_Y(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * MoveSpeed;
}
