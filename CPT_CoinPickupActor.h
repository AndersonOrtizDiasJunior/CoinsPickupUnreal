// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPT_CoinPickupActor.generated.h"

class UStaticMeshComponent;
class URotatingMovementComponent;
class USphereComponent;
class USoundBase;

UCLASS()
class COINPICKUP_API ACPT_CoinPickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPT_CoinPickupActor();

    UFUNCTION()
    void OnBeginOverlapComponentEvent(
        UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
    );

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
    TObjectPtr<UStaticMeshComponent> MeshComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
    TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
    TObjectPtr<USphereComponent> ColliderComponent;

    UPROPERTY(EditDefaultsOnly, Category="Coin Pickup")
    float VolumeMultiplier {0.5};

    UPROPERTY(EditDefaultsOnly, Category="Coin Pickup ")
    TObjectPtr<USoundBase> PickSound;
};
