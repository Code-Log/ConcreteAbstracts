#include <MeleeWeaponCreator.h>

MeleeWeaponCreator::MeleeWeaponCreator()
{
	this->total++;
}

AttackWeapon* MeleeWeaponCreator::produceAttackWeapon()
{
	return new MeleeWeapons();
}

int MeleeWeaponCreator::getTotal()
{
	return this->total;
}
