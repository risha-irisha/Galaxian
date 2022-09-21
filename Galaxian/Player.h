#pragma once

#include "Character.h"

class FPlayer : public FCharacter
{
public:
	FPlayer(FWorld& World);

	//void SetHP(float NewHP);
	//float GetHP() const;

	/*bool IsDead() const;

	void HandleDamage(float Damage);

	void Kill();*/

	//virtual void OnAnimationEnded();

	virtual void OnHit();

protected:
	//float HP = 100.f;
};

