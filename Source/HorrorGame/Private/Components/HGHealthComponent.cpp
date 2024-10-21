// Horror Game. All Rights Reserved.

#include "Components/HGHealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

UHGHealthComponent::UHGHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UHGHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    check(MaxHealth > 0);

    SetHealth(MaxHealth);

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &ThisClass::OnTakeDamage);
    }
}

void UHGHealthComponent::OnTakeDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    UE_LOG(LogHealthComponent, Display, TEXT("TakeDamage: %f"), Damage);
    ApplayDamage(Damage);
}

void UHGHealthComponent::ApplayDamage(float Damage)
{
    if (Damage <= 0.0f || IsDead() || !GetWorld()) return;
    UE_LOG(LogHealthComponent, Display, TEXT("ApplayDamage: %f"), Damage);
    SetHealth(Health - Damage);

    if (IsDead())
    {
        OnDeath.Broadcast();
    }
}

void UHGHealthComponent::SetHealth(float NewHealth)
{
    const auto NextHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
    const auto HealthDelta = NextHealth - Health;

    Health = NextHealth;
    OnHealthChanged.Broadcast(Health, HealthDelta);
    UE_LOG(LogHealthComponent, Display, TEXT("Health: %f | HealthDelta: %f"), Health, HealthDelta);
}
