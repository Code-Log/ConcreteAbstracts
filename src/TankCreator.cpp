#include <TankCreator.h>

TankCreator::TankCreator()
{
    /// \todo: Implement TankCreator::TankCreator
}

VesselWeapon* TankCreator::produceVesselWeapon()
{
	return Tanks();
}

int TankCreator::getTotal()
{
	return this->total;
}
