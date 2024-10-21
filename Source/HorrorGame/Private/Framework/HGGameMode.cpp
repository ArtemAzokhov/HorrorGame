// Horror Game. All Rights Reserved.

#include "Framework/HGGameMode.h"
#include "Player/HGCharacter.h"
#include "Player/HGPlayerController.h"
#include "UI/HGHUD.h"
#include "Components/HGHealthComponent.h"

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
}