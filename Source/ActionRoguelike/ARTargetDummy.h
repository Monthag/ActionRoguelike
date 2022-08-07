// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARTargetDummy.generated.h"

class UARAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API AARTargetDummy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARTargetDummy();

protected:
	
	UPROPERTY(VisibleAnywhere)
	UARAttributeComponent* AttributeComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, UARAttributeComponent* OwiningComp, float NewHealth, float Delta);

};
