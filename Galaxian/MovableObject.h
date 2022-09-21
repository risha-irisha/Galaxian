#pragma once
#include "SFML/Graphics.hpp"

#include "StaticObject.h"
#include "CommonTypes.h"

struct FAnimationData
{
	float SpeedAnimation = 0.f;

	int numberFrames = 0;
	int SpriteTexturePositionX = 0;
	int SpriteTexturePositionY = 0;
	int SpriteOffset = 0;
	ETextureAnimationDirection AnimationDirection = ETextureAnimationDirection::Horizontal;

	//Проиграть только 1 раз анимацию после запуска
	bool bPlayOnlyOnce = false;
};

class FMovableObject : public FStaticObject
{
public:
	FMovableObject(FWorld& World);

	void Move(float DeltaTime);
	void Tick(float DeltaTime);
	void ProcessObjectCollision();

	FAnimationData* GetCurrentAnimationData();

	void Animation(float DeltaTime);

	void SetInput(sf::Vector2f NewInput);

	virtual void OnAnimationEnded();

protected:
	sf::Vector2f Input;
	float MoveSpeed;

	float currentFrame = 0.f;

	bool bEnableAnimation = true;
	
	//Текущий индекс анимации из массива Animations
	int CurrentAnimationIndex = 0;
	//Список всех анимаций объекта
	std::vector<FAnimationData> Animations;

	bool bEnableBordersCollision = true;
};

