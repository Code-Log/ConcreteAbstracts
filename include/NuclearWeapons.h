#ifndef NUCLEARWEAPONS_H
#define NUCLEARWEAPONS_H

#include <AttackWeapon.h>

class NuclearWeapons : public AttackWeapon {


public:
	int getDamage();

	std::string getName();
};

#endif
