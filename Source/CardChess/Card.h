#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "Card.generated.h"

class UPaperSpriteComponent;
class UBoxComponent;
class USceneComponent;
class ABoardSpace;

UCLASS(BlueprintType)
class ACard : public AActor
{
    GENERATED_BODY()
public:
    ACard();
    ~ACard();

    UFUNCTION()
    void SetCardData(FCardData& a_CardData);

    void SetBoardSpace(ABoardSpace* a_BoardSpace);

    UFUNCTION(BlueprintPure)
    ABoardSpace* GetBoardSpace();

    UFUNCTION(BlueprintCallable)
        void DestroyCard();

    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

    virtual void BeginPlay() override;


    virtual void K2_DestroyActor() override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ACard)
    USceneComponent* m_Root = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    UPaperSpriteComponent* m_PaperSpriteComponent = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    UBoxComponent* m_BoxCollider = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    UBoxComponent* m_BoardCollider = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = ACard)
    ABoardSpace* m_BoardSpace = nullptr;

    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    //FCardData m_CardData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    UDataTable* m_DataTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ACard)
    FDataTableRowHandle m_RowHandle;

};