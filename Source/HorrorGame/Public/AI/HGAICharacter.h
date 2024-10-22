// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/HGBaseCharacter.h"
#include "HGAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class HORRORGAME_API AHGAICharacter : public AHGBaseCharacter
{
    GENERATED_BODY()

public:
    AHGAICharacter();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    TObjectPtr<UBehaviorTree> BehsaviorTreeAsset;

protected:
    virtual void Death() override;
    virtual void BeginPlay() override;
};
