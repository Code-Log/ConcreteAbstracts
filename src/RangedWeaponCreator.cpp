#include <RangedWeaponCreator.h>

RangedWeaponCreator::RangedWeaponCreator()
{
	this->total++;
}

AttackWeapon* RangedWeaponCreator::produceAttackWeapon()
{
	return new RangedWeapons();
}

int RangedWeaponCreator::getTotal()
{
	return this->total;
}
