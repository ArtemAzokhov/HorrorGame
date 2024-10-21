// Horror Game. All Rights Reserved.

#include "UI/HGGameplayWidget.h"
#include "Components/ProgressBar.h"
#include "Components/HGHealthComponent.h"
#include "Components/TextBlock.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameplayWidget, All, All);

void UHGGameplayWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (const auto HealthComponent = GetOwningPlayerPawn()->FindComponentByClass<UHGHealthComponent>())
    {
        HealthComponent->OnHealthChanged.AddUObject(this, &ThisClass::OnHealthChanged);
    }
}

void UHGGameplayWidget::OnHealthChanged(float Health, float HealthDelta)
{
    UE_LOG(LogGameplayWidget, Display, TEXT("Health: %f | HealthDelta: %f"), Health, HealthDelta);

    if (HealtTextBlock)
    {
        FText HealthText = FText::Format(                                      //
            NSLOCTEXT("Gameplay", "HealthFormat", "Health: {0} (Delta: {1})"), // for localization
            FText::AsNumber(Health),                                           //
            FText::AsNumber(HealthDelta));

        HealtTextBlock->SetText(HealthText);
    }

    UpdateHealthBar();
}

void UHGGameplayWidget::UpdateHealthBar()
{
    UE_LOG(LogGameplayWidget, Display, TEXT("UpdateHealthBar"));

    if (HealthBar)
    {
        const auto Percent = GetOwningPlayerPawn()->FindComponentByClass<UHGHealthComponent>()->GetHealthPercent();
        HealthBar->SetPercent(Percent);
    }
}
