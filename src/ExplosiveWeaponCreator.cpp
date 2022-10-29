#include <ExplosiveWeaponCreator.h>

ExplosiveWeaponCreator::ExplosiveWeaponCreator()
{
	this->total++;
}

AttackWeapon* ExplosiveWeaponCreator::produceAttackWeapon()
{
	return ExplosiveWeapons();
}

int ExplosiveWeaponCreator::getTotal()
{
	return this->total;
}
