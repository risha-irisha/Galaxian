#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

#include "World.h"

int main()
{
	// создаем окно с заданными параметрами
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Galaxian");

	// создаем объект класса FWorld
	FWorld world(window);

	// это пока не используем
	sf::Clock clock;

	// по окно открыто
	while (window.isOpen())
	{
		// создаем объект - событие
		sf::Event windowEvent;
		// пока есть события?
		while (window.pollEvent(windowEvent))
		{
			// если тип события - закрыть (красный крестик)
			if (windowEvent.type == sf::Event::Closed)
			{
				// то закрываем окно
				window.close();
			}
			// иначе если тип события - нажатие клавиши
			else if (windowEvent.type == sf::Event::KeyPressed) 
			{
				// клавиши - Esc
				if (windowEvent.key.code == sf::Keyboard::Key::Escape)
				{
					// окно закрывается
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
			//const float deltaTime = clock.getElapsedTime().asSeconds();
			//std::cout << deltaTime * 2000.f << "\n";
			//world.Tick(deltaTime * 2000.f);
			world.Tick(1 / 60.f);
		}
		//clock.restart();
	}
	std::cout << "\nGame time: " << world.GetWorldTime();
	return 0;
}