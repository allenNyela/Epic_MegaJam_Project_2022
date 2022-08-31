// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CrateLink.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOOTES_API UCrateLink : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCrateLink();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UFUNCTION(BlueprintCallable, Category = "Link")
		void AddLink(AActor* OtherObj);

	UFUNCTION(BlueprintCallable, Category = "Link")
		void DestroyCrates();

private:
	AActor* soulObj;
	bool SoulCrate = false;
		
};
