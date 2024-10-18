// Horror Game. All Rights Reserved.

#include "Player/HGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Framework/HGUtils.h"

void AHGPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (!InputComponent) return;

    auto* Input = Cast<UEnhancedInputComponent>(InputComponent);
    check(Input);
    Input->BindAction(PauseAction, ETriggerEvent::Started, this, &ThisClass::OnPauseGame);
}

void AHGPlayerController::OnPauseGame()
{
    SetPause(!IsPaused());
}