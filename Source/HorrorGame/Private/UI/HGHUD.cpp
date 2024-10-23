// Horror Game. All Rights Reserved.

#include "UI/HGHUD.h"
#include "UI/HGGameplayWidget.h"
#include "UI/HGGameOverWidget.h"
#include "UI/HGPauseWidget.h"
#include "UI/HGGameCompletedWidget.h"
#include "Framework/HGGameMode.h"
#include "Framework/HGUtils.h"

void AHGHUD::BeginPlay()
{
    Super::BeginPlay();

    GameplayWidget = CreateWidget<UHGGameplayWidget>(GetWorld(), GameplayWidgetClass);
    check(GameplayWidget);
    GameWidgets.Add(EHGGameState::GameInProgress, GameplayWidget);

    GameOverWidget = CreateWidget<UHGGameOverWidget>(GetWorld(), GameOverWidgetClass);
    check(GameOverWidget);
    GameWidgets.Add(EHGGameState::GameOver, GameOverWidget);

    PauseWidget = CreateWidget<UHGPauseWidget>(GetWorld(), PauseWidgetClass);
    check(PauseWidget);
    GameWidgets.Add(EHGGameState::GamePause, PauseWidget);

    GameCompletedWidget = CreateWidget<UHGGameCompletedWidget>(GetWorld(), GameCompletedWidgetClass);
    check(GameCompletedWidget);
    GameWidgets.Add(EHGGameState::GameCompleted, GameCompletedWidget);

    for (auto& [UIState, GameWidget] : GameWidgets)
    {
        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Collapsed);
    }

    if (GetWorld())
    {
        const auto GameMode = Cast<AHGGameMode>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnGameStateChanged.AddUObject(this, &ThisClass::OnGameStateChanged);
        }
    }
}

void AHGHUD::OnGameStateChanged(EHGGameState State)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Collapsed);
    }

    if (GameWidgets.Contains(State))
    {
        CurrentWidget = GameWidgets[State];
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    }

    bool bShowCursor = State != EHGGameState::GameInProgress;
    WorldUtils::SetUIInput(GetWorld(), bShowCursor);
}
