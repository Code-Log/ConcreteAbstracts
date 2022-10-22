#ifndef VESSELWEAPONS_H
#define VESSELWEAPONS_H
#include <string>
#include <iostream>
using namespace std;

class VesselWeapon {

private:
	string name;
	int damage;
	int defense;

public:
	virtual string getName() = 0;

	virtual int getDamage() = 0;

	virtual int getDefense() = 0;
};

#endif
