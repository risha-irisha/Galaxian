#include "Character.h"
#include "Projectile.h"
#include "World.h"

FCharacter::FCharacter(FWorld& World) : FMovableObject(World)
{
}

void FCharacter::Tick(float DeltaTime)
{
	FMovableObject::Tick(DeltaTime);

	if (bIsEnabledAutoFire && CanShot())
	{
		Shot(); 
	}
}

bool FCharacter::CanShot() const
{
	return World.GetWorldTime() - LastTimeShot >= ReloadWeaponTime;
}

void FCharacter::Shot()
{
	if (!CanShot())
	{
		return;
	}

	std::shared_ptr<FProjectile> projectile;
	projectile = std::make_shared<FProjectile>(World);
	World.GetObjects().push_back(projectile);
	projectile->SetInput(Direction);
	projectile->SetPosition(GetOrigin().x - projectile->GetRect().width / 2, GetOrigin().y - projectile->GetRect().height + GunOffset.y);

	LastTimeShot = World.GetWorldTime();

	projectile->SetTeam(Team);
}

ETeam FCharacter::GetTeam() const
{
	return Team;
}