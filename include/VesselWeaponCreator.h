#ifndef VESSELWEAPONCREATOR_H
#define VESSELWEAPONCREATOR_H

#include <VesselWeapon.h>

class VesselWeaponCreator {

private:
	int total;

public:
	VesselWeaponCreator();

	VesselWeapon* produce();

protected:
	virtual VesselWeapon* produceVesselWeapon() = 0;

public:
	int getTotal();
};

#endif
