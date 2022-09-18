#include "Player.h"
#include "CommonTypes.h"
#include "World.h"

FPlayer::FPlayer(FWorld& World) : FCharacter(World)
{
	Texture.loadFromFile("./Content/Textures/Main_Texture.png");
	TextureSize.x = 94;
	TextureSize.y = 100;

	Rect.width = 94;
	Rect.height = 100;
	
	currentFrame = 0.f;
	numberFrame = 4;
	SpeedAnimation = 0.01f;
	SpriteTexturePositionX = 0;
	SpriteTexturePositionY = 0;
	SpriteOffset = 95;

	MoveSpeed = 20.f;

	GunOffset.y = -Rect.height / 2;

	bIsDirectionX = true;

	bIsEnabledAutoFire = false;

	ReloadWeaponTime = 1.f;

	Team = ETeam::Friend;

	Direction = sf::Vector2f(0.f, -1.f);
}

float& FPlayer::GetHP()
{
	return HP;
}

bool FPlayer::Dead()
{
	currentFrame = 0.f;
	numberFrame = 4;
	SpeedAnimation = 0.01f;
	SpriteTexturePositionX = 0;
	SpriteTexturePositionY = 505;
	SpriteOffset = 95;

	return true;
}
