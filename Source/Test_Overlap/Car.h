// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Car.generated.h"

UCLASS()
class TEST_OVERLAP_API ACar : public AActor
{
	GENERATED_BODY()
	
public:	
    
    UPROPERTY(EditAnyWhere, Category = "Params")
        float displacementSpeed = 1000;

        float displacementSpeedAux = 0;

    UPROPERTY(EditAnyWhere, Category = "Params")
        class UStaticMeshComponent* mesh;

	// Sets default values for this actor's properties
	ACar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
        void StopCar();

    UFUNCTION()
        void ResumeCar();

};
