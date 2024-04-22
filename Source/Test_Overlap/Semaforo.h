// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"
#include "Car.h"
#include "Pedestrian.h"
#include "Semaforo.generated.h"

UCLASS()
class TEST_OVERLAP_API ASemaforo : public AActor
{
	GENERATED_BODY()
	
public:	

    UPROPERTY(EditAnywhere, Category = "Collider");
    class USphereComponent* collider;

    enum BeaconState {Green, Red};
    BeaconState beaconState;

    FTimerHandle timerId;

    UPROPERTY(EditAnyWhere, Category = "Light")
    UPointLightComponent* light;

    UPROPERTY(EditAnywhere, Category = "Time");
    float timeWait = 5;

    float timeWaitAux = 0;

    UFUNCTION()
        virtual void NotifyActorBeginOverlap(AActor* OtherActor);

    UFUNCTION()
        virtual void NotifyActorEndOverlap(AActor* OtherActor);

	// Sets default values for this actor's properties
	ASemaforo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    std::vector<ACar*> ListCars;
    std::vector<APedestrian*> ListPed;

    bool is_car_passing = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // void Switching();

    UFUNCTION()
    void SetLight(bool lighting);

    UFUNCTION()
    void Switching(bool _green);

    UFUNCTION()
        void CarPass();

    UFUNCTION()
    void PedPass();

};
