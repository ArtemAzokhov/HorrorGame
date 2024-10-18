// Horror Game. All Rights Reserved.

#include "UI/HGPauseWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"

void UHGPauseWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    check(ResumeButton);
    ResumeButton->OnClicked.AddDynamic(this, &ThisClass::OnResume);

    check(ResetButton);
    ResetButton->OnClicked.AddDynamic(this, &ThisClass::OnReset);

    check(MainMenuButton);
    MainMenuButton->OnClicked.AddDynamic(this, &ThisClass::OnMainMenu);
}

void UHGPauseWidget::OnResume()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}

void UHGPauseWidget::OnReset()
{
    const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
    UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}

void UHGPauseWidget::OnMainMenu()
{
    if (!MenuLevel.IsNull())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName(MenuLevel.GetAssetName()));
    }
}
