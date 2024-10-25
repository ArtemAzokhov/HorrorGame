// Horror Game. All Rights Reserved.

#include "Weapon/HGNaturalWeapon.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Animations/HGDamageStartAnimNotify.h"
#include "Animations/HGDamageEndAnimNotify.h"
#include "Animations/HGAttackEndAnimNotify.h"

AHGNaturalWeapon::AHGNaturalWeapon()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
    CollisionComponent->InitBoxExtent(FVector(10));
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    SetRootComponent(CollisionComponent);
}

void AHGNaturalWeapon::BeginPlay()
{
    Super::BeginPlay();

    InitAnimations();

    check(CollisionComponent);
    CollisionComponent->IgnoreActorWhenMoving(GetOwner(), true);
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnWeaponOverlap);

    // CollisionLog();
}

void AHGNaturalWeapon::OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, SweepResult.Location);
    if (GetOwner() != OtherActor)
    {
        UGameplayStatics::ApplyPointDamage(
            OtherActor, DamageAmount, SweepResult.ImpactNormal, SweepResult, GetController(), this, UDamageType::StaticClass());

        // for do damage only once
        ACharacter* Character = Cast<ACharacter>(GetOwner());
        if (Character)
        {
            OnDamageEnd(Character->GetMesh());
        }
    }
}

AController* AHGNaturalWeapon::GetController() const
{
    const auto Pawn = Cast<APawn>(GetOwner());
    return Pawn ? Pawn->GetController() : nullptr;
}

void AHGNaturalWeapon::StartAttack()
{
    if (!bAttackInProgress)
    {
        bAttackInProgress = true;
        PlayAnimMontage(AttackAnimMontage);
        UE_LOG(LogTemp, Display, TEXT("StartAttack NaturalWeapon"));
    }
}

void AHGNaturalWeapon::PlayAnimMontage(UAnimMontage* Animation)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;

    Character->PlayAnimMontage(Animation);
}

void AHGNaturalWeapon::InitAnimations()
{
    auto AttackEndAnimNotify = FindNotifyByClass<UHGAttackEndAnimNotify>(AttackAnimMontage);
    if (AttackEndAnimNotify)
    {
        AttackEndAnimNotify->OnNotified.AddUObject(this, &ThisClass::OnAttackFinished);
    }

    auto DamageStartAnimNotify = FindNotifyByClass<UHGDamageStartAnimNotify>(AttackAnimMontage);
    if (DamageStartAnimNotify)
    {
        DamageStartAnimNotify->OnNotified.AddUObject(this, &ThisClass::OnDamageStart);
    }

    auto DamageEndAnimNotify = FindNotifyByClass<UHGDamageEndAnimNotify>(AttackAnimMontage);
    if (DamageEndAnimNotify)
    {
        DamageEndAnimNotify->OnNotified.AddUObject(this, &ThisClass::OnDamageEnd);
    }
}

void AHGNaturalWeapon::OnDamageStart(USkeletalMeshComponent* MeshComp)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character || Character->GetMesh() != MeshComp) return;

    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    // CollisionLog();
}

void AHGNaturalWeapon::OnDamageEnd(USkeletalMeshComponent* MeshComp)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character || Character->GetMesh() != MeshComp) return;

    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    // CollisionLog();
}

void AHGNaturalWeapon::OnAttackFinished(USkeletalMeshComponent* MeshComp)
{
    UE_LOG(LogTemp, Warning, TEXT("AttackFinished %s"), *GetController()->GetName());

    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character || Character->GetMesh() != MeshComp) return;

    bAttackInProgress = false;
}

void AHGNaturalWeapon::CollisionLog()
{
    FCollisionResponseContainer CollisionResponses = CollisionComponent->GetCollisionResponseToChannels();

    UE_LOG(LogTemp, Display, TEXT("Collision Responses:"));
    for (int32 Channel = 0; Channel < ECollisionChannel::ECC_MAX; ++Channel)
    {
        ECollisionResponse Response = CollisionResponses.GetResponse((ECollisionChannel)Channel);

        FString ChannelName = UEnum::GetValueAsString((ECollisionChannel)Channel);
        FString ResponseName = UEnum::GetValueAsString(Response);

        UE_LOG(LogTemp, Display, TEXT("%s : %s"), *ChannelName, *ResponseName);
    }
}
