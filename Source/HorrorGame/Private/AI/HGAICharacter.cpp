// Horror Game. All Rights Reserved.

#include "AI/HGAICharacter.h"
#include "AI/HGAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "BrainComponent.h"

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

void AHGAICharacter::Death()
{
    UE_LOG(LogTemp, Display, TEXT("Player %s is dead"), *GetName());
    GetCharacterMovement()->DisableMovement();
    // PlayAnimMontage(DeathAnimMontage);

    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetMesh()->SetSimulatePhysics(true);

        const auto HGController = Cast<AAIController>(Controller);
    if (HGController && HGController->BrainComponent)
    {
        HGController->BrainComponent->Cleanup();
    }
}