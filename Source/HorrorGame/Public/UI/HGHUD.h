// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HGHUD.generated.h"

class UHGGameplayWidget;
class UHGGameOverWidget;

UENUM()
enum class EUIGameState : uint8
{
    GameInProgress = 0,
    GameOver,
    GameCompleted
};

UCLASS()
class HORRORGAME_API AHGHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UHGGameplayWidget> GameplayWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UHGGameOverWidget> GameOverWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TObjectPtr<UHGGameplayWidget> GameplayWidget;

    UPROPERTY()
    TObjectPtr<UHGGameOverWidget> GameOverWidget;

    UPROPERTY()
    TMap<EUIGameState, TObjectPtr<UUserWidget>> GameWidgets;

    UPROPERTY()
    TObjectPtr<UUserWidget> CurrentWidget;

    EUIGameState GameState;

    void SetUIGameState(EUIGameState InGameState);
};
