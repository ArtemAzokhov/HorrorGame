// Horror Game. All Rights Reserved.

#include "Framework/HGMenuGameMode.h"
#include "Framework/HGUtils.h"

void AHGMenuGameMode::StartPlay()
{
    Super::StartPlay();

    WorldUtils::SetUIInput(GetWorld(), true);
}
