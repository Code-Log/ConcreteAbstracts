#ifndef TANKS_H
#define TANKS_H

#include <VesselWeaponCreator.h>

class Tanks : public VesselWeapon {


public:
	int getDamage();

	int getDefense();

	std::string getName();
};

#endif
