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
    UPaperSprite* m_Sprite;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FCardData)
    FName m_CardName;
};