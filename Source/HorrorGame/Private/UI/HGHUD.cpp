// Horror Game. All Rights Reserved.

#include "UI/HGHUD.h"
#include "UI/HGGameplayWidget.h"
#include "UI/HGGameOverWidget.h"

void AHGHUD::BeginPlay()
{
    Super::BeginPlay();

    GameplayWidget = CreateWidget<UHGGameplayWidget>(GetWorld(), GameplayWidgetClass);
    check(GameplayWidget);
    GameWidgets.Add(EUIGameState::GameInProgress, GameplayWidget);

    GameOverWidget = CreateWidget<UHGGameOverWidget>(GetWorld(), GameOverWidgetClass);
    check(GameOverWidget);
    GameWidgets.Add(EUIGameState::GameOver, GameOverWidget);

    for (auto& [UIState, GameWidget] : GameWidgets)
    {
        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Collapsed);
    }

    SetUIGameState(EUIGameState::GameInProgress);
}

void AHGHUD::SetUIGameState(EUIGameState InGameState)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Collapsed);
    }

    if (GameWidgets.Contains(InGameState))
    {
        CurrentWidget = GameWidgets[InGameState];
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    }

    GameState = InGameState;
}
