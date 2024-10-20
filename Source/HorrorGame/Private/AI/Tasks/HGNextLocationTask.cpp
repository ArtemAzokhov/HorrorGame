// Horror Game. All Rights Reserved.

#include "AI/Tasks/HGNextLocationTask.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UHGNextLocationTask::UHGNextLocationTask()
{
    NodeName = "Next Location";
}

EBTNodeResult::Type UHGNextLocationTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const auto Controller = OwnerComp.GetAIOwner();
    const auto BlackBoard = OwnerComp.GetBlackboardComponent();
    if (!Controller || !BlackBoard) return EBTNodeResult::Failed;

    const auto Pawn = Controller->GetPawn();
    if (!Pawn) return EBTNodeResult::Failed;

    const auto NavSys = UNavigationSystemV1::GetCurrent(Pawn);
    if (!NavSys) return EBTNodeResult::Failed;

    auto Location = Pawn->GetActorLocation();

    FNavLocation NavLocation;
    const auto bIsFound = NavSys->GetRandomReachablePointInRadius(Location, Radius, NavLocation);
    if (!bIsFound) return EBTNodeResult::Failed;

    BlackBoard->SetValueAsVector(LocationKey.SelectedKeyName, NavLocation.Location);
    return EBTNodeResult::Succeeded;
}
