#include "Enemy.h"
#include "World.h"

FEnemy::FEnemy(FWorld& World) : FCharacter(World)
{
	Team = ETeam::Hostile;

	Direction = sf::Vector2f(0.f, 1.f);
}

void FEnemy::OnHit()
{
	std::cout << "HP Enemy: " << HP << "\n";
}
