// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptMakerGameMode.h"
#include "CryptMakerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACryptMakerGameMode::ACryptMakerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
