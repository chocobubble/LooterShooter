// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LooterShooter.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "LSAutoLootItem.h"

#include "LSGameInstance.generated.h"

// class UDataTable;

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	RIFLE,
	PISTOL,
	SHOTGUN
};

USTRUCT(BlueprintType)
struct FLSWeaponBaseData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FLSWeaponBaseData() : Level(1), MagazineCapacity(20), FireRate(500.0f),
		MovementSpeed(510.0f), BulletDamage(50.0f), CriticalHitChance(0.03f), 
		CriticalHitMultiplier(1.5f), DamageReduceDistance(1000.0f), ReloadTime(2.0f),
		BulletsPerCatridge(1), MaxRange(10000.0f), MaxSpreadAngle(1.0f),
		MinSpreadAngle(0.0f), HeatPerShot(0.1f) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 MagazineCapacity = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float FireRate = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float MovementSpeed = 510.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float BulletDamage = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float CriticalHitChance = 0.03f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float CriticalHitMultiplier = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float DamageReduceDistance = 1000.f;

	UPROPERTY(EditAnywhere,  BlueprintReadWrite, Category = Weapon)
	float ReloadTime = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 BulletsPerCatridge = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float MaxRange = 10000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	float MaxSpreadAngle  = 1.f;

	UPROPERTY(EditAnywhere,  BlueprintReadWrite, Category = Attack)
	float MinSpreadAngle = 1.f;

	UPROPERTY(EditAnywhere,  BlueprintReadWrite, Category = Attack)
	float HeatPerShot = 0.1f;
};

USTRUCT(BlueprintType)
struct FLSPlayerData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FLSPlayerData() : 
		Level(1), MaxHP(100.0f), MaxShield(50.f), MaxMP(1.f), Defense(1.f),
		ShieldRechargeRate(0.1f), ShieldRechargeDelay(3.f), NextExp(5), MasteryExp(1) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxShield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float ShieldRechargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float ShieldRechargeDelay;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 NextExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 MasteryExp;
};

USTRUCT(BlueprintType)
struct FLSMonsterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FLSMonsterData() : 
		Level(1), MaxHP(100.0f), MaxShield(50.f), Defense(1.f),
		ShieldRechargeRate(0.1f), ShieldRechargeDelay(3.f), DropExp(5) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxShield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float ShieldRechargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float ShieldRechargeDelay;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 DropExp;
};
/*
USTRUCT(BlueprintType)
struct FLSWeaponBaseData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 MagazineCapacity = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float FireRate = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float MovementSpeed = 510.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float BulletDamage = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float CriticalHitChance = 0.03f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float CriticalHitMultiplier = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float DamageReduceDistance = 1000.f;

	UPROPERTY(EditAnywhere,  BlueprintReadWrite, Category = Weapon)
	float ReloadTime = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 BulletsPerCatridge = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float MaxRange = 10000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	float MaxSpreadAngle  = 1.f;

	UPROPERTY(EditAnywhere,  BlueprintReadWrite, Category = Attack)
	float MinSpreadAngle = 1.f;

	UPROPERTY(EditAnywhere,  BlueprintReadWrite, Category = Attack)
	float HeatPerShot = 0.1f;
};

*/

/**
 * 
 */
UCLASS()
class LOOTERSHOOTER_API ULSGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	ULSGameInstance();

	virtual void Init() override;
	FLSPlayerData* GetLSPlayerData(int32 Level);
	FLSMonsterData* GetLSMonsterData(int32 Level);
	FLSWeaponBaseData* GetWeaponData(EWeaponType WeaponType, int32 ItemLevel);
/*
	FLSWeaponBaseData* GetLSRifleData(int32 ItemLevel);
	FLSWeaponBaseData* GetLSShotgunData(int32 ItemLevel);
	FLSWeaponBaseData* GetLSPistolData(int32 ItemLevel);
*/
	USkeletalMesh* GetRifleMesh() const
	{
		return RifleWeaponMesh;
	}

	USkeletalMesh* GetShotgunMesh() const
	{
		return ShotgunWeaponMesh;
	}

	USkeletalMesh* GetPistolMesh() const
	{
		return PistolWeaponMesh;
	}

	void SpawnAutoLootItem(FVector SpawnLocation, ELootItemType LootedItemType, int32 Amount);

	FStreamableManager StreamableManager;

	UPROPERTY(VisibleAnywhere, Category = Loot)
	UStaticMesh* HPMesh;

	UPROPERTY(VisibleAnywhere, Category = Loot)
	UStaticMesh* MPMesh;

	UPROPERTY(VisibleAnywhere, Category = Loot)
	UStaticMesh* GoldMesh;

	UPROPERTY(VisibleAnywhere, Category = Loot)
	UStaticMesh* RifleAmmoMesh;

	UPROPERTY(VisibleAnywhere, Category = Loot)
	UStaticMesh* ShotgunAmmoMesh;
	
	UPROPERTY(VisibleAnywhere, Category = Loot)
	UStaticMesh* PistolAmmoMesh;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	UMaterialInstance* MI_Rifle;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	UMaterialInstance* MI_Shotgun;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	UMaterialInstance* MI_Pistol;

private:
	UPROPERTY()
	UDataTable* LSPlayerTable;
	
	UPROPERTY()
	UDataTable* LSMonsterTable;

	UPROPERTY()
	UDataTable* LSRifleDataTable;

	UPROPERTY()
	UDataTable* LSShotgunDataTable;

	UPROPERTY()
	UDataTable* LSPistolDataTable;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	USkeletalMesh* RifleWeaponMesh;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	USkeletalMesh* ShotgunWeaponMesh;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	USkeletalMesh* PistolWeaponMesh;

	
};
