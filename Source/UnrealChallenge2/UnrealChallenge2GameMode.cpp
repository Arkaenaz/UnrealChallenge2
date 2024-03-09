// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealChallenge2GameMode.h"
#include "UnrealChallenge2Character.h"
#include "UObject/ConstructorHelpers.h"

AUnrealChallenge2GameMode::AUnrealChallenge2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
