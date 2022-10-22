#ifndef VESSELWEAPONS_H
#define VESSELWEAPONS_H
#include <string>
#include <iostream>

class VesselWeapon {

private:
	std::string name;
	int damage;
	int defense;

public:
	virtual std::string getName() = 0;

	virtual int getDamage() = 0;

	virtual int getDefense() = 0;
};

#endif
