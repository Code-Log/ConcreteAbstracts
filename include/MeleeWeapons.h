#ifndef MELEEWEAPONS_H
#define MELEEWEAPONS_H
#include "AttackWeapon.h"

class MeleeWeapons : public AttackWeapon {


public:
	int getDamage();

	string getName();
};

#endif
