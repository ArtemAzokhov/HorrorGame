// Horror Game. All Rights Reserved.

#include "Player/HGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/HGHealthComponent.h"
#include "Components/CapsuleComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogAHGCharacter, All, All);

AHGCharacter::AHGCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    HealthComponent = CreateDefaultSubobject<UHGHealthComponent>("HealthComponent");
}

void AHGCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (auto* PC = Cast<APlayerController>(GetController()))
    {
        if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(CharacterMappingContext, 0);
        }
    }

    HealthComponent->OnDeath.AddUObject(this, &ThisClass::Death);
}

void AHGCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AHGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    auto* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    check(Input);
    if (MoveAction)
    {
        Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
    }
    else
    {
        UE_LOG(LogAHGCharacter, Error, TEXT("MoveAction isn't set!"));
    }

    if (LookAction)
    {
        Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
    }
    else
    {
        UE_LOG(LogAHGCharacter, Error, TEXT("LookAction isn't set!"));
    }
}

void AHGCharacter::Move(const FInputActionValue& InputActionValue)
{
    AddMovementInput(GetActorForwardVector(), InputActionValue.Get<FVector2D>().Y);
    AddMovementInput(GetActorRightVector(), InputActionValue.Get<FVector2D>().X);
}

void AHGCharacter::Look(const FInputActionValue& InputActionValue)
{
    AddControllerYawInput(InputActionValue.Get<FVector2D>().X);
    AddControllerPitchInput(-InputActionValue.Get<FVector2D>().Y);
}

void AHGCharacter::Death()
{
    UE_LOG(LogAHGCharacter, Display, TEXT("Player %s is dead"), *GetName());
    GetCharacterMovement()->DisableMovement();
    // PlayAnimMontage(DeathAnimMontage);

    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetMesh()->SetSimulatePhysics(true);
}
