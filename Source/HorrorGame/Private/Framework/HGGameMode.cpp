// Horror Game. All Rights Reserved.

#include "Framework/HGGameMode.h"
#include "Player/HGCharacter.h"
#include "Player/HGPlayerController.h"
#include "UI/HGHUD.h"
#include "Framework/HGUtils.h"

AHGGameMode::AHGGameMode()
{
    DefaultPawnClass = AHGCharacter::StaticClass();
    PlayerControllerClass = AHGPlayerController::StaticClass();
    HUDClass = AHGHUD::StaticClass();
}

void AHGGameMode::StartPlay()
{
    Super::StartPlay();

    WorldUtils::SetUIInput(GetWorld(), false);
}
