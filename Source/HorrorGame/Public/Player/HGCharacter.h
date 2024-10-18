// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Framework/HGCoreTypes.h"
#include "HGCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class HORRORGAME_API AHGCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AHGCharacter();

    FOnDeathSignature OnDeath;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputMappingContext> CharacterMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputAction> MoveAction;

    UPROPERTY(EditDefaultsOnly, Category = "Health")
    float Health{100.0f};

    UFUNCTION()
    void Move(const FInputActionValue& InputActionValue);

    UFUNCTION()
    void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    void Death();

    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
