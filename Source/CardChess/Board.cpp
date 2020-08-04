// Copyright Epic Games, Inc. All Rights Reserved.

#include "Board.h"
#include "BoardSpace.h"
#include "Components/TextRenderComponent.h"
#include "Engine/World.h"
#include "PaperSpriteComponent.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AChessBoard::AChessBoard()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);

	// Set defaults
	m_BoardSize = FIntPoint(3,3);
	BlockSpacing = 300.f;
}


void AChessBoard::BeginPlay()
{
	Super::BeginPlay();

	// Number of blocks
	const int32 NumBlocks = m_BoardSize.X * m_BoardSize.Y;

	// Loop to spawn each block
	for(int32 BlockIndex=0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex/m_BoardSize.X) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex%m_BoardSize.Y) * BlockSpacing; // Modulo gives remainder

		// Make position vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		ABoardSpace* NewBlock = GetWorld()->SpawnActor<ABoardSpace>(BlockLocation, FRotator(0,0,0));
		NewBlock->BlockMesh->SetStaticMesh(m_BoardMesh);
		NewBlock->HoverMaterial = m_HoverMaterial;

		if (BlockIndex % 2 == 0)
		{
			NewBlock->BaseMaterial = m_WhiteSpaceMaterial;
			NewBlock->BlockMesh->SetMaterial(0, m_WhiteSpaceMaterial);
		}
		else
		{
			NewBlock->BaseMaterial = m_BlackSpaceMaterial;
			NewBlock->BlockMesh->SetMaterial(0, m_BlackSpaceMaterial);
		}

		// Tell the block about its owner
		if (NewBlock != nullptr)
		{
			NewBlock->OwningBoard = this;
		}
	}
}


//void AChessBoard::AddScore()
//{
//	// Increment score
//	//Score++;
//
//	// Update text
//	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
//}

#undef LOCTEXT_NAMESPACE
