#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

#include "World.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Galaxian");

	FWorld world(window);

	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (windowEvent.type == sf::Event::KeyPressed)
			{
				if (windowEvent.key.code == sf::Keyboard::Key::Escape)
				{
					window.close();
				}
			}
			world.GetInputControler().HandleEvent(windowEvent);
		}

		if (world.GetEndGame())
		{
			//std::cout << "\n\n\n\t\tEnd Game\n\n\n";
		}
		else
		{
			world.Tick(1 / 60.f);
		}
	}
	std::cout << "\nGame time: " << world.GetWorldTime();
	return 0;
}