#include "EnemyController.h"
#include "World.h"
#include "Enemy.h"

FEnemyController::FEnemyController(FWorld& World) : World(World)
{
}

void FEnemyController::Tick(float DeltaTime)
{
	std::vector<FEnemy*> enemies;

	for (size_t i = 0; i < World.GetObjects().size(); i++)
	{
		FEnemy* enemy = dynamic_cast<FEnemy*>(World.GetObjects()[i].get());

		if (enemy != nullptr)
		{
			enemies.push_back(enemy);
		}
	}

	if (World.GetWorldTime() - LastTimeEnemyShot >= ReloadWeaponEnemyTime)
	{
		const int randEnemy = rand() % enemies.size();
		enemies[randEnemy]->Shot();
		LastTimeEnemyShot = World.GetWorldTime();
	}
}
