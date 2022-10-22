#ifndef MELEEWEAPONS_H
#define MELEEWEAPONS_H

#include <AttackWeapon.h>

class MeleeWeapons : public AttackWeapon {


public:
	int getDamage();

	std::string getName();
};

#endif
