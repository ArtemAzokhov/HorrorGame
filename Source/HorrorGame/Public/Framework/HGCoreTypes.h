#pragma once

#include "HGCoreTypes.generated.h"

UENUM()
enum class EHGGameState : uint8
{
    Waiting = 0,
    GameInProgress,
    GamePause,
    GameOver,
    GameCompleted
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameStateChangedSignature, EHGGameState);

//health
DECLARE_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, float);

DECLARE_MULTICAST_DELEGATE(FOnExitSignature);