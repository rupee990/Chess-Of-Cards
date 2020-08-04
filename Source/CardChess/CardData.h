#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CardData.generated.h"

class UPaperSprite;

USTRUCT(BlueprintType)
struct FCardData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FCardData)
    UPaperSprite* m_Sprite = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FCardData)
    UStaticMesh* m_PieceMesh = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FCardData)
    UMaterialInstance* m_PieceMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FCardData)
    FName m_CardName = TEXT("Card");
};