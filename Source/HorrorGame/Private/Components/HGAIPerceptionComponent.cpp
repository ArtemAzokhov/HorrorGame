// Horror Game. All Rights Reserved.

#include "Components/HGAIPerceptionComponent.h"
#include "AIController.h"
#include "Perception/AISense_Sight.h"

TObjectPtr<AActor> UHGAIPerceptionComponent::GetClosestEnemy() const
{
    TArray<AActor*> PerceivedActors;
    GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerceivedActors);
    if (PerceivedActors.Num() == 0) return nullptr;

    const auto Controller = Cast<AAIController>(GetOwner());
    if (!Controller) return nullptr;

    const auto Pawn = Controller->GetPawn();
    if (!Pawn) return nullptr;

    double BestDistance = MAX_FLT;
    TObjectPtr<AActor> BestPawn = nullptr;
    for (const auto PerceivedActor : PerceivedActors)
    {
        const auto CurrenDistance = (PerceivedActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
        if (CurrenDistance < BestDistance)
        {
            BestDistance = CurrenDistance;
            BestPawn = PerceivedActor;
        }
    }

    return BestPawn;
}
