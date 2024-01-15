// Copyright : OK

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cloud.generated.h"

UCLASS()
class LIFEVAIR_API ACloud : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACloud();
    
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    FVector InitialPosition;
    float Time;
    const float Scale = 10.0f; // Adjust this value as needed

    // Function to update the vector's position
    UFUNCTION(BlueprintCallable)
    void AnimateVector(FVector& Vector, float Time, float Scale);
    
    UFUNCTION(BlueprintCallable)
    void TestOui();
    
    /**
     * prout Prints a string to the log, and optionally, to the screen
     * If Print To Log is true, it will be visible in the Output Log window.  Otherwise it will be logged only as 'Verbose', so it generally won't show up.
     */
    UFUNCTION(BlueprintCallable, meta=(Keywords = "log print", AdvancedDisplay = "2"), Category="Utilities|String")
    static void PrintString();
    
    UFUNCTION(BlueprintPure, Category="Math|Random")
    static int32 RandomInteger2(int32 Max);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
