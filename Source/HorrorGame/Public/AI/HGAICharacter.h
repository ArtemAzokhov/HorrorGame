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

protected:
    virtual void BeginPlay() override;


};
