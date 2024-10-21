// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HGAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class HORRORGAME_API AHGAICharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AHGAICharacter();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    TObjectPtr<UBehaviorTree> BehsaviorTreeAsset;

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    TObjectPtr<UAnimMontage> AttackAnimMontage;

    void StartAttack();
    void StopAttack();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Attack")
    float DamageRadius = 200.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Attack", meta = (EditCondition = "!DoFullDamage"))
    float DamageAmount = 50.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Attack")
    bool DoFullDamage = false;

    virtual void BeginPlay() override;
};
