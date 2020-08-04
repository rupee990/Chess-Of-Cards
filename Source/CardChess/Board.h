// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.generated.h"

/** Class used to spawn blocks and manage score */
UCLASS(minimalapi)
class AChessBoard : public AActor
{
	GENERATED_BODY()

protected:
	/** Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** Text component for the score */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* ScoreText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AChessBoard)
    FIntPoint m_BoardSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AChessBoard)
    UStaticMesh* m_BoardMesh = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AChessBoard)
    UMaterialInstance* m_WhiteSpaceMaterial = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AChessBoard)
    UMaterialInstance* m_BlackSpaceMaterial = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AChessBoard)
    UMaterialInstance* m_HoverMaterial = nullptr;

    /** Spacing of blocks */
    UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly)
    float BlockSpacing;

public:
	AChessBoard();


protected:
	// Begin AActor interface
	virtual void BeginPlay() override;
	// End AActor interface

public:

	///** Handle the block being clicked */
	//void AddScore();

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns ScoreText subobject **/
	FORCEINLINE class UTextRenderComponent* GetScoreText() const { return ScoreText; }
};



