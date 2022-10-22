#ifndef SHIPCREATOR_H
#define SHIPCREATOR_H
#include "VesselWeaponCreator.h"

class ShipCreator : public VesselWeaponCreator {


public:
	ShipCreator();

	VesselWeapon* produceVesselWeapon();

	int getTotal();
};

#endif
