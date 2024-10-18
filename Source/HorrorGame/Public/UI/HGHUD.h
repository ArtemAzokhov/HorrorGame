// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Framework/HGCoreTypes.h"
#include "HGHUD.generated.h"

class UHGGameplayWidget;
class UHGGameOverWidget;
class UHGPauseWidget;

UCLASS()
class HORRORGAME_API AHGHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UHGGameplayWidget> GameplayWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UHGGameOverWidget> GameOverWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UHGPauseWidget> PauseWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TObjectPtr<UHGGameplayWidget> GameplayWidget;

    UPROPERTY()
    TObjectPtr<UHGGameOverWidget> GameOverWidget;

    UPROPERTY()
    TObjectPtr<UHGPauseWidget> PauseWidget;

    UPROPERTY()
    TMap<EHGGameState, TObjectPtr<UUserWidget>> GameWidgets;

    UPROPERTY()
    TObjectPtr<UUserWidget> CurrentWidget;

    void OnGameStateChanged(EHGGameState State);
};
