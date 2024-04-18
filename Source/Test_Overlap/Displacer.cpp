// Fill out your copyright notice in the Description page of Project Settings.


#include "Displacer.h"

// Sets default values
ADisplacer::ADisplacer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Se crea la malla
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADisplacer::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Hello World from Displacer!"));

	

	//Obtiene el jugador
	APlayerController* player = GetWorld()->GetFirstPlayerController();
	//Redirige el Input a este actor
	EnableInput(player);

	//Enlaza el método Horizontal al eje Horizontal
	InputComponent->BindAxis("Horizontal", this, &ADisplacer::Horizontal);

	//Enlaza el método Horizontal al eje Horizontal
	InputComponent->BindAxis("Vertical", this, &ADisplacer::Vertical);

}

void ADisplacer::Vertical(float value)
{
	//Adquiere el delta del eje vertical
	verticalValue = value;
}

void ADisplacer::Horizontal(float value)
{
	//Adquiere el delta del eje horizontal
	horizontalValue = value;
}


// Called every frame
void ADisplacer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Desplaza al objeto por la escena en dirección forward
	//SetActorLocation(GetActorLocation() + (GetActorForwardVector() * displacementSpeed * DeltaTime));

	//Desplaza al objeto en los ejes forward y right
	SetActorLocation(GetActorLocation() +
		((GetActorRightVector() * horizontalValue) + (GetActorForwardVector() * verticalValue)).GetSafeNormal() *
		displacementSpeed * DeltaTime);

    // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Location from actor") + GetActorLocation().ToString());
    UE_LOG(LogTemp, Display, TEXT("Location from actor %s"), *GetActorLocation().ToString());
}

