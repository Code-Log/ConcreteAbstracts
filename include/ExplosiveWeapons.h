#ifndef EXPLOSIVEWEAPONS_H
#define EXPLOSIVEWEAPONS_H

#include <AttackWeapon.h>

class ExplosiveWeapons : public AttackWeapon {
public:
	int getDamage();

	std::string getName();
};

#endif
