#pragma once

#include "Character.h"

class FPlayer : public FCharacter
{
public:
	FPlayer(FWorld& World);

	float& GetHP();

	bool Dead(); // �������

protected:
	float HP = 100.f;
};

