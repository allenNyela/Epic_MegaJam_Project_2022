#include "ProceduralManager.h"

// Sets default values
AProceduralManager::AProceduralManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProceduralManager::BeginPlay()
{
	Super::BeginPlay();
	TArray<FVector2D> quadrants;
	QuadrantSize = DistanceAcross / QuadrantCount;
	for (int x = 0; x < QuadrantCount; x++)
	{
		for (int y = 0; y < QuadrantCount; y++)
		{
			const float quadrantX = x - QuadrantCount / 2;
			const float quadrantY = y - QuadrantCount / 2;
			FVector2D quadrantCenter = FVector2D(quadrantX * QuadrantSize, quadrantY * QuadrantSize);
			quadrants.Add(quadrantCenter);
			SpawnDebris(quadrantCenter);
		}
	}
	for (int i = 0; i < CrateCount; i++)
	{
		FVector2D crateQuadrant = quadrants[FMath::RandRange(0, quadrants.Num() - 1)];
		quadrants.Remove(crateQuadrant);
		SpawnAround(SpawnObject, SoulWorldObject, crateQuadrant);
	}
}

void AProceduralManager::SpawnDebris(FVector2D quadrant)
{
	int amount = FMath::RandRange(MinDebris, MaxDebris);
	for (int i = 0; i < amount; i++)
	{
		SpawnAround(Debris, DebrisSoulWorld, quadrant);
	}
}

void AProceduralManager::SpawnAround(UClass* Spawnable, UClass* SoulObject, FVector2D location)
{
	float xLocation = FMath::RandRange(location.X, location.X + QuadrantSize);
	xLocation -= QuadrantSize / 2;
	float yLocation = FMath::RandRange(location.Y, location.Y + QuadrantSize);
	yLocation -= QuadrantSize / 2;
	FVector spawnLoc = OriginPoint + FVector(xLocation, yLocation, 0);
	AActor *SpawnedActor = GetWorld()->SpawnActor(Spawnable, &spawnLoc);
	FVector partnerPos = spawnLoc + RelativeLocation;
	AActor *SoulActor = GetWorld()->SpawnActor(SoulObject, &partnerPos);
	UActorComponent *comp = SpawnedActor->GetComponentByClass(UCrateLink::StaticClass());
	if (UCrateLink* crateLink = dynamic_cast<UCrateLink*>(comp))
	{
		crateLink->AddLink(SoulActor);
	}
}