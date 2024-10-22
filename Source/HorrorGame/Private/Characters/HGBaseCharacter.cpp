// Horror Game. All Rights Reserved.

#include "Characters/HGBaseCharacter.h"
#include "Components/HGHealthComponent.h"
#include "Components/HGWeaponComponent.h"

AHGBaseCharacter::AHGBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    HealthComponent = CreateDefaultSubobject<UHGHealthComponent>("HealthComponent");
    WeaponComponent = CreateDefaultSubobject<UHGWeaponComponent>("WeaponComponent");
}

void AHGBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    HealthComponent->OnDeath.AddUObject(this, &ThisClass::Death);
}

void AHGBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AHGBaseCharacter::Death() {}
