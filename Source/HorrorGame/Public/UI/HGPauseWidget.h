// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HGPauseWidget.generated.h"

class UButton;

UCLASS()
class HORRORGAME_API UHGPauseWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> ResumeButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> ResetButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> MainMenuButton;

    UPROPERTY(EditDefaultsOnly)
    TSoftObjectPtr<UWorld> MenuLevel;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnResume();

    UFUNCTION()
    void OnReset();

    UFUNCTION()
    void OnMainMenu();
};
