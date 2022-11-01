#include <MeleeWeaponCreator.h>

MeleeWeaponCreator::MeleeWeaponCreator()
{

}

AttackWeapon* MeleeWeaponCreator::produceAttackWeapon()
{
	return new MeleeWeapons();
}