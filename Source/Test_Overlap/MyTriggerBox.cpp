// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"

AMyTriggerBox::AMyTriggerBox()
{
    //Se crea la malla
    //collider = CreateDefaultSubobject<UBoxComponent>(TEXT("collider"));
    //collider->SetupAttachment(RootComponent);
    ////Se modifica el tama�o del collider
    //collider->SetBoxExtent(FVector(50, 50, 50));
    
}

void AMyTriggerBox::BeginPlay()
{
    Super::BeginPlay();

    

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    //Suscripci�n al los eventos de beginOverlap (trigger enter)
    GetCollisionComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerBox::TriggerEnter);

    //Suscripci�n al los eventos de endOverlap (trigger exit)
    GetCollisionComponent()->OnComponentEndOverlap.AddDynamic(this, &AMyTriggerBox::TriggerExit);



}

void AMyTriggerBox::TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (GEngine != nullptr)
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Hello from Coded Trigger to ") + OtherActor->GetName());

    // Calcula la direcci�n del actor que est� entrando
    /*FVector Direction = OtherActor->GetActorLocation() - GetActorLocation();
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("SweepResult ") + SweepResult.ToString());
    // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Direction ") + Direction.ToString());
    Direction.Normalize();
    // Direction *= -1;

    // Define una normal est�tica
    FVector Normal = FVector(0, 1, 0);

    // Calcula el vector de reflejo
    FVector Reflection = Direction - 2 * (FVector::DotProduct(Direction, Normal)) * Normal;

    // Dibuja una l�nea desde la posici�n del actor hasta el punto de impacto
    DrawDebugLine(GetWorld(), OtherActor->GetActorLocation(), GetActorLocation(), FColor::Red, true, 1.0f);

    // Dibuja una l�nea desde el punto de impacto en la direcci�n del vector de reflejo
    DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + Reflection * 100, FColor::Green, true, 1.0f);

    // Aplica la nueva direcci�n al actor
    FRotator NewRotation = Reflection.Rotation();
    OtherActor->SetActorRotation(NewRotation);*/

    // Calcula la direcci�n del actor que est� entrando
    /*FVector Direction = OtherActor->GetActorLocation() - GetActorLocation();
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("SweepResult ") + SweepResult.ToString());

    // Normaliza la direcci�n
    Direction.Normalize();

    // Refleja la direcci�n
    FVector Reflection = -1 * Direction;

    // Dibuja una l�nea desde la posici�n del actor hasta el punto de impacto
    DrawDebugLine(GetWorld(), OtherActor->GetActorLocation(), GetActorLocation(), FColor::Red, true, 1.0f);

    // Dibuja una l�nea desde el punto de impacto en la direcci�n del vector de reflejo
    DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + Reflection * 100, FColor::Green, true, 1.0f);*/

    // Obtiene la rotaci�n actual del actor
    FRotator CurrentRotation = OtherActor->GetActorRotation();

    CurrentRotation.Add(0.0f, 180.0f, 0.0f);

    // Agrega 180 grados a la rotaci�n en el eje Z
    // FRotator NewRotation = FRotator(CurrentRotation.Roll, CurrentRotation.Pitch, CurrentRotation.Yaw + 180.0f);

    // Aplica la nueva rotaci�n al actor
    OtherActor->SetActorRotation(CurrentRotation);
}

void AMyTriggerBox::TriggerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (GEngine != nullptr)
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Bye from Coded Trigger to ") + OtherActor->GetName());

}
