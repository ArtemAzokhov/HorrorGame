// Horror Game. All Rights Reserved.

#include "Player/HGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

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

    OnTakeAnyDamage.AddDynamic(this, &ThisClass::OnTakeDamage);
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
    if(!MoveAction.IsNull())
    {
        Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
    }
    else
    {
        UE_LOG(LogAHGCharacter, Error, TEXT("MoveAction isn't set!"));
    }
}

void AHGCharacter::Move(const FInputActionValue& InputActionValue)
{
    AddMovementInput(FVector::ForwardVector, InputActionValue.Get<FVector2D>().Y);
    AddMovementInput(FVector::RightVector, InputActionValue.Get<FVector2D>().X);
}

void AHGCharacter::OnTakeDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    UE_LOG(LogTemp, Display, TEXT("TakeDamage"));
    Health -= Damage;
    UE_LOG(LogTemp, Display, TEXT("Health: %f"), Health);
    if (FMath::IsNearlyZero(Health))
    {
        Death();
    }
}

void AHGCharacter::Death()
{
    UE_LOG(LogTemp, Display, TEXT("Dead"));
    GetCharacterMovement()->DisableMovement();
    OnDeath.Broadcast();
}
