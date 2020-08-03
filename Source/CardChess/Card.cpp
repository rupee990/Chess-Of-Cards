#include "Card.h"
#include "Components/BoxComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"

ACard::ACard()
{
    m_PaperSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Root");
    SetRootComponent(m_PaperSpriteComponent);
    m_BoxCollider = CreateDefaultSubobject<UBoxComponent>("Collider");
    m_BoxCollider->SetBoxExtent(FVector(16, 10, 24));
    m_BoxCollider->AttachToComponent(m_PaperSpriteComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

ACard::~ACard()
{

}

void ACard::SetCardData(FCardData& a_CardData)
{
    m_CardData = a_CardData;
    m_PaperSpriteComponent->SetSprite(m_CardData.m_Sprite);
}

