// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HGGameOverWidget.generated.h"

class UButton;

UCLASS()
class HORRORGAME_API UHGGameOverWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> BackToMenuButton;

    UPROPERTY(EditDefaultsOnly)
    TSoftObjectPtr<UWorld> MenuLevel;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnBackToMenu();
};
