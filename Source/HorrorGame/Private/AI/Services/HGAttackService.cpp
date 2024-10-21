// Horror Game. All Rights Reserved.

#include "AI/Services/HGAttackService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/HGAICharacter.h"

UHGAttackService::UHGAttackService()
{
    NodeName = "Attack";
}

void UHGAttackService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    const auto Controller = OwnerComp.GetAIOwner();
    const auto BlackBoard = OwnerComp.GetBlackboardComponent();

    const auto HasAim = BlackBoard && BlackBoard->GetValueAsObject(EnemyActorKey.SelectedKeyName);

    if (Controller)
    {
        const auto Pawn = Controller->GetPawn<AHGAICharacter>();
        if (Pawn)
        {

            HasAim ? Pawn->StartAttack() : Pawn->StopAttack();
        }
    }
}
