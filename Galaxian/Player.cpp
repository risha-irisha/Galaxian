#include "Player.h"
#include "CommonTypes.h"
#include "World.h"
#include "ResourceManager.h"

FPlayer::FPlayer(FWorld& World) : FCharacter(World)
{
	Texture = FResourceManager::Get().FindOrLoadTexture("./Content/Textures/Main_Texture.png");
	
	TextureSize.x = 94;
	TextureSize.y = 100;

	Rect.width = 94;
	Rect.height = 100;
	
	currentFrame = 0.f;

	//выделили память для всех анимаций
	Animations.resize(static_cast<int>(EAnimation::Max));

	//Idle(переводится как покой(состояние) animation
	{
		//Получаем объект из массива под индексом 0. И запоминаем на него ссылку
		FAnimationData& animData = Animations[static_cast<int>(EAnimation::Idle)];
		animData.numberFrames = 4;
		animData.SpeedAnimation = 0.01f;
		animData.SpriteTexturePositionX = 0;
		animData.SpriteTexturePositionY = 0;
		animData.SpriteOffset = 1;
		animData.AnimationDirection = ETextureAnimationDirection::Horizontal;
	}

	//Hit
	{
		FAnimationData& animData = Animations[static_cast<int>(EAnimation::Hit)];
		animData.numberFrames = 4;
		animData.SpeedAnimation = 0.005f;
		animData.SpriteTexturePositionX = 0;
		animData.SpriteTexturePositionY = 406;
		animData.SpriteOffset = 1;
		animData.AnimationDirection = ETextureAnimationDirection::Horizontal;
		animData.bPlayOnlyOnce = true;
	}

	//Death
	{
		FAnimationData& animData = Animations[static_cast<int>(EAnimation::Death)];
		animData.numberFrames = 4;
		animData.SpeedAnimation = 0.001f;
		animData.SpriteTexturePositionX = 0;
		animData.SpriteTexturePositionY = 506;
		animData.SpriteOffset = 1;
		animData.AnimationDirection = ETextureAnimationDirection::Horizontal;
		animData.bPlayOnlyOnce = true;
	}

	MoveSpeed = 20.f;

	GunOffset.y = -Rect.height / 2;

	bIsEnabledAutoFire = false;

	ReloadWeaponTime = 1.f;

	Team = ETeam::Friend;

	Direction = sf::Vector2f(0.f, -1.f);
}

void FPlayer::OnHit()
{
	std::cout << "HP Player: " << HP << "\n";
}

//void FPlayer::SetHP(float NewHP)
//{
//
//}

//float FPlayer::GetHP() const
//{
//	return HP;
//}

//bool FPlayer::IsDead() const
//{
//	return HP <= 0.f;
//}
//
//void FPlayer::HandleDamage(float Damage)
//{
//	if (!IsDead())
//	{
//		HP -= Damage;
//		std::cout << "New Player HP: " << HP << "\n";
//		CurrentAnimationIndex = static_cast<int>(EAnimation::Hit);
//
//		if (IsDead())
//		{
//			Kill();
//		}
//	}
//}
//
//void FPlayer::Kill()
//{
//	CurrentAnimationIndex = static_cast<int>(EAnimation::Death);
//}

//void FPlayer::OnAnimationEnded()
//{
//	if (CurrentAnimationIndex == static_cast<int>(EAnimation::Hit))
//	{
//		CurrentAnimationIndex = static_cast<int>(EAnimation::Idle);
//	}
//	else if(CurrentAnimationIndex == static_cast<int>(EAnimation::Death))
//	{
//		bEnableAnimation = false;
//	}
//}
