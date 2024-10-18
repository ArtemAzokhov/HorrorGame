// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HGPlayerController.generated.h"

class UInputAction;

UCLASS()
class HORRORGAME_API AHGPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    void OnPauseGame();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputAction> PauseAction;

    virtual void SetupInputComponent() override;
};
