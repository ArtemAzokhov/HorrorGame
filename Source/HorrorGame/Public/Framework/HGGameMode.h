// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Framework/HGCoreTypes.h"
#include "HGGameMode.generated.h"

UCLASS()
class HORRORGAME_API AHGGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AHGGameMode();

    FOnGameStateChangedSignature OnGameStateChanged;

    virtual void StartPlay() override;
    virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
    virtual bool ClearPause() override;

private:
    EHGGameState GameState = EHGGameState::Waiting;

    void SetGameState(EHGGameState State);
    void GameOver();
};
