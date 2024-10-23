// Horror Game. All Rights Reserved.

#include "World/HGDoor.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Player/HGCharacter.h"

AHGDoor::AHGDoor()
{
    PrimaryActorTick.bCanEverTick = false;

    SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    SetRootComponent(SceneComponent);

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(GetRootComponent());

    DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    DoorMesh->SetupAttachment(GetRootComponent());
}

void AHGDoor::BeginPlay()
{
    Super::BeginPlay();

    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
    TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);
}

void AHGDoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AHGDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor->IsA(AHGCharacter::StaticClass()))
    {
        OpenDoor();
        OpenDoor_Implementation();
    }
}

void AHGDoor::OnOverlapEnd(
    UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    CloseDoor();
    CloseDoor_Implementation();
}

void AHGDoor::OpenDoor_Implementation()
{
    // animation of door opening in a blueprint
    UE_LOG(LogTemp, Display, TEXT("OpenDoor"));
}

void AHGDoor::CloseDoor_Implementation()
{
    // animation of door closing in a blueprint
    UE_LOG(LogTemp, Display, TEXT("CloseDoor"));
    OnExit.Broadcast();
}
