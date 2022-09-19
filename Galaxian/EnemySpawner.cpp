#include "EnemySpawner.h"
#include "World.h"
#include "WhiteSpaceshipEnemy.h"

FEnemySpawner::FEnemySpawner(FWorld& World) : World(World)
{

}

void FEnemySpawner::SpawnWave(const FLevel& Level)
{
	for (size_t i = 0; i < Level.GetEnemiesDescriptions().size(); i++)
	{
		const FEnemyDescription& enemyDescription = Level.GetEnemiesDescriptions()[i];
		
		std::shared_ptr<FEnemy> enemy;
		switch (enemyDescription.EnemyType)
		{
		case EEnemyType::WhiteSpaceship:
			enemy = std::make_shared<FWhiteSpaceshipEnemy>(World);
			break;
		}

		enemy->SetPosition(Level.GetEnemiesDescriptions()[i].Location.x, Level.GetEnemiesDescriptions()[i].Location.y);
		World.GetObjects().push_back(enemy);
	}
}
