// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HGAIController.generated.h"

class UHGAIPerceptionComponent;

UCLASS()
class HORRORGAME_API AHGAIController : public AAIController
{
    GENERATED_BODY()

public:
    AHGAIController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UHGAIPerceptionComponent* HGAIPerceptionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FName FocusOnKeyName = "EnemyActor";

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DelataTime) override;

private:
    TObjectPtr<AActor> GetFocusOnActor() const;
};
