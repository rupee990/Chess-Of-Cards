// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoardSpace.h"
#include "Board.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstance.h"
#include "Card.h"

ABoardSpace::ABoardSpace()
{


	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	//BlockMesh->SetStaticMesh(PlaneMesh);
	BlockMesh->SetRelativeScale3D(FVector(1.f,1.f,0.25f));
	BlockMesh->SetRelativeLocation(FVector(0.f,0.f,25.f));
	//BlockMesh->SetMaterial(0, BlueMaterial);
	BlockMesh->SetupAttachment(DummyRoot);
	
	BlockMesh->OnComponentBeginOverlap.AddDynamic(this, &ABoardSpace::OnOverlapBegin);
	BlockMesh->OnComponentEndOverlap.AddDynamic(this, &ABoardSpace::OnOverlapEnd);
	//BlockMesh->OnClicked.AddDynamic(this, &ACardChessBlock::BlockClicked);
	//BlockMesh->OnInputTouchBegin.AddDynamic(this, &ACardChessBlock::OnFingerPressedBlock);

	// Save a pointer to the orange material
	//BaseMaterial = ConstructorStatics.BaseMaterial.Get();
	//BlueMaterial = ConstructorStatics.BlueMaterial.Get();
	//OrangeMaterial = ConstructorStatics.OrangeMaterial.Get();
}

void ABoardSpace::HandleOverlap()
{

}

void ABoardSpace::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Highlight(true);

	if (IsValid(OtherActor))
	{
		Cast<ACard>(OtherActor)->SetBoardSpace(this);
	}
}

void ABoardSpace::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Highlight(false);
}

//void ABoardSpace::BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
//{
//	HandleClicked();
//}
//
//
//void ABoardSpace::OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
//{
//	HandleClicked();
//}
//
//void ABoardSpace::HandleClicked()
//{
//	// Check we are not already active
//	if (!bIsActive)
//	{
//		bIsActive = true;
//
//		// Change material
//		BlockMesh->SetMaterial(0, OrangeMaterial);
//
//		// Tell the Grid
//		if (OwningGrid != nullptr)
//		{
//			OwningGrid->AddScore();
//		}
//	}
//}

void ABoardSpace::Highlight(bool bOn)
{
	// Do not highlight if the block has already been activated.
	if (bIsActive)
	{
		return;
	}

	if (bOn)
	{
		BlockMesh->SetMaterial(0, HoverMaterial);
	}
	else
	{
		BlockMesh->SetMaterial(0, BaseMaterial);
	}
}
