#include <NuclearWeaponCreator.h>

NuclearWeaponCreator::NuclearWeaponCreator()
{
	this.total++;
}

AttackWeapon* NuclearWeaponCreator::produceAttackWeapon()
{
	return NuclearWeapons();
}

int NuclearWeaponCreator::getTotal()
{
	return this.total;
}
