#ifndef RANGEDWEAPONCREATOR_H
#define RANGEDWEAPONCREATOR_H

#include <AttackWeaponCreator.h>

class RangedWeaponCreator : public AttackWeaponCreator {


public:
	RangedWeaponCreator();

	AttackWeapon* produceAttackWeapon();

	int getTotal();
};

#endif
