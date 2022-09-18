#include "SFML/Graphics.hpp"

#include "InputController.h"
#include "World.h"
#include "Player.h"

FInputControler::FInputControler(FWorld& World) : World(World)
{
}

void FInputControler::HandleInput()
{
	sf::Vector2f dir(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		dir.y = -1.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dir.y = 1.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		dir.x = -1.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		dir.x = 1.f;
	}

	World.GetPlayer().SetInput(dir);
}

void FInputControler::HandleEvent(const sf::Event& Event)
{

	if (Event.type == sf::Event::KeyPressed)
	{
		if (Event.key.code == sf::Keyboard::Key::Space)
		{
			FPlayer& player = World.GetPlayer();
			if (player.CanShot())
			{
				player.Shot();
			}
		}
	}
}
