#pragma once
#include "SFML/Graphics/RenderWindow.hpp"

#include "CommonTypes.h"

class FLevel
{
public:
	void Load(const std::string& FileName);
	const std::vector<FEnemyDescription>& GetEnemiesDescriptions() const;
protected:
	std::vector<FEnemyDescription> EnemiesDescriptions;
};

