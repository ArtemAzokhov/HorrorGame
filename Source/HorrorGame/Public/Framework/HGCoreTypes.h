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

DECLARE_MULTICAST_DELEGATE(FOnDeathSignature);
