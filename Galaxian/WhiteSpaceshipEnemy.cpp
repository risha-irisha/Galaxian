#include "WhiteSpaceshipEnemy.h"
#include "ResourceManager.h"

FWhiteSpaceshipEnemy::FWhiteSpaceshipEnemy(FWorld& World) : FEnemy(World)
{
	Texture = FResourceManager::Get().FindOrLoadTexture("./Content/Textures/Main_Texture.png");

	TextureSize.x = 39;
	TextureSize.y = 55;

	Rect.width = 40;
	Rect.height = 55;

	GunOffset.y = -Rect.height / 2;
	//SetSpriteRect(0, 708);

	Animations.resize(static_cast<int>(EAnimation::Max));

	HP = 40.f;

	//Idle(переводится как покой(состояние) animation
	{
		FAnimationData& animData = Animations[static_cast<int>(EAnimation::Idle)];
		animData.numberFrames = 4;
		animData.SpeedAnimation = 0.005f;
		animData.SpriteTexturePositionX = 0;
		animData.SpriteTexturePositionY = 707;
		animData.SpriteOffset = 2;
		animData.AnimationDirection = ETextureAnimationDirection::Horizontal;
	}

	//Hit
	{
		FAnimationData& animData = Animations[static_cast<int>(EAnimation::Hit)];
		animData.numberFrames = 1;
		animData.SpeedAnimation = 0.001f;
		animData.SpriteTexturePositionX = 328;
		animData.SpriteTexturePositionY = 707;
		animData.SpriteOffset = 2;
		animData.AnimationDirection = ETextureAnimationDirection::Horizontal;
		animData.bPlayOnlyOnce = true;
	}

	//bIsEnabledAutoFire = true;

	//MoveSpeed = 20.f;
}