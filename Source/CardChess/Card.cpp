#include "Card.h"
#include "Components/BoxComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"

ACard::ACard()
{
    m_Root = CreateDefaultSubobject<USceneComponent>("Root");
    SetRootComponent(m_Root);
    m_PaperSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("CardSprite");
    m_PaperSpriteComponent->AttachToComponent(m_Root, FAttachmentTransformRules::KeepRelativeTransform);
    m_PaperSpriteComponent->SetRelativeRotation(FRotator(0, 90, 90));

    m_BoxCollider = CreateDefaultSubobject<UBoxComponent>("Collider");
    m_BoxCollider->SetBoxExtent(FVector(16, 1, 24));
    m_BoxCollider->AttachToComponent(m_PaperSpriteComponent, FAttachmentTransformRules::KeepRelativeTransform);

    m_BoardCollider = CreateDefaultSubobject<UBoxComponent>("BoardCollider");
    m_BoardCollider->SetBoxExtent(FVector(1, 30, 1));
    m_BoardCollider->AttachToComponent(m_PaperSpriteComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

ACard::~ACard()
{

}

void ACard::SetCardData(FCardData& a_CardData)
{
    //m_CardData = a_CardData;
    //m_PaperSpriteComponent->SetSprite(m_CardData.m_Sprite);
}

void ACard::SetBoardSpace(ABoardSpace* a_BoardSpace)
{
    m_BoardSpace = a_BoardSpace;
}

ABoardSpace* ACard::GetBoardSpace()
{
    return m_BoardSpace;
}

void ACard::DestroyCard()
{
    TSet<UActorComponent*> Components = GetComponents();

    for (UActorComponent* comp : Components)
    {
        comp->DestroyComponent();
    }

    Destroy();
    
}

void ACard::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{

    FName propertyName = PropertyChangedEvent.GetPropertyName();


    if (propertyName == "m_DataTable")
    {
        m_RowHandle.DataTable = m_DataTable;
        m_PaperSpriteComponent->SetSprite(m_DataTable->FindRow<FCardData>(m_RowHandle.RowName, "")->m_Sprite);
    }

    if (propertyName == "RowName")
    {
        m_PaperSpriteComponent->SetSprite(m_DataTable->FindRow<FCardData>(m_RowHandle.RowName, "")->m_Sprite);
    }
}

void ACard::BeginPlay()
{
    if (IsValid(m_RowHandle.DataTable) && m_RowHandle.RowName != "")
    {
        m_PaperSpriteComponent->SetSprite(m_DataTable->FindRow<FCardData>(m_RowHandle.RowName, "")->m_Sprite);
    }
}

void ACard::K2_DestroyActor()
{
    Super::K2_DestroyActor();
    
    if (IsPendingKillPending())
    {
        UE_LOG(LogTemp, Warning, TEXT("IS PENDING KILL!"));
    }
}

