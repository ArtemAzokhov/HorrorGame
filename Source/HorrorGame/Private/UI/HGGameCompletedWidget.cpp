// Horror Game. All Rights Reserved.

#include "UI/HGGameCompletedWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UHGGameCompletedWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    check(BackToMenuButton);
    BackToMenuButton->OnClicked.AddDynamic(this, &ThisClass::OnBackToMenu);

    check(AgainButton);
    AgainButton->OnClicked.AddDynamic(this, &ThisClass::OnAgain);
}

void UHGGameCompletedWidget::OnBackToMenu()
{
    if (!MenuLevel.IsNull())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName(MenuLevel.GetAssetName()));
    }
}

void UHGGameCompletedWidget::OnAgain()
{
    const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
    UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}
