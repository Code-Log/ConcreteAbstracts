#include <ExplosiveWeaponCreator.h>

ExplosiveWeaponCreator::ExplosiveWeaponCreator()
{

}

AttackWeapon* ExplosiveWeaponCreator::produceAttackWeapon()
{
	return new ExplosiveWeapons();
}