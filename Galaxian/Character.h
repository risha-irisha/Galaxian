#pragma once
#include "SFML/Graphics.hpp"

#include "MovableObject.h"
#include "CommonTypes.h"

class FCharacter : public FMovableObject
{
public:
	FCharacter(FWorld& World);
	virtual void Tick(float DeltaTime);

	bool CanShot() const;
	void Shot();

	ETeam GetTeam() const;

protected:
	sf::Vector2f Direction;

	sf::Vector2f GunOffset;
	ETeam Team;

	bool bIsEnabledAutoFire = false; //�������������� ��������

	float LastTimeShot = 0.f; // ������� ���������� ��������
	float ReloadWeaponTime = 0.1f; // ����� ����������� ������
};