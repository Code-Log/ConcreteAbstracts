#ifndef TANKCREATOR_H
#define TANKCREATOR_H

#include <VesselWeaponCreator.h>

class TankCreator : public VesselWeaponCreator {


public:
	TankCreator();

	VesselWeapon* produceVesselWeapon();

	int getTotal();
};

#endif
