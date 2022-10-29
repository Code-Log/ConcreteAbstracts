#include <JetCreator.h>

JetCreator::JetCreator()
{
	/// \todo: Implement JetCreator::JetCreator
}

VesselWeapon* JetCreator::produceVesselWeapon()
{
	return new Jets();
}

int JetCreator::getTotal()
{
	return this->total;
}
