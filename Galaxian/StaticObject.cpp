#include "StaticObject.h"

#include "World.h"

FStaticObject::FStaticObject(FWorld& InWorld) :
	World(InWorld)
{

}

void FStaticObject::Draw()
{
	const sf::Vector2f spriteScale(Rect.width / TextureSize.x, Rect.height / TextureSize.y);
	Sprite.setPosition(Rect.left + (Sprite.getOrigin().x * spriteScale.x), Rect.top + (Sprite.getOrigin().y * spriteScale.y));

	World.GetWindow().draw(Sprite);
}

void FStaticObject::Tick(float DeltaTime)
{
}

void FStaticObject::SetPosition(sf::Vector2f NewPosition)
{
	Rect.left = NewPosition.x;
	Rect.top = NewPosition.y;
}

void FStaticObject::SetPosition(float X, float Y)
{
	SetPosition(sf::Vector2f(X, Y));
}

const sf::FloatRect& FStaticObject::GetRect() const
{
	return Rect;
}

sf::Vector2f FStaticObject::GetOrigin() const
{
	return sf::Vector2f(Rect.left + Rect.width / 2, Rect.top + Rect.height / 2);
}

void FStaticObject::SetSpriteRect(int TextureX, int TextureY)
{
	Sprite.setTexture(Texture);
	Sprite.setTextureRect(sf::IntRect(TextureX, TextureY, TextureSize.x, TextureSize.y));
	
	const sf::Vector2f spriteScale(Rect.width / TextureSize.x, Rect.height / TextureSize.y);
	Sprite.setScale(spriteScale);

	const sf::Vector2f spriteOrigin(TextureSize.x / 2.f, TextureSize.y / 2.f);
	Sprite.setOrigin(spriteOrigin);
}