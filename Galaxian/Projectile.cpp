#include "Projectile.h"
#include "World.h"
#include "Enemy.h"
#include "Player.h"
#include "ResourceManager.h"

FProjectile::FProjectile(FWorld& World) : FMovableObject(World)
{
	Texture = FResourceManager::Get().FindOrLoadTexture("./Content/Textures/Main_Texture.png");

	TextureSize.x = 18;
	TextureSize.y = 46;

	Rect.width = 18;
	Rect.height = 46;

	//SetSpriteRect(855, 231);

	//�������� ������ ��� ���� ��������
	Animations.resize(static_cast<int>(EAnimation::Max));

	//Idle(����������� ��� �����(���������) animation
	{
		//�������� ������ �� ������� ��� �������� 0. � ���������� �� ���� ������
		FAnimationData& animData = Animations[static_cast<int>(EAnimation::Idle)];
		animData.numberFrames = 4;
		animData.SpeedAnimation = 0.005f;
		animData.SpriteTexturePositionX = 855;
		animData.SpriteTexturePositionY = 431;
		animData.SpriteOffset = 4;
		animData.AnimationDirection = ETextureAnimationDirection::Vertical;
	}

	////Death
	//{
	//	FAnimationData& animData = Animations[static_cast<int>(EAnimation::Death)];
	//	animData.numberFrames = 4;
	//	animData.SpeedAnimation = 0.005f;
	//	animData.SpriteTexturePositionX = 128;
	//	animData.SpriteTexturePositionY = 797;
	//	animData.SpriteOffset = 1;
	//	animData.AnimationDirection = ETextureAnimationDirection::Horizontal;
	//	animData.bPlayOnlyOnce = true;
	//}

	MoveSpeed = 8.f;
	bEnableBordersCollision = false;	
}

void FProjectile::Tick(float DeltaTime)
{
	FMovableObject::Tick(DeltaTime);
	ProcessProjectileCollision();
}

ETeam FProjectile::GetTeam() const
{
	return Team;
}

void FProjectile::SetTeam(ETeam team)
{
	Team = team;
}

float FProjectile::GetDamage() const
{
	return Damage;
}

void FProjectile::ProcessProjectileCollision()
{
	bool bIsProgectileIntersection = false;

	std::vector<FCharacter*> characterToRemove;

	for (size_t i = 0; i < World.GetObjects().size(); i++)
	{
		sf::FloatRect enemyRect = World.GetObjects()[i]->GetRect();

		if (ObjectIntersection(Rect, enemyRect))
		{
			//dynamic_cast ��������� ���������� ������ ���� � ������� � ���������� ��� ��� � �������� �������� ��������
			//�� ���� ����� ��� ������ ����� ������������� ��� ������� � ������� ���� ������������ ��������
			//��-�������� �� ��� �� ������� ��� ������� ResultType* dynamic_cast<ResultType*>(InitialType* Variable)

			//�.�. � ����� ������ �� ������(�������� ���) FStaticObject* � ���� FCharacter*. ������ dynamic_cast ������ ��� FCharacter*
			//���� ���������� ����� �����������  ��������, �������� �������� ��� Projectile* � ���� FCharacter*
			//dynamic_cast ������ nullptr

			//����� ��������� ���������� �����
			FCharacter* character = dynamic_cast<FCharacter*>(World.GetObjects()[i].get());

			//����� ��������� ��� ����(���������� �����) ������ �������
			if (character != nullptr)
			{
				//����� �� ��� ����� ��������� ������������ ���������� character
				//��������� �������� ��� ��� �� nullptr � ��������� �� ������ ����  �� ��������� � �������� ���������

				//��������� ��� ������� ���� � ������� �� ���������
				if (Team != character->GetTeam())
				{
					bIsProgectileIntersection = true;

					//����� ����� ������� ��� 1 dynamic_cast ��� ���� ����� ��������� ��� character �������� Enemy �  ���� �������� �� �� ������ ������� ��� �� ����
					FEnemy* enemy = dynamic_cast<FEnemy*>(character);

					if (enemy != nullptr)
					{
						enemy->HandleDamage(Damage);
						if (enemy->IsDead())
						{
							characterToRemove.push_back(character);
						}
					}
					else //���� character ��� Player
					{
						if (FPlayer* player = dynamic_cast<FPlayer*>(character))
						{
							//player->SetHP(player->GetHP() - Damage);
							player->HandleDamage(Damage);
						}
					}
				}
			}
		}
	}

	for (size_t i = 0; i < characterToRemove.size(); i++)
	{
		World.RemoveObject(*characterToRemove[i]);
	}

	if (bIsProgectileIntersection || Rect.top + Rect.height < 0 || Rect.top> World.GetWindowSize().y)
	{
		World.RemoveObject(*this);
	}
}

bool FProjectile::ObjectIntersection(const sf::FloatRect& transform1, const sf::FloatRect& transform2)
{
	float left = std::max(transform1.left, transform2.left);
	float top = std::max(transform1.top, transform2.top);
	float right = std::min(transform1.left + transform1.width, transform2.left + transform2.width);
	float bottom = std::min(transform1.top + transform1.height, transform2.top + transform2.height);

	float width = right - left;
	float height = bottom - top;

	return height > 0.f && width > 0.f;
}
