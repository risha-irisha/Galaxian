#pragma once

#include "MovableObject.h"
#include "CommonTypes.h"

class FProjectile : public FMovableObject
{
public:
	FProjectile(FWorld& World);
	virtual void Tick(float DeltaTime);

	ETeam GetTeam() const;
	void SetTeam(ETeam team);

	float GetDamage() const;

	void ProcessProjectileCollision();

	// пересечение объектов
	bool ObjectIntersection(const sf::FloatRect& transform1, const sf::FloatRect& transform2);
protected:
	ETeam Team;

	float Damage = 20.f;
};

