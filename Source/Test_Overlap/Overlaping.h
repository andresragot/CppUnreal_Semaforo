// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Overlaping.generated.h"

UCLASS()
class TEST_OVERLAP_API AOverlaping : public AActor
{
	GENERATED_BODY()

public:

	/// <summary>
	/// Colisionador del objeto
	/// </summary>
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Collider")
	class UBoxComponent* boxCollider;

	// Sets default values for this actor's properties
	AOverlaping();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Trigger Enter (Begin Overlap)
	//https://dev.epicgames.com/community/learning/tutorials/zw7m/hits-and-overlaps-bp-c-multiplayer
	UFUNCTION()
	void TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//Trigger Exit (End Overlap)
	UFUNCTION()
	void TriggerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor);
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor);
};
