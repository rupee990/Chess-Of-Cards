#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "Engine/DataAsset.h"
#include "CardDatabase.generated.h"

UCLASS()
class UCardsDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UCardsDatabase() {};
    ~UCardsDatabase() {};

    FCardData& GetData(int32 a_Index) { return m_Data[a_Index]; }


public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UCardDatabase)
    TArray<FCardData> m_Data;
};