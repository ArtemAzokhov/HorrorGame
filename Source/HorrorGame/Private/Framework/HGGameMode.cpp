// Horror Game. All Rights Reserved.

#include "Framework/HGGameMode.h"
#include "Player/HGCharacter.h"
#include "Player/HGPlayerController.h"
#include "UI/HGHUD.h"
#include "Components/HGHealthComponent.h"
#include "World/HGDoor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

AHGGameMode::AHGGameMode()
{
    DefaultPawnClass = AHGCharacter::StaticClass();
    PlayerControllerClass = AHGPlayerController::StaticClass();
    HUDClass = AHGHUD::StaticClass();
}

void AHGGameMode::StartPlay()
{
    Super::StartPlay();

    SetGameState(EHGGameState::GameInProgress);

    if (GetWorld())
    {
        if (const auto PlayerController = GetWorld()->GetFirstPlayerController())
        {
            if (auto Character = PlayerController->GetPawn<AHGCharacter>())
            {
                if (auto HealthComponent = Character->FindComponentByClass<UHGHealthComponent>())
                {
                    HealthComponent->OnDeath.AddUObject(this, &ThisClass::GameOver);
                }
            }
        }
    }

    FindWinDoor();
}

bool AHGGameMode::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
    const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);
    if (PauseSet)
    {
        SetGameState(EHGGameState::GamePause);
    }

    return PauseSet;
}

bool AHGGameMode::ClearPause()
{
    const auto PauseCleared = Super::ClearPause();
    if (PauseCleared)
    {
        SetGameState(EHGGameState::GameInProgress);
    }

    return PauseCleared;
}

void AHGGameMode::SetGameState(EHGGameState State)
{
    if (GameState == State) return;

    GameState = State;
    OnGameStateChanged.Broadcast(GameState);
}

void AHGGameMode::GameOver()
{
    SetGameState(EHGGameState::GameOver);
    StopPawns();
}

void AHGGameMode::GameComplete()
{
    SetGameState(EHGGameState::GameCompleted);
    StopPawns();
}

void AHGGameMode::FindWinDoor()
{
    if (!GetWorld()) return;

    TArray<AActor*> Doors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHGDoor::StaticClass(), Doors);
    if (Doors.Num() > 0)
    {
        for (const auto Door : Doors)
        {
            if (Door && Door->ActorHasTag(WinTeg))
            {
                const auto WinningDoor = Cast<AHGDoor>(Door);
                WinningDoor->OnExit.AddUObject(this, &ThisClass::GameComplete);
            }
        }
    }
}

void AHGGameMode::StopPawns()
{
    for (auto Pawn : TActorRange<APawn>(GetWorld()))
    {
        if (Pawn)
        {
            Pawn->TurnOff();
            Pawn->DisableInput(nullptr);
        }
    }
}
