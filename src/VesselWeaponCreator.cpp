#include <VesselWeaponCreator.h>

VesselWeaponCreator::VesselWeaponCreator()
{
    /// \todo: Implement VesselWeaponCreator::VesselWeaponCreator
}

VesselWeapon* VesselWeaponCreator::produce()
{
	return produceVesselWeapon();
}

int VesselWeaponCreator::getTotal()
{
	return this->total;
}
