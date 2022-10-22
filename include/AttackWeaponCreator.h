#ifndef ATTACKWEAPONCREATOR_H
#define ATTACKWEAPONCREATOR_H
#include <AttackWeapon.h>

class AttackWeaponCreator {

private:
	int total;

public:
	AttackWeaponCreator();

	AttackWeapon* produce();

protected:
	virtual AttackWeapon* produceAttackWeapon() = 0;

public:
	virtual int getTotal() = 0;
};

#endif
