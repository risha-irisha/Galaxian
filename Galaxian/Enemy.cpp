#include "Enemy.h"

FEnemy::FEnemy(FWorld& World) : FCharacter(World)
{
	Team = ETeam::Hostile;

	Direction = sf::Vector2f(0.f, 1.f);
}
