#pragma once

class FWorld;

class FInputControler
{
public:
	FInputControler(FWorld& World);
	void HandleInput(); // handle - обработка
	void HandleEvent(const sf::Event& Event);

protected:
	FWorld& World;
};

