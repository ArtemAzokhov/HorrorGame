// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Framework/HGCoreTypes.h"
#include "HGHealthComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HORRORGAME_API UHGHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHGHealthComponent();

    FOnDeathSignature OnDeath;
    FOnHealthChangedSignature OnHealthChanged;

    float GetHealthPercent() const { return Health / MaxHealth; }

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
    float MaxHealth{100.0f};

    UPROPERTY(EditDefaultsOnly, Category = "Sound")
    TObjectPtr<USoundBase> ImpactSound;

    virtual void BeginPlay() override;

private:
    float Health = 0.0f;

    UFUNCTION()
    void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    bool IsDead() const { return FMath::IsNearlyZero(Health); }
    void ApplayDamage(float Damage);
    void SetHealth(float NewHealth);
};
