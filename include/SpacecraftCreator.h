#ifndef SPACECRAFTCREATOR_H
#define SPACECRAFTCREATOR_H
#include "VesselWeaponCreator.h"

class SpacecraftCreator : public VesselWeaponCreator {


public:
	SpacecraftCreator();

	VesselWeapon* produceVesselWeapon();

	int getTotal();
};

#endif
