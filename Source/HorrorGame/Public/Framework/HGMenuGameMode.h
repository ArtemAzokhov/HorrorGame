// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HGMenuGameMode.generated.h"

UCLASS()
class HORRORGAME_API AHGMenuGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    virtual void StartPlay() override;
};
