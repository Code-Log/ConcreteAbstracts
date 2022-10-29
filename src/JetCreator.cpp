#include <JetCreator.h>

JetCreator::JetCreator()
{
	/// \todo: Implement JetCreator::JetCreator
}

VesselWeapon* JetCreator::produceVesselWeapon()
{
	return Jets();
}

int JetCreator::getTotal()
{
	return this->total;
}
