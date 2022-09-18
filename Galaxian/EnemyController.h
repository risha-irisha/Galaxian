#pragma once

class FWorld;

class FEnemyController
{
public:
	FEnemyController(FWorld& World);
	void Tick(float DeltaTime);
protected:
	FWorld& World;

	float LastTimeEnemyShot = 0.f; // ������� ���������� ��������
	float ReloadWeaponEnemyTime = 2.f; // ����� ����������� ������
};

