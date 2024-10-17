// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HGMenuWidget.generated.h"

class UButton;

UCLASS()
class HORRORGAME_API UHGMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> StartGameButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> CloseGameButton;

    UPROPERTY(EditDefaultsOnly)
    TSoftObjectPtr<UWorld> GameLevel;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnCloseGame();
};
