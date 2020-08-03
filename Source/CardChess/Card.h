#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "Card.generated.h"

class UPaperSpriteComponent;
class UBoxComponent;

UCLASS(BlueprintType)
class ACard : public AActor
{
    GENERATED_BODY()
public:
    ACard();
    ~ACard();

    UFUNCTION()
    void SetCardData(FCardData& a_CardData);

protected:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    UPaperSpriteComponent* m_PaperSpriteComponent = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    UBoxComponent* m_BoxCollider = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    FCardData m_CardData;
};