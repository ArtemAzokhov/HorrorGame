// Horror Game. All Rights Reserved.

#include "UI/HGMenuHUD.h"
#include "UI/HGMenuWidget.h"

void AHGMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    MenuWidget = CreateWidget<UHGMenuWidget>(GetWorld(), MenuWidgetClass);
    check(MenuWidget);

    MenuWidget->AddToViewport();
}
