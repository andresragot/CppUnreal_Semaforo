// Fill out your copyright notice in the Description page of Project Settings.


#include "Beacon.h"

// Sets default values
ABeacon::ABeacon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Se crea el colisionador
	collider = CreateDefaultSubobject<USphereComponent>("Collider");
	collider->SetSphereRadius(128);
	collider->SetupAttachment(RootComponent);

	//Se crea la luz
	light = CreateDefaultSubobject<UPointLightComponent>("Light");
	//Se modifica la jerarquía de compnentes
	light->SetupAttachment(collider);

}

// Called when the game starts or when spawned
void ABeacon::BeginPlay()
{
	Super::BeginPlay();

	//Estado inicial
	beaconState = BeaconState::Off;
	SetLight(false);

	//El booleano del final es para que se active de forma repetitiva
	GetWorldTimerManager().SetTimer(timerId, this, &ABeacon::Switching, interval, true, 0);
	
}

// Called every frame
void ABeacon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABeacon::Switching()
{
	if (beaconState == BeaconState::Off)
	{
		beaconState = BeaconState::On;
		SetLight(true);
		currentNumSwitchs++;
	}
	else
	{
		beaconState = BeaconState::Off;
		SetLight(false);
		currentNumSwitchs++;
	}

	if (currentNumSwitchs >= numSwitchs)
	{
		currentNumSwitchs = 0;
		GetWorldTimerManager().ClearTimer(timerId);
	}
}

void ABeacon::SetLight(bool lighting)
{
	light->SetVisibility(lighting);
}

