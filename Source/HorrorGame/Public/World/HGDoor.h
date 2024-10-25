// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Framework/HGCoreTypes.h"
#include "HGDoor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class HORRORGAME_API AHGDoor : public AActor
{
    GENERATED_BODY()

public:
    AHGDoor();

    FOnExitSignature OnExit;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Door")
    void OpenDoor();
    virtual void OpenDoor_Implementation();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Door")
    void CloseDoor();
    virtual void CloseDoor_Implementation();

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    USceneComponent* SceneComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UBoxComponent* EnterTriggerBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UBoxComponent* ExitTriggerBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* DoorMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
    bool bCanOpen = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bCanOpen", EditConditionHides), Category = "Door Settings")
    bool bCloseAfterOpened = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "360", EditCondition = "bCanOpen", EditConditionHides),
        Category = "Door Settings")
    float OpenAngle = 90.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bCanOpen", EditConditionHides), Category = "Door Settings")
    float OpenTime = 1.0f; // in seconds

    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    AActor* OpenCauser = nullptr;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
