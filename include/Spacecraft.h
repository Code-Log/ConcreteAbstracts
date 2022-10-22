#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include "VesselWeapon.h"

class Spacecraft : public VesselWeapon {


public:
	int getDamage();

	int getDefense();

	string getName();
};

#endif
