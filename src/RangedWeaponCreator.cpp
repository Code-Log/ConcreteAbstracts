#include <RangedWeaponCreator.h>

RangedWeaponCreator::RangedWeaponCreator()
{
	this->total++;
}

AttackWeapon* RangedWeaponCreator::produceAttackWeapon()
{
	return RangedWeapons();
}

int RangedWeaponCreator::getTotal()
{
	return this->total;
}
