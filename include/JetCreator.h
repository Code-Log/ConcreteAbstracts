#ifndef JETCREATOR_H
#define JETCREATOR_H
#include "VesselWeaponCreator.h"

class JetCreator : public VesselWeaponCreator {


public:
	JetCreator();

	VesselWeapon* produceVesselWeapon();

	int getTotal();
};

#endif
