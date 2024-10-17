// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HGGameMode.generated.h"

UCLASS()
class HORRORGAME_API AHGGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AHGGameMode();

    virtual void StartPlay() override;
};
