#include "MovableObject.h"
#include "World.h"

FMovableObject::FMovableObject(FWorld& World) : FStaticObject(World)
{
}

void FMovableObject::Move(float DeltaTime)
{
	sf::Vector2f velocity = Input * MoveSpeed * DeltaTime;
	Rect.left += velocity.x;
	Rect.top += velocity.y;

	if (bEnableBordersCollision)
	{
		if (Rect.top < 0)
		{
			Rect.top = 0;
		}
		else if (Rect.top + Rect.height > World.GetWindowSize().y)
		{
			Rect.top = World.GetWindowSize().y - Rect.height;
		}

		if (Rect.left < 0)
		{
			Rect.left = 0;
		}
		else if (Rect.left + Rect.width > World.GetWindowSize().x)
		{
			Rect.left = World.GetWindowSize().x - Rect.width;
		}
	}
	
}

void FMovableObject::Tick(float DeltaTime)
{
	Move(DeltaTime);
	Animation(DeltaTime);
}

void FMovableObject::ProcessObjectCollision()
{

}

FAnimationData* FMovableObject::GetCurrentAnimationData()
{
	//��������� ��� ������ ������ ����� � � ��� ���� ��������
	if (CurrentAnimationIndex >= 0 && CurrentAnimationIndex < Animations.size())
	{
		return &Animations[CurrentAnimationIndex];
	}

	//���� �������� ���, ���������� ������� ���������
	return nullptr;
}

void FMovableObject::Animation(float DeltaTime)
{
	FAnimationData* currentAnimationPtr = GetCurrentAnimationData();
	if (currentAnimationPtr == nullptr || !bEnableAnimation)
	{
		return;
	}

	bool bIsAnimationEnded = false;

	currentFrame += currentAnimationPtr->SpeedAnimation;
	//�������� ��� �������� ��������� �����������
	if (currentFrame > currentAnimationPtr->numberFrames)
	{ 
		currentFrame = 0.f;

		if (currentAnimationPtr->bPlayOnlyOnce)
		{
			bEnableAnimation = false;
		}
		bIsAnimationEnded = true;
	}

	//���� �� ������ ��� ���������� ��������(�.�. ��� ����������� �� �����), �� �� ������ �� ��������� ��������, �.�. currentFrame ����� ����� 0 � �������� ������ �� 1� �����
	if (bEnableAnimation)
	{
		switch (currentAnimationPtr->AnimationDirection)
		{
		case ETextureAnimationDirection::Horizontal:
			SetSpriteRect(currentAnimationPtr->SpriteTexturePositionX + (TextureSize.x + currentAnimationPtr->SpriteOffset) * int(currentFrame), currentAnimationPtr->SpriteTexturePositionY);
			break;
		case ETextureAnimationDirection::Vertical:
			SetSpriteRect(currentAnimationPtr->SpriteTexturePositionX, currentAnimationPtr->SpriteTexturePositionY + (TextureSize.y + currentAnimationPtr->SpriteOffset) * int(currentFrame));
			break;
		}
	}

	if (bIsAnimationEnded)
	{
		OnAnimationEnded();
	}
	
	//std::cout << SpriteTexturePositionX * int(currentFrame) << "\n";
}

void FMovableObject::SetInput(sf::Vector2f NewInput)
{
	Input = NewInput;
}

void FMovableObject::OnAnimationEnded()
{

}
