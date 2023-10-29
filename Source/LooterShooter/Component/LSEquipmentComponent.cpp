// Fill out your copyright notice in the Description page of Project Settings.

#include "LSEquipmentComponent.h"
#include "LooterShooter/Weapon/LSWeapon.h"
#include "LooterShooter/Weapon/LSWeaponInstance.h"
#include "LooterShooter/Weapon/LSWeaponDefinition.h"

ULSEquipmentComponent::ULSEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	WeaponInstanceClass = ALSWeaponInstance::StaticClass();
}

void ULSEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentWeaponIndex = 0;
}

void ULSEquipmentComponent::SetCurrentWeaponIndex(int32 Index)
{
	CurrentWeaponIndex = Index;
	CurrentWeaponInstance = WeaponInstanceList[Index];
}

int32 ULSEquipmentComponent::GetCurrentWeaponIndex() const
{
	return CurrentWeaponIndex;
}

void ULSEquipmentComponent::EquipWeapon(ALSWeaponInstance* WeaponInstance)
{
	if (WeaponInstanceList.Num() < 3)
	{
		WeaponInstanceList.Emplace(WeaponInstance);
		CurrentWeaponInstance = WeaponInstance;
		OnEquipmentChanged.Broadcast();
	}
	else
	{
		LSLOG(Warning, TEXT("Weapon list is full"));
	}
}

void ULSEquipmentComponent::EquipWeapon(ALSWeaponInstance* Weapon, int8 index)
{

}

ALSWeaponInstance* ULSEquipmentComponent::GetCurrentWeaponInstance() 
{
	return GetWeaponInstance(CurrentWeaponIndex);
}

ALSWeaponInstance* ULSEquipmentComponent::GetWeaponInstance(int32 Index)
{
	LSCHECK(Index < WeaponInstanceList.Num() , nullptr);
	if (WeaponInstanceList[Index] != nullptr)
	{
		return WeaponInstanceList[Index];
	}
	else
	{
		LSLOG(Error, TEXT("%d error"), Index);
		return nullptr;
	}
} 

void ULSEquipmentComponent::SetRoundsRemaining(int32 NewRoundsRemaining)
{
	LSCHECK(CurrentWeaponInstance != nullptr);
	CurrentWeaponInstance->SetRoundsRemaining(NewRoundsRemaining);
	OnRoundsRemainingChanged.Broadcast(CurrentWeaponIndex);
	LSLOG_S(Warning);
}

int32 ULSEquipmentComponent::GetRoundsRemaining() const
{
	LSLOG_S(Warning);
	LSCHECK(CurrentWeaponInstance != nullptr, -1);
	return CurrentWeaponInstance->GetRoundsRemaining();
}

void ULSEquipmentComponent::DecreaseRoundsRemaining()
{
	LSLOG_S(Warning);
	// 탄약을 1보다 많이 소모하는 속성 넣는 경우 여기 수정하기
	int32 NewRoundsRemaining = CurrentWeaponInstance->GetRoundsRemaining() - 1;
	SetRoundsRemaining(NewRoundsRemaining);
}

