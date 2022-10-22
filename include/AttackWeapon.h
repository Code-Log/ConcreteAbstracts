#ifndef ATTACKWEAPON_H
#define ATTACKWEAPON_H

#include <string>
#include <iostream>

class AttackWeapon {

private:
	std::string name;
	int damage;

public:
	virtual int getDamage() = 0;

	virtual std::string getName() = 0;
};

#endif
