// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "Math/UnrealMathUtility.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class TEST_OVERLAP_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:

    /// <summary>
    /// Malla del objeto
    /// </summary>
    UPROPERTY(EditAnyWhere, Category = "Params")
        class UBoxComponent* collider;

    AMyTriggerBox();

protected:

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    //Trigger Enter (Begin Overlap)
    //https://dev.epicgames.com/community/learning/tutorials/zw7m/hits-and-overlaps-bp-c-multiplayer
    UFUNCTION()
        void TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    //Trigger Exit (End Overlap)
    UFUNCTION()
        void TriggerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
