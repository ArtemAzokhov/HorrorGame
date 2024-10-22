// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HGWeaponComponent.generated.h"

class AHGNaturalWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HORRORGAME_API UHGWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHGWeaponComponent();

    UFUNCTION()
    void StartAttack();

    UFUNCTION()
    void StopAttack();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<AHGNaturalWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "Weapon_R";

    UPROPERTY()
    AHGNaturalWeapon* CurrentWeapon = nullptr;

    bool CanAttack() const;

    virtual void BeginPlay() override;

private:
    bool bAttackAnimInProgress = false;

    void SpawnWeapon();
    void AttachWeaponToSocket(AHGNaturalWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName);
};
