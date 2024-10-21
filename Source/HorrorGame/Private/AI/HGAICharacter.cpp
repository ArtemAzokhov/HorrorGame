// Horror Game. All Rights Reserved.

#include "AI/HGAICharacter.h"
#include "AI/HGAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AHGAICharacter::AHGAICharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    AutoPossessAI = EAutoPossessAI::Disabled;
    AIControllerClass = AHGAIController::StaticClass();

    bUseControllerRotationYaw = false;
    if (GetCharacterMovement())
    {
        GetCharacterMovement()->bUseControllerDesiredRotation = true;
        GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
    }
}

void AHGAICharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AHGAICharacter::StartAttack()
{
    

    UGameplayStatics::ApplyRadialDamage(GetWorld(), //
        DamageAmount,                               //
        GetActorLocation(),                         //
        DamageRadius,                               //
        UDamageType::StaticClass(),                 //
        {GetOwner()},                               //
        this,                                       //
        GetController(),                            //
        DoFullDamage);
       
    auto Dur = PlayAnimMontage(AttackAnimMontage);
    UE_LOG(LogTemp, Display, TEXT("Attack enemy! %f"), Dur);
}

void AHGAICharacter::StopAttack()
{
    UE_LOG(LogTemp, Display, TEXT(" Stop Attack !"));
}