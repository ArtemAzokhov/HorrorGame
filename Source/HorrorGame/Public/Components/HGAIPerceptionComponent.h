// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "HGAIPerceptionComponent.generated.h"

UCLASS()
class HORRORGAME_API UHGAIPerceptionComponent : public UAIPerceptionComponent
{
    GENERATED_BODY()

public:
    TObjectPtr<AActor> GetClosestEnemy() const;
};
