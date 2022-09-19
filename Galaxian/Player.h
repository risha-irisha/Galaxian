#pragma once

#include "Character.h"

class FPlayer : public FCharacter
{
	enum class EAnimation
	{
		Idle,
		Death,
		Max
	};
public:
	FPlayer(FWorld& World);

	void SetHP(float NewHP);
	float GetHP() const;

	bool IsDead() const;

	void Kill();

protected:
	float HP = 100.f;
};

