// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATank::ATank() 
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(GetRootComponent());

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    CameraComp->SetupAttachment(SpringArm);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) 
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ATank::Move);
}

void ATank::Move(float Value) 
{
    FVector DeltaLocation = FVector::ZeroVector;
    DeltaLocation.X = MovementSpeed * Value;
    AddActorLocalOffset(DeltaLocation);
    // Logging for dev and debugging.
    // UE_LOG(LogTemp, Warning, TEXT("Value: %f."), Value);
}