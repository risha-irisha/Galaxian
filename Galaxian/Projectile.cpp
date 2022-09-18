#include "Projectile.h"
#include "World.h"
#include "Enemy.h"
#include "Player.h"

FProjectile::FProjectile(FWorld& World) : FMovableObject(World)
{
	Texture.loadFromFile("./Content/Textures/Main_Texture.png");
	TextureSize.x = 18;
	TextureSize.y = 46;

	Rect.width = 18;
	Rect.height = 46;

	//SetSpriteRect(855, 231);

	currentFrame = 0.f;
	numberFrame = 4;
	SpeedAnimation = 0.005f;
	SpriteTexturePositionX = 855;
	SpriteTexturePositionY = 231;
	SpriteOffset = 50;

	MoveSpeed = 10.f;

	bIsBorders = false;

	bIsDirectionX = false;
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
	bool bIsHittingPlayer = false; // ��������� � ������ �����

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
					//����� ����� ������� ��� 1 dynamic_cast ��� ���� ����� ��������� ��� character �������� Enemy �  ���� �������� �� �� ������ ������� ��� �� ����
					FEnemy* enemy = dynamic_cast<FEnemy*>(character);

					if (enemy != nullptr)
					{
						World.GetObjects().erase(World.GetObjects().begin() + i);
						bIsProgectileIntersection = true;
					}
					//���� character ��� Player �� ���� ������ �� ������
					else
					{
						FPlayer* player = dynamic_cast<FPlayer*>(character);
						if (player != nullptr)
						{
							bIsHittingPlayer = true;
							player->GetHP() -= Damage;
							if (player->GetHP() <= 0)
							{
								player->Dead(); 
								//World.GetObjects().erase(World.GetObjects().begin() + i);
							}
						}
					}
				}
			}
			//���������� ����� ��������� �� �������, else �� ���� ��� ��� �� �����
			else
			{

			}
		}
	}

	if (bIsProgectileIntersection || bIsHittingPlayer || Rect.top + Rect.height < 0 || Rect.top> World.GetWindowSize().y)
	{
		for (size_t i = 0; i < World.GetObjects().size(); i++)
		{
			if (World.GetObjects()[i].get() == this)
			{
				World.GetObjects().erase(World.GetObjects().begin() + i);
				return;
			}
		}
	}

	//if (bIsHittingPlayer)
	//{
	//	//bIsHittingPlayer = false;
	//	HP--;
	//	if (HP >= 2)
	//	{
	//		std::cout << HP << " lives left\n";
	//	}
	//	else if (HP == 0)
	//	{
	//		std::cout << "Dead";
	//	}
	//	else
	//	{
	//		std::cout << HP << " life left\n";
	//	}
	//}
}

bool FProjectile::ObjectIntersection(const sf::FloatRect& transform1, const sf::FloatRect& transform2)
{
	float left = std::max(transform1.left, transform2.left);
	float top = std::max(transform1.top, transform2.top);
	float right = std::min(transform1.left + transform1.width, transform2.left + transform2.width);
	float bottom = std::min(transform1.top + transform1.height, transform2.top + transform2.height);

	float width = right - left;
	float height = bottom - top;

	if (height > 10.f && width > 10.f)
	{
		return true;
	}
	else
	{
		return false;
	}
}
