// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemMeshComponent.h"

#include "TP_WeaponComponent.h"
#include "UnrealChallenge2Character.h"

// Sets default values for this component's properties
UItemMeshComponent::UItemMeshComponent()
{
}

void UItemMeshComponent::AttachProjectile(AUnrealChallenge2Character* TargetCharacter)
{
	if (!TargetCharacter->GetHasRifle())
	{
		return;
	}

	TArray<AActor*> attachedActors;
	TargetCharacter->GetController()->GetPawn()->GetAttachedActors(attachedActors);
	UE_LOG(LogTemp, Warning, TEXT("Controller : %s."), *TargetCharacter->GetController()->GetActorNameOrLabel());
	UE_LOG(LogTemp, Warning, TEXT("Pawn : %s."), *TargetCharacter->GetController()->GetPawn()->GetActorNameOrLabel());
	UE_LOG(LogTemp, Warning, TEXT("Children Size : %d."), attachedActors.Num());
	for(int i = 0; i < attachedActors.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Children : %s."), *attachedActors[i]->GetActorNameOrLabel());
	}
	UTP_WeaponComponent* weapon = attachedActors[0]->GetComponentByClass<UTP_WeaponComponent>();
	if (weapon == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Weapon NOT FOUND."));
		return;
	}

	weapon->ProjectileClass = ProjectileClass;
}