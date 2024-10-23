// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HGBaseCharacter.generated.h"

class UHGHealthComponent;
class UHGWeaponComponent;

UCLASS()
class HORRORGAME_API AHGBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AHGBaseCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UHGHealthComponent* HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UHGWeaponComponent* WeaponComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    TObjectPtr<UAnimMontage> DeathAnimMontage;

    virtual void BeginPlay() override;
    virtual void Death();
};
