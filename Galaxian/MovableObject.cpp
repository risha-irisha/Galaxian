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

	if (bIsBorders)
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

void FMovableObject::Animation(float DeltaTime)
{
	currentFrame += SpeedAnimation;
	if (currentFrame > numberFrame)
	{
		currentFrame = 0.f;
	}

	if (bIsDirectionX)
	{		
		SetSpriteRect(SpriteTexturePositionX + SpriteOffset * int(currentFrame), SpriteTexturePositionY);
	}
	else
	{
		currentFrame += SpeedAnimation;
		if (currentFrame > numberFrame)
		{
			currentFrame = 1.f;
		}
		SetSpriteRect(SpriteTexturePositionX , SpriteTexturePositionY + SpriteOffset * int(currentFrame));
	}
	
	//std::cout << SpriteTexturePositionX * int(currentFrame) << "\n";
}

void FMovableObject::SetInput(sf::Vector2f NewInput)
{
	Input = NewInput;
}

void FMovableObject::OnHit(FStaticObject StaticObject)
{
}
