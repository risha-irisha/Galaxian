#pragma once

#include "Level.h"

class FWorld;

class FEnemySpawner
{
public:
	FEnemySpawner(FWorld& World);
	void SpawnWave(const FLevel& Level);
protected:
	FWorld& World;
};

