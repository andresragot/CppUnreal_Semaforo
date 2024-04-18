// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Pedestrian.generated.h"

UCLASS()
class TEST_OVERLAP_API APedestrian : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnyWhere, Category = "Params")
	float walkingSpeed = 100;

	float walkingSpeedAux = 0;

	UPROPERTY(EditAnyWhere, Category = "Params")
	class UStaticMeshComponent* mesh;

	// Sets default values for this actor's properties
	APedestrian();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Stop();

	UFUNCTION()
	void Resume();

};
