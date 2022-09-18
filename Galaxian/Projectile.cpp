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
	bool bIsHittingPlayer = false; // попадание в игрока пулей

	for (size_t i = 0; i < World.GetObjects().size(); i++)
	{
		sf::FloatRect enemyRect = World.GetObjects()[i]->GetRect();

		if (ObjectIntersection(Rect, enemyRect))
		{
			//dynamic_cast выполняет приведение одного типа к другому и возвращает тот тип к которому пытаемся привести
			//по сути схему его работы можно рассматривать как функцию у которой есть возвращаемое значение
			//по-простому он мог бы написан как функция ResultType* dynamic_cast<ResultType*>(InitialType* Variable)

			//т.е. в нашем случае мы кастим(приводим тип) FStaticObject* к типу FCharacter*. Значит dynamic_cast вернет тип FCharacter*
			//Если приведение типов завершилось  неудачей, например приводим тип Projectile* к типу FCharacter*
			//dynamic_cast вернет nullptr

			//здесь выполнили приведение типов
			FCharacter* character = dynamic_cast<FCharacter*>(World.GetObjects()[i].get());

			//здесь проверили что каст(приведение типов) прошло успешно
			if (character != nullptr)
			{
				//здесь мы уже можем безопасно использовать переменную character
				//безопасно означает что она не nullptr и программа не упадет если  мы обратимся к нулевому указателю

				//проверяем что команда пули и корабля не совпадает
				if (Team != character->GetTeam())
				{
					//здесь нужно сделать еще 1 dynamic_cast для того чтобы проверить что character является Enemy и  если является то мы просто удаляем его из мира
					FEnemy* enemy = dynamic_cast<FEnemy*>(character);

					if (enemy != nullptr)
					{
						World.GetObjects().erase(World.GetObjects().begin() + i);
						bIsProgectileIntersection = true;
					}
					//Если character это Player то пока ничего не делаем
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
			//приведение типов произошло не успешно, else по сути нам тут не нужен
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
