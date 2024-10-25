// Horror Game. All Rights Reserved.

#include "Characters/HGBaseCharacter.h"
#include "Components/HGHealthComponent.h"
#include "Components/HGWeaponComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogHGBaseCharacter, All, All);

AHGBaseCharacter::AHGBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    HealthComponent = CreateDefaultSubobject<UHGHealthComponent>("HealthComponent");
    WeaponComponent = CreateDefaultSubobject<UHGWeaponComponent>("WeaponComponent");
}

void AHGBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    HealthComponent->OnDeath.AddUObject(this, &ThisClass::Death);
}

void AHGBaseCharacter::Death()
{
    UE_LOG(LogHGBaseCharacter, Display, TEXT("Player %s is dead"), *GetName());
    GetCharacterMovement()->DisableMovement();
    if (DeathAnimMontage != nullptr)
    {
        PlayAnimMontage(DeathAnimMontage);
    }
    else
    {
        GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

        GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        GetMesh()->SetSimulatePhysics(true);
    }
}
