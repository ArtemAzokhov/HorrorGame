// Horror Game. All Rights Reserved.

#include "UI/HGGameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UHGGameOverWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    check(BackToMenuButton);
    BackToMenuButton->OnClicked.AddDynamic(this, &ThisClass::OnBackToMenu);
}

void UHGGameOverWidget::OnBackToMenu()
{
    if (!MenuLevel.IsNull())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName(MenuLevel.GetAssetName()));
    }
}
