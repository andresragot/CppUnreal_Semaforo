// Fill out your copyright notice in the Description page of Project Settings.


#include "Overlaping.h"

// Sets default values
AOverlaping::AOverlaping()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Se crea el componente collider
	boxCollider = CreateDefaultSubobject<UBoxComponent>("Collider");

	//Se modifica el tamaño del collisder
	boxCollider->SetBoxExtent(FVector(50, 50, 50));

	//Se modifica la jerarquía de compnentes
	boxCollider->SetupAttachment(RootComponent);

	////Se modifica el perfil de colisión para que se comporte como un trigger
	//boxCollider->SetCollisionProfileName(TEXT("Trigger"));
	////Se activa la generación de eventos de overlap
	//boxCollider->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void AOverlaping::BeginPlay()
{
	Super::BeginPlay();

	//Suscripción al los eventos de beginOverlap (trigger enter)
	boxCollider->OnComponentBeginOverlap.AddDynamic(this, &AOverlaping::TriggerEnter);

	//Suscripción al los eventos de endOverlap (trigger exit)
	boxCollider->OnComponentEndOverlap.AddDynamic(this, &AOverlaping::TriggerExit);

	if (GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Coded Trigger Ready!"));


	
}

// Called every frame
void AOverlaping::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOverlaping::TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Hello from Codded Trigger!"));
	
	//UE_LOG(LogTemp, Warning, TEXT("Hello from coded trigger"));
}

void AOverlaping::TriggerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Bye from Trigger!"));
}

void AOverlaping::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Hello from Codded Trigger to ") + OtherActor->GetName());

}

void AOverlaping::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Bye from Codded Trigger to ") + OtherActor->GetName());

}

