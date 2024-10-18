// Horror Game. All Rights Reserved.

#include "UI/HGGameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UHGGameOverWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    check(BackToMenuButton);
    BackToMenuButton->OnClicked.AddDynamic(this, &ThisClass::OnBackToMenu);

    check(AgainButton);
    AgainButton->OnClicked.AddDynamic(this, &ThisClass::OnAgain);
}

void UHGGameOverWidget::OnBackToMenu()
{
    if (!MenuLevel.IsNull())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName(MenuLevel.GetAssetName()));
    }
}

void UHGGameOverWidget::OnAgain()
{
    const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
    UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}
