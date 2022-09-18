#pragma once
#include "SFML/Graphics.hpp"

#include "StaticObject.h"

class FMovableObject : public FStaticObject
{
public:
	FMovableObject(FWorld& World);

	void Move(float DeltaTime);
	void Tick(float DeltaTime);
	void ProcessObjectCollision();

	void Animation(float DeltaTime);

	void SetInput(sf::Vector2f NewInput);

	virtual void OnHit(FStaticObject StaticObject);

protected:
	sf::Vector2f Input;
	float MoveSpeed;

	float currentFrame = 0.f;
	int numberFrame = 0;
	float SpeedAnimation = 0.f;
	int SpriteTexturePositionX = 0;
	int SpriteTexturePositionY = 0;
	int SpriteOffset = 0;

	bool bIsBorders = true;

	bool bIsDirectionX = true;
};

