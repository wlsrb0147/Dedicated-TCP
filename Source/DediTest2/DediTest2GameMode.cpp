// Copyright Epic Games, Inc. All Rights Reserved.

#include "DediTest2GameMode.h"
#include "DediTest2Character.h"
#include "UObject/ConstructorHelpers.h"

ADediTest2GameMode::ADediTest2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
