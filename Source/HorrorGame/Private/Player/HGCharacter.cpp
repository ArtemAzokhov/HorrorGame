// Horror Game. All Rights Reserved.

#include "Player/HGCharacter.h"

AHGCharacter::AHGCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AHGCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AHGCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AHGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
