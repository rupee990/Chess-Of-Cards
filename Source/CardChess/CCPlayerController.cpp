// Copyright Epic Games, Inc. All Rights Reserved.

#include "CCPlayerController.h"

ACardChessPlayerController::ACardChessPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
