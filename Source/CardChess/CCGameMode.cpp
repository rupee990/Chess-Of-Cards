// Copyright Epic Games, Inc. All Rights Reserved.

#include "CCGameMode.h"
#include "CCPlayerController.h"
#include "CCPawn.h"

ACardChessGameMode::ACardChessGameMode()
{
	// no pawn by default
	DefaultPawnClass = ACardChessPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = ACardChessPlayerController::StaticClass();
}
