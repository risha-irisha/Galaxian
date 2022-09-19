#include "World.h"
#include "WhiteSpaceshipEnemy.h"
#include "Level.h"
#include "Player.h"

FWorld::FWorld(sf::RenderWindow& InWindow) : 
	Window(InWindow),
	InputControler(*this),
	enemySpawner(*this),
	enemyController(*this)
{
	Player = std::make_shared<FPlayer>(*this);
	Objects.push_back(Player);
	Player->SetPosition(GetWindowSize().x / 2 - Player->GetOrigin().x, GetWindowSize().y - Player->GetRect().height);
	Level.Load("level.txt");

	enemySpawner.SpawnWave(Level);
}

void FWorld::Tick(float DeltaTime)
{
	WorldTime += DeltaTime;

	InputControler.HandleInput();
	for (size_t i = 0; i < Objects.size(); i++)
	{
		Objects[i]->Tick(DeltaTime);
	}

	enemyController.Tick(DeltaTime);

	Draw();
}

void FWorld::Draw()
{
	Window.clear(sf::Color::Black);

	for (size_t i = 0; i < Objects.size(); i++)
	{
		Objects[i]->Draw();
	}

	Window.display();
}

sf::RenderWindow& FWorld::GetWindow()
{
	return Window;
}

sf::Vector2u FWorld::GetWindowSize() const
{
	return Window.getSize();
}

FPlayer& FWorld::GetPlayer()
{
	return *Player;
}

FInputControler& FWorld::GetInputControler()
{
	return InputControler;
}

void FWorld::RemoveObject(const FStaticObject& ObjectToRemove)
{
	for (size_t i = 0; i < Objects.size(); i++)
	{
		std::shared_ptr<FStaticObject> object = Objects[i];
		if (object != nullptr && object.get() == &ObjectToRemove)
		{
			Objects.erase(Objects.begin() + i);
			return;
		}
	}
}

std::vector<std::shared_ptr<FStaticObject>>& FWorld::GetObjects()
{
	return Objects;
}

float FWorld::GetWorldTime()
{
	return WorldTime * 0.1f;
}

bool FWorld::GetEndGame()
{
	return endGame;
}

void FWorld::SetEndGame(bool Game)
{
	endGame = Game;
}
