// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATank::ATank() 
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(GetRootComponent());

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    CameraComp->SetupAttachment(SpringArm);
}