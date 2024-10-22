// Horror Game. All Rights Reserved.

#include "Components/HGWeaponComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Weapon/HGNaturalWeapon.h"

UHGWeaponComponent::UHGWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UHGWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapon();
}

void UHGWeaponComponent::SpawnWeapon()
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character || !GetWorld()) return;

    auto Weapon = GetWorld()->SpawnActor<AHGNaturalWeapon>(WeaponClass);
    if (Weapon)
    {
        Weapon->SetOwner(Character);
        AttachWeaponToSocket(Weapon, Character->GetMesh(), WeaponEquipSocketName);
    }

    CurrentWeapon = Weapon;
}

void UHGWeaponComponent::AttachWeaponToSocket(AHGNaturalWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName)
{
    if (!Weapon || !SceneComponent) return;
    FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
    Weapon->AttachToComponent(SceneComponent, AttachmentRules, SocketName);
}

void UHGWeaponComponent::StartAttack()
{
    if (!CanAttack()) return;
    UE_LOG(LogTemp, Display, TEXT("Attack by %s!"), *GetOwner()->GetName());
    CurrentWeapon->StartAttack();
}

void UHGWeaponComponent::StopAttack()
{
    UE_LOG(LogTemp, Display, TEXT("Stop Attack !"));
}

bool UHGWeaponComponent::CanAttack() const
{
    return CurrentWeapon != nullptr;
}