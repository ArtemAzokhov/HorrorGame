// Horror Game. All Rights Reserved.

#include "Player/HGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Framework/HGUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAHGPlayerController, All, All);

void AHGPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (!InputComponent) return;

    auto* Input = Cast<UEnhancedInputComponent>(InputComponent);
    check(Input);

    if(PauseAction)
    {
        PauseAction->bTriggerWhenPaused = true;
        Input->BindAction(PauseAction, ETriggerEvent::Started, this, &ThisClass::OnPauseGame);
    }
    else
    {
        UE_LOG(LogAHGPlayerController, Error, TEXT("PauseAction isn't set!"));
    }
}

void AHGPlayerController::OnPauseGame()
{
    SetPause(!IsPaused());
}