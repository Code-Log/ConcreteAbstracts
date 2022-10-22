#ifndef SHIPS_H
#define SHIPS_H
#include "VesselWeaponCreator.h"

class Ships : public VesselWeapon {


public:
	int getDamage();

	int getDefense();

	string getName();
};

#endif
