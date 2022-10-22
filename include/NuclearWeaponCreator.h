#ifndef NUCLEARWEAPONCREATOR_H
#define NUCLEARWEAPONCREATOR_H
#include "AttackWeaponCreator.h"

class NuclearWeaponCreator : public AttackWeaponCreator {


public:
	NuclearWeaponCreator();

	AttackWeapon* produceAttackWeapon();

	int getTotal();
};

#endif
