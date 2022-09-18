#pragma once
#include "SFML/Graphics/RenderWindow.hpp"

#include "InputController.h"
#include "Level.h"
#include "EnemySpawner.h"
#include "EnemyController.h"
#include "Player.h"

class FPlayer;
class FStaticObject;

class FWorld
{
public:
	FWorld(sf::RenderWindow& Window);

	void Tick(float DeltaTime);
	void Draw();

	sf::RenderWindow& GetWindow();
	sf::Vector2u GetWindowSize() const;

	FPlayer& GetPlayer();
	FInputControler& GetInputControler();

	std::vector<std::shared_ptr<FStaticObject>>& GetObjects();

	float GetWorldTime();

	bool GetEndGame();
	void SetEndGame(bool Game);

private:
	sf::RenderWindow& Window;

	std::shared_ptr<FPlayer> Player;
	FInputControler InputControler;
	FLevel Level;
	FEnemySpawner enemySpawner;

	FEnemyController enemyController;

	std::vector<std::shared_ptr<FStaticObject>> Objects;

	float WorldTime = 0.f; // общее время с момента запуска игры
	bool endGame = false;
};

