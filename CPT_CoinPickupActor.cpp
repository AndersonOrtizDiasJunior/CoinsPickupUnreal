// Fill out your copyright notice in the Description page of Project Settings.


#include "CPT_CoinPickupActor.h"
#include "GameFramework/Character.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPT_CoinPickupActor::ACPT_CoinPickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
    SetRootComponent(ColliderComponent);
    ColliderComponent->SetGenerateOverlapEvents(true);
    ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
    ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    ColliderComponent->OnComponentBeginOverlap.AddDynamic(
     this, &ACPT_CoinPickupActor::OnBeginOverlapComponentEvent
    );

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
    MeshComponent->SetupAttachment(ColliderComponent);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
    MeshComponent->SetGenerateOverlapEvents(false);

    RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}

void ACPT_CoinPickupActor::OnBeginOverlapComponentEvent(
    UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
)
{
    if (!Cast<ACharacter>(OtherActor)) return;

    if (PickSound)
    {
        UGameplayStatics::PlaySoundAtLocation(
            this, PickSound, GetActorLocation(), VolumeMultiplier);
    }

    Destroy();
}
