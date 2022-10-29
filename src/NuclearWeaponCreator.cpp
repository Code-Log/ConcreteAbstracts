#include <NuclearWeaponCreator.h>

NuclearWeaponCreator::NuclearWeaponCreator()
{
	this->total++;
}

AttackWeapon* NuclearWeaponCreator::produceAttackWeapon()
{
	return new NuclearWeapons();
}

int NuclearWeaponCreator::getTotal()
{
	return this->total;
}
