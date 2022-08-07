// Fill out your copyright notice in the Description page of Project Settings.


#include "ARTargetDummy.h"
#include "ARAttributeComponent.h"

// Sets default values
AARTargetDummy::AARTargetDummy()
{
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
    RootComponent = MeshComp;

    AttributeComp = CreateDefaultSubobject<UARAttributeComponent>("AttributeComp");
    // Trigger when health is changed (damage/healing)
    AttributeComp->OnHealthChanged.AddDynamic(this, &AARTargetDummy::OnHealthChanged);
}

void AARTargetDummy::OnHealthChanged(AActor* InstigatorActor, UARAttributeComponent* OwiningComp, float NewHealth, float Delta)
{
    if (Delta < 0.0f)
    {
        MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
    }
    
}
