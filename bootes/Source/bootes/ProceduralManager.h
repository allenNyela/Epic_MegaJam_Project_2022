// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralManager.generated.h"

UCLASS()
class BOOTES_API AProceduralManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditDefaultsOnly, Category = "Crates")
		UClass* SpawnObject;

	UPROPERTY(EditDefaultsOnly, Category = "Crates")
		UClass* Debris;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float DistanceAcross = 10000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crates")
		int CrateCount = 13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		int QuadrantCount = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		int MaxDebris = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		int MinDebris = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		FVector RelativeLocation = FVector(0, 500000, 0);

private:

	void SpawnDebris(FVector2D quadrant);

	void SpawnAround(UClass* Spawnable, FVector2D location);

	float QuadrantSize = 0.f;
};
