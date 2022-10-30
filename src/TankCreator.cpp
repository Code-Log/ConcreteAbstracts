#include <TankCreator.h>

TankCreator::TankCreator()
{
    /// \todo: Implement TankCreator::TankCreator
}

VesselWeapon* TankCreator::produceVesselWeapon()
{
	return new Tanks();
}