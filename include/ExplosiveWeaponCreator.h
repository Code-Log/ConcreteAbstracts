#ifndef EXPLOSIVEWEAPONCREATOR_H
#define EXPLOSIVEWEAPONCREATOR_H

#include <AttackWeaponCreator.h>

class ExplosiveWeaponCreator : public AttackWeaponCreator {
public:
	ExplosiveWeaponCreator();

	AttackWeapon* produceAttackWeapon();

	int getTotal();
};

#endif
