#include <ShipCreator.h>

ShipCreator::ShipCreator()
{
    /// \todo: Implement ShipCreator::ShipCreator
}

VesselWeapon* ShipCreator::produceVesselWeapon()
{
	return Ships();
}

int ShipCreator::getTotal()
{
	return this->total;
}
