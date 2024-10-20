// Horror Game. All Rights Reserved.


#include "AI/HGAIController.h"
#include "AI/HGAICharacter.h"

void AHGAIController::OnPossess(APawn* InPawn) 
{
	Super::OnPossess(InPawn);

	const auto AICharacter = Cast<AHGAICharacter>(InPawn);
	if(AICharacter)
    {
        RunBehaviorTree(AICharacter->BehsaviorTreeAsset);
	}
}
