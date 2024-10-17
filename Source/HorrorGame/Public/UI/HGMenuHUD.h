// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HGMenuHUD.generated.h"

class UHGMenuWidget;

UCLASS()
class HORRORGAME_API AHGMenuHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UHGMenuWidget> MenuWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TObjectPtr<UHGMenuWidget> MenuWidget;
};
