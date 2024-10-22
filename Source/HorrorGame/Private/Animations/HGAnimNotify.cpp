// Horror Game. All Rights Reserved.

#include "Animations/HGAnimNotify.h"

void UHGAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
    Super::Notify(MeshComp, Animation, EventReference);
    OnNotified.Broadcast(MeshComp);
}
