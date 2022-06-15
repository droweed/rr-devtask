// Copyright Epic Games, Inc. All Rights Reserved.

#include "RRTestGameMode.h"
#include "RRTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARRTestGameMode::ARRTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
