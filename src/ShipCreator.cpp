#include <ShipCreator.h>

ShipCreator::ShipCreator()
{
    /// \todo: Implement ShipCreator::ShipCreator
}

VesselWeapon* ShipCreator::produceVesselWeapon()
{
	return new Ships();
}

int ShipCreator::getTotal()
{
	return this->total;
}
