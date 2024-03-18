// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "ItemMeshComponent.generated.h"

class AUnrealChallenge2Character;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALCHALLENGE2_API UItemMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AUnrealChallenge2Projectile> ProjectileClass;

	/** Sets default values for this component's properties */
	UItemMeshComponent();

	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void AttachProjectile(AUnrealChallenge2Character* TargetCharacter);
};

