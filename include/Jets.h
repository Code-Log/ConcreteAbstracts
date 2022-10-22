#ifndef JETS_H
#define JETS_H

#include <VesselWeaponCreator.h>

class Jets : public VesselWeapon {


public:
	int getDamage();

	int getDefense();

	std::string getName();
};

#endif
