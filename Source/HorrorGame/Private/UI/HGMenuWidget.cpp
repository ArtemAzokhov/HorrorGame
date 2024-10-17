// Horror Game. All Rights Reserved.

#include "UI/HGMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UHGMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    check(StartGameButton);
    StartGameButton->OnClicked.AddDynamic(this, &ThisClass::OnStartGame);

    check(CloseGameButton);
    CloseGameButton->OnClicked.AddDynamic(this, &ThisClass::OnCloseGame);
}

void UHGMenuWidget::OnStartGame()
{
    if (!GameLevel.IsNull())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName(GameLevel.GetAssetName()));
    }
}

void UHGMenuWidget::OnCloseGame()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(), EQuitPreference::Quit, false);
}
