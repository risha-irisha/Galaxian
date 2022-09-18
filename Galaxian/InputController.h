#pragma once

class FWorld;

class FInputControler
{
public:
	FInputControler(FWorld& World);
	void HandleInput();
	void HandleEvent(const sf::Event& Event);

protected:
	FWorld& World;
};

