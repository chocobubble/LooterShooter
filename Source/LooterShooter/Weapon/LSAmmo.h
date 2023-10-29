// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LooterShooter/LooterShooter.h"
#include "GameFramework/Actor.h"
#include "LSAmmo.generated.h"

class UProjectileMovementComponent;

UCLASS()
class LOOTERSHOOTER_API ALSAmmo : public AActor
{
	GENERATED_BODY()
	
public:	
	ALSAmmo();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	UStaticMeshComponent* Mesh;
private:
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere)
	FVector FireDir = FVector::ZeroVector;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Fire(FVector Dir);

	FTimerHandle OnLifeTimerHandle = {};

};
