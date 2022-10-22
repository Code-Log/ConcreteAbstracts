#ifndef MELEEWEAPONCREATOR_H
#define MELEEWEAPONCREATOR_H
#include "AttackWeaponCreator.h"

class MeleeWeaponCreator : public AttackWeaponCreator {


public:
	MeleeWeaponCreator();

	AttackWeapon* produceAttackWeapon();

	int getTotal();
};

#endif
