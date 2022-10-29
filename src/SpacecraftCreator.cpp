#include <SpacecraftCreator.h>

SpacecraftCreator::SpacecraftCreator()
{
    /// \todo: Implement SpacecraftCreator::SpacecraftCreator
}

VesselWeapon* SpacecraftCreator::produceVesselWeapon()
{
	return Spacecraft();
}

int SpacecraftCreator::getTotal()
{
    return this->total;
}
