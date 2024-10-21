// Horror Game. All Rights Reserved.

#include "AI/HGAIController.h"
#include "AI/HGAICharacter.h"
#include "Components/HGAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AHGAIController::AHGAIController()
{
    HGAIPerceptionComponent = CreateDefaultSubobject<UHGAIPerceptionComponent>("HGAIPerceptionComponent");
    SetPerceptionComponent(*HGAIPerceptionComponent);
}

void AHGAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto AICharacter = Cast<AHGAICharacter>(InPawn);
    if (AICharacter)
    {
        RunBehaviorTree(AICharacter->BehsaviorTreeAsset);
    }
}

void AHGAIController::Tick(float DelataTime)
{
    Super::Tick(DelataTime);

    const auto TargetActor = GetFocusOnActor();
    SetFocus(TargetActor);
}

TObjectPtr<AActor> AHGAIController::GetFocusOnActor() const
{
    if (!GetBlackboardComponent()) return nullptr;

    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}
