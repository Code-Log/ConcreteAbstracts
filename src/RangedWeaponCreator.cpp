#include <RangedWeaponCreator.h>

RangedWeaponCreator::RangedWeaponCreator()
{

}

AttackWeapon* RangedWeaponCreator::produceAttackWeapon()
{
	return new RangedWeapons();
}