// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HGNaturalWeapon.generated.h"

class UBoxComponent;

UCLASS()
class HORRORGAME_API AHGNaturalWeapon : public AActor
{
    GENERATED_BODY()

public:
    AHGNaturalWeapon();

    void StartAttack();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Weapon")
    UBoxComponent* CollisionComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    TObjectPtr<UAnimMontage> AttackAnimMontage;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon", meta = (EditCondition = "!DoFullDamage"))
    float DamageAmount = 50.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    bool DoFullDamage = false;

    virtual void BeginPlay() override;

private:
    bool bAttackInProgress = false;

    UFUNCTION()
    void OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    AController* GetController() const;

    void PlayAnimMontage(UAnimMontage* Animation);
    void InitAnimations();
    void OnDamageStart(USkeletalMeshComponent* MeshComp);
    void OnDamageEnd(USkeletalMeshComponent* MeshComp);
    void OnAttackFinished(USkeletalMeshComponent* MeshComp);

    void CollisionLog();

    template <typename T> //
    T* FindNotifyByClass(UAnimSequenceBase* Animation)
    {
        if (!Animation) return nullptr;

        const auto NotifyEvents = Animation->Notifies;
        for (auto NotifyEvent : NotifyEvents)
        {
            auto AnimNotify = Cast<T>(NotifyEvent.Notify);
            if (AnimNotify != nullptr)
            {
                return AnimNotify;
            }
        }
        return nullptr;
    }
};
