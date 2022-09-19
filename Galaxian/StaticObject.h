#pragma once
#include "SFML/Graphics.hpp"

#include <iostream>

class FWorld;

class FStaticObject
{
public:
	FStaticObject(FWorld& InWorld);

	virtual void Draw();
	virtual void Tick(float DeltaTime);

	void SetPosition(sf::Vector2f NewPosition);
	void SetPosition(float X, float Y);

	const sf::FloatRect& GetRect() const;

	//Получить координаты центра
	sf::Vector2f GetOrigin() const;

	void SetSpriteRect(int TextureX, int TextureY);

protected:
	FWorld& World;

	sf::FloatRect Rect;

	sf::Sprite Sprite;
	std::shared_ptr<sf::Texture> Texture;

	sf::Vector2i TextureSize;
};

