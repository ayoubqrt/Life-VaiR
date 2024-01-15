// Copyright : OK


#include "Cloud.h"

// Sets default values
ACloud::ACloud()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACloud::BeginPlay()
{
	Super::BeginPlay();
    
    InitialPosition = GetActorLocation();
    Time = 0.0f;
}

// Called every frame
void ACloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    Time += DeltaTime;

    // Update vector's position
    FVector NewPosition = InitialPosition;
    AnimateVector(NewPosition, Time, Scale);

    // Set new position
    SetActorLocation(NewPosition);
}

// Called to bind functionality to input
void ACloud::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACloud::AnimateVector(FVector& Vector, float InTime, float InScale)
{
    // Lemniscate of Bernoulli formula
    Vector.X = InitialPosition.X + InScale * FMath::Sqrt(2) * FMath::Cos(InTime) / (FMath::Pow(FMath::Sin(InTime), 2) + 1);
    Vector.Y = InitialPosition.Y + InScale * FMath::Sqrt(2) * FMath::Cos(InTime) * FMath::Sin(InTime) / (FMath::Pow(FMath::Sin(InTime), 2) + 1);
    // Z remains constant
}

void ACloud:TestOui() {}
static void PrintString() {}
