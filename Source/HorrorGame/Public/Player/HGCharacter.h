// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HGCharacter.generated.h"

UCLASS()
class HORRORGAME_API AHGCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AHGCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
