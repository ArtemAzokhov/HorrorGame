// Horror Game. All Rights Reserved.

#include "Player/HGCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/HGWeaponComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogAHGCharacter, All, All);

AHGCharacter::AHGCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
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

    if (AttackAction && WeaponComponent)
    {
        Input->BindAction(AttackAction, ETriggerEvent::Triggered, WeaponComponent, &UHGWeaponComponent::StartAttack);
    }
    else
    {
        UE_LOG(LogAHGCharacter, Error, TEXT("AttackAction isn't set!"));
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
