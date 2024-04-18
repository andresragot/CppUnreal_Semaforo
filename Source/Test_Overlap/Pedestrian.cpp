// Fill out your copyright notice in the Description page of Project Settings.


#include "Pedestrian.h"

// Sets default values
APedestrian::APedestrian()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APedestrian::BeginPlay()
{
	Super::BeginPlay();
	
	walkingSpeedAux = walkingSpeed;
}

// Called every frame
void APedestrian::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * walkingSpeed * DeltaTime);
}

void APedestrian::Stop()
{
	walkingSpeed = 0;
}

void APedestrian::Resume()
{
	walkingSpeed = walkingSpeedAux;
}

