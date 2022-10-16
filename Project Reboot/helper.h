#pragma once

#include <vector>

#include "definitions.h"
#include "enums.h"

namespace Helper
{
	namespace Easy
	{
		UObject* SpawnActor(UObject* Class, FVector Location, FRotator Rotation = FRotator(), UObject* Owner = nullptr);
		UObject* SpawnObject(UObject* Class, UObject* Outer);
	}

	static int GetSizeOfClass(UObject* Class) { return Class ? *(int*)(__int64(Class) + PropertiesSizeOffset) : 0; }
	UObject* GetWorld();
	UObject* GetTransientPackage();
	UObject* GetEngine();
	UObject* GetGameMode();
	UObject* GetGameState();
	UObject* GetLocalPlayerController();
	UObject* GetPlayerStateFromController(UObject* Controller);
	UObject* GetControllerFromPawn(UObject* Pawn);
	UObject* GetPawnFromController(UObject* Controller);
	UObject* SpawnPawn(UObject* Controller, FVector Location, bool bAssignCharacterParts = false);
	void ChoosePart(UObject* Pawn, TEnumAsByte<EFortCustomPartType> Part, UObject* ChosenCharacterPart);
	void SetOwner(UObject* Actor, UObject* Owner);
	UObject* GetAbilitySystemComponent(UObject* Pawn);
	void InitializeBuildingActor(UObject* Controller, UObject* BuildingActor, bool bUsePlayerBuildAnimations = false, UObject* ReplacedBuilding = nullptr);
	UObject** GetPlaylist();
	TArray<UObject*> GetAllActorsOfClass(UObject* Class);
	bool IsInAircraft(UObject* Controller);
	UObject* GetCurrentWeapon(UObject* Pawn);
	UObject* GetWeaponData(UObject* Weapon);
	int* GetTeamIndex(UObject* PlayerState);
	FVector GetActorLocation(UObject* Actor);
	__int64* GetEntryFromPickup(UObject* Pickup);

	std::vector<UObject*> GetAllObjectsOfClass(UObject* Class);
	UObject* GetPlayerStart();
	UObject* SummonPickup(UObject* Pawn, UObject* Definition, FVector Location, EFortPickupSourceTypeFlag PickupSource, EFortPickupSpawnSource SpawnSource, int Count = 1, bool bMaxAmmo = false, int Ammo = 0);

	namespace Conversion
	{
		FName StringToName(FString& String); // We don't want the fstring to never get free'd
	}
}