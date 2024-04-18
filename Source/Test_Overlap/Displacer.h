// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Displacer.generated.h"

UCLASS()
class TEST_OVERLAP_API ADisplacer : public AActor
{
	GENERATED_BODY()
	
public:	

	/// <summary>
	/// Velocidad de movimiento
	/// </summary>
	UPROPERTY(EditAnyWhere, Category = "Params")
	float displacementSpeed = 1000;

	/// <summary>
	/// Mensaje a mostrar
	/// </summary>
	UPROPERTY(EditAnyWhere, Category = "Params")
	FString message = "Hello World!";

	/// <summary>
	/// Malla del objeto
	/// </summary>
	UPROPERTY(EditAnyWhere, Category = "Params")
	class UStaticMeshComponent* mesh;

	// Sets default values for this actor's properties
	ADisplacer();

protected:
	/// <summary>
	/// Valores obtenidos de la pulsación del teclado
	/// </summary>
	float verticalValue, horizontalValue;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	

	UFUNCTION()
	/// <summary>
	/// Método que captura los valores del teclado para Vertical
	/// </summary>
	/// <param name="value"></param>
	void Vertical(float value);

	UFUNCTION()
	/// <summary>
	/// Método que captura los valores del teclado para Horizontal
	/// </summary>
	/// <param name="value"></param>
	void Horizontal(float value);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
