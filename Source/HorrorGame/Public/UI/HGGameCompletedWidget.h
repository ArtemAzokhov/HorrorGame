// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HGGameCompletedWidget.generated.h"

class UButton;

UCLASS()
class HORRORGAME_API UHGGameCompletedWidget : public UUserWidget
{
	GENERATED_BODY()

	protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> BackToMenuButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> AgainButton;

    UPROPERTY(EditDefaultsOnly)
    TSoftObjectPtr<UWorld> MenuLevel;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnBackToMenu();

    UFUNCTION()
    void OnAgain();
	
};
