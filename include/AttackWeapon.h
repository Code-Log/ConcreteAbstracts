#ifndef ATTACKWEAPON_H
#define ATTACKWEAPON_H
#include <string>
#include <iostream>
using namespace std;

class AttackWeapon {

private:
	string name;
	int damage;

public:
	virtual int getDamage() = 0;

	virtual string getName() = 0;
};

#endif
