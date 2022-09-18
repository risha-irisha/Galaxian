#include "WhiteSpaceshipEnemy.h"

FWhiteSpaceshipEnemy::FWhiteSpaceshipEnemy(FWorld& World) : FEnemy(World)
{
	Texture.loadFromFile("./Content/Textures/Main_Texture.png");
	TextureSize.x = 39;
	TextureSize.y = 55;

	Rect.width = 40;
	Rect.height = 55;

	//SetSpriteRect(0, 708);

	GunOffset.y = -Rect.height / 2;

	currentFrame = 0.f;
	numberFrame = 4;
	SpeedAnimation = 0.01f;
	SpriteTexturePositionX = 0;
	SpriteTexturePositionY = 708;
	SpriteOffset = 41;

	bIsDirectionX = true;

	//bIsEnabledAutoFire = true;

	//MoveSpeed = 20.f;
}