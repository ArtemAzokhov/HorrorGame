// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/HGBaseCharacter.h"
#include "HGCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class HORRORGAME_API AHGCharacter : public AHGBaseCharacter
{
    GENERATED_BODY()

public:
    AHGCharacter();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputMappingContext> CharacterMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputAction> MoveAction;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputAction> LookAction;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputAction> AttackAction;

    UFUNCTION()
    void Move(const FInputActionValue& InputActionValue);

    UFUNCTION()
    void Look(const FInputActionValue& InputActionValue);

    virtual void Death() override;
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
