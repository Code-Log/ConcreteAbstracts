#ifndef RANGEDWEAPONS_H
#define RANGEDWEAPONS_H

#include <AttackWeapon.h>

class RangedWeapons : public AttackWeapon {


public:
	int getDamage();

	std::string getName();
};

#endif
