// Fill out your copyright notice in the Description page of Project Settings.


#include "CrateLink.h"

// Sets default values for this component's properties
UCrateLink::UCrateLink()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCrateLink::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCrateLink::AddLink(AActor* OtherObj)
{
	soulObj = OtherObj;
}

void UCrateLink::DestroyCrates()
{
	if (soulObj)
	{
		soulObj->Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destroyed partner"));
	}
	GetOwner()->Destroy();
}

