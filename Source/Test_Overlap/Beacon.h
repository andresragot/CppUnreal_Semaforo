// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"
#include "Beacon.generated.h"

UCLASS()
class TEST_OVERLAP_API ABeacon : public AActor
{
	GENERATED_BODY()
	
public:	

	/// <summary>
	/// Número de intermitancias que se van a realizar con timer
	/// </summary>
	UPROPERTY(EditAnyWhere, Category = "Timming Params")
	int numSwitchs = 5;

	/// <summary>
	/// Intervalo de encendido
	/// </summary>
	UPROPERTY(EditAnyWhere, Category = "Timming Params")
	int interval = 2;

	/// <summary>
	/// LLeva la cuenta del número de parpadeos
	/// </summary>
	int currentNumSwitchs;

	/// <summary>
	/// Collider de la baliza
	/// </summary>
	UPROPERTY(EditAnyWhere, Category = "Collider")
	class USphereComponent* collider;

	/// <summary>
	/// Estado de la baliza
	/// </summary>
	enum BeaconState { On, Off };
	BeaconState beaconState;

	//https://docs.unrealengine.com/4.26/en-US/API/Runtime/Engine/Engine/FTimerHandle/
	/// <summary>
	/// Manejador que identifica a un timer de manera única
	/// </summary>
	FTimerHandle timerId;

	/// <summary>
	/// Punto de luz
	/// </summary>
	UPROPERTY(EditAnyWhere, Category = "Light")
	UPointLightComponent* light;

	// Sets default values for this actor's properties
	ABeacon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Atiende el evento del Timer
	/// </summary>
	void Switching();

	/// <summary>
	/// Enciende o apaga la luz
	/// </summary>
	/// <param name="lighting">On/Off</param>
	void SetLight(bool lighting);


};
