// Horror Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "HGAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNotifiedSignature, USkeletalMeshComponent*);

UCLASS()
class HORRORGAME_API UHGAnimNotify : public UAnimNotify
{
    GENERATED_BODY()

public:
    virtual void Notify(
        USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

    FOnNotifiedSignature OnNotified;
};
