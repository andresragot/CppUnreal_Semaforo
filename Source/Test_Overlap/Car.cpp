// Fill out your copyright notice in the Description page of Project Settings.


#include "Car.h"

// Sets default values
ACar::ACar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Creamos la malla
    mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
    mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACar::BeginPlay()
{
	Super::BeginPlay();

    displacementSpeedAux = displacementSpeed;
	
}

// Called every frame
void ACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    SetActorLocation(GetActorLocation() + GetActorForwardVector() * displacementSpeed * DeltaTime);
}

void ACar::StopCar()
{
    displacementSpeed = 0;
}

void ACar::ResumeCar()
{
    displacementSpeed = displacementSpeedAux;
}

