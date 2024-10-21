// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HGGameplayWidget.generated.h"

class UProgressBar;
class UTextBlock;

UCLASS()
class HORRORGAME_API UHGGameplayWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UProgressBar> HealthBar;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> HealtTextBlock;

    virtual void NativeOnInitialized() override;

    void OnHealthChanged(float Health, float HealthDelta);

    void UpdateHealthBar();
};
