#include <NuclearWeaponCreator.h>

NuclearWeaponCreator::NuclearWeaponCreator()
{

}

AttackWeapon* NuclearWeaponCreator::produceAttackWeapon()
{
	return new NuclearWeapons();
}