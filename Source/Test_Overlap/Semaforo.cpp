// Fill out your copyright notice in the Description page of Project Settings.


#include "Semaforo.h"

// Sets default values
ASemaforo::ASemaforo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    PrimaryActorTick.bAllowTickOnDedicatedServer = true;


    collider = CreateDefaultSubobject<USphereComponent>("Collider");
    collider->SetSphereRadius(124);
    collider->SetupAttachment(RootComponent);

    // se crea la luz
    light = CreateDefaultSubobject<UPointLightComponent>("Light");
    // Se modifica la jerarquia de componentes
    light->SetupAttachment(collider);

    timeWaitAux = timeWait;
}

// Called when the game starts or when spawned
void ASemaforo::BeginPlay()
{
	Super::BeginPlay();
	
    //Estado inciial
    beaconState = BeaconState::Green;
    SetLight(true);
}

// Called every frame
void ASemaforo::Tick(float DeltaTime)
{    
    // FString message_1 = FString::Printf(TEXT("Time restante %d"), ListCars.size());
    // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, message_1);
    // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Hola"));

    if (ListCars.size() > 0 && ListPed.size() <= 0)
    {
        if (timeWaitAux <= 0)
        {
            CarPass();
            timeWaitAux = timeWait;
        }
        // FString message = FString::Printf(TEXT("Time restante %d"), timeWaitAux);
        // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, message);

        // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Time restante") + timeWaitAux);
        timeWaitAux -= DeltaTime;
    }

    if (ListPed.size() > 0 && beaconState == BeaconState::Green)
    {
        Switching(false);
        PedPass();
    }

    Super::Tick(DeltaTime);
}

void ASemaforo::Switching(bool _green)
{
    if (!_green)
    {
        // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Switching red"));
        beaconState = BeaconState::Red;
        SetLight(false);
    }
    else if (_green)
    {
        // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Switching green"));
        beaconState = BeaconState::Green;
        SetLight(true);
    }
}

void ASemaforo::SetLight(bool lighting)
{
        //light->LightColor = FColor::Green;
    if (!lighting)
    {
        light->SetLightColor(FLinearColor::Red);
        // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Color red"));
    }
    else
    {
        light->SetLightColor(FLinearColor::Green);
        // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Color green"));
    }
}


void ASemaforo::NotifyActorBeginOverlap(AActor* OtherActor)
{
    ACar* carActor = Cast<ACar>(OtherActor);

    if (carActor != NULL)
    {
        // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Car enter %s") + carActor->GetName());
        carActor->StopCar();
        if (beaconState == BeaconState::Green)
        {
            // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Beacon green"));
            Switching(false);
            carActor->ResumeCar();
            // carActor->ResumeCar();
        }
        else
        {
            ListCars.push_back(carActor);
        }
    }
    else
    {
        APedestrian* pedActor = Cast<APedestrian>(OtherActor);
        if (pedActor != NULL)
        {
            ListPed.push_back(pedActor);
            pedActor->Stop();
            if (beaconState == BeaconState::Red)
            {
                pedActor->Resume();
            }
        }
    }
}

void ASemaforo::NotifyActorEndOverlap(AActor* OtherActor)
{
    ACar* carActor = Cast<ACar>(OtherActor);
    if (carActor != NULL)
    {
        Switching(true);
        if (ListCars.size() > 0)
        {
            Switching(false);
        }
    }
    else
    {
        APedestrian* pedActor = Cast<APedestrian>(OtherActor);
        if (pedActor != NULL)
        {
            ListPed.erase(std::remove(ListPed.begin(), ListPed.end(), pedActor), ListPed.end());
            if (ListCars.size() <= 0)
            {
                Switching(true);
            }
        }
    }
}

void ASemaforo::CarPass()
{
    if (ListCars.size() > 0)
    {
        // GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, TEXT("Car Pass"));
        ACar* carToPass = ListCars[0];

        carToPass->ResumeCar();

        ListCars.erase(ListCars.begin());

        // Switching(ListCars.size() <= 0);
    }
}

void ASemaforo::PedPass()
{
    for (int i = 0; i < ListPed.size(); i++)
    {
        APedestrian* pedToPass = ListPed[i];

        pedToPass->Resume();
    }
}