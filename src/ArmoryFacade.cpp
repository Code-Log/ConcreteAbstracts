#include <ArmoryFacade.h>
#include <RecruiterContext.h>

ArmoryFacade::ArmoryFacade()
{
    weaponTransport = new WeaponTransport();
    suppliesTransport = new SuppliesTransport();
    attackVessel = new AttackVessel();
    recruiterContext = new RecruiterContext;
    transportContext = new TransportContext(weaponTransport);
}

bool ArmoryFacade::purchaseWeapon(Recruits *recruits)
{
    transportContext->setStrategy(weaponTransport);
    transportContext->purchase(recruits);

    /// \todo: Implement ArmoryFacade::purchaseWeapon
    return true;
}

bool ArmoryFacade::purchaseAttackVessel(Recruits *recruits)
{
    transportContext->setStrategy(attackVessel);
    /// \todo: Implement ArmoryFacade::purchaseAttackVessel
    return true;
}

bool ArmoryFacade::purchaseSupplies(Recruits *recruits)
{
    transportContext->setStrategy(suppliesTransport);
    /// \todo: Implement ArmoryFacade::purchaseSupplies
    return true;
}

ArmoryFacade::~ArmoryFacade() {
    delete transportContext;
    delete weaponTransport;
    delete suppliesTransport;
    delete attackVessel;
    delete recruiterContext;
}

TransportContext *ArmoryFacade::getTransportContext() const {
    return transportContext;
}

void ArmoryFacade::setTransportContext(TransportContext *transportContext) {
    ArmoryFacade::transportContext = transportContext;
}

RecruiterContext *ArmoryFacade::getRecruiterContext() const {
    return recruiterContext;
}

void ArmoryFacade::setRecruiterContext(RecruiterContext *recruiterContext) {
    ArmoryFacade::recruiterContext = recruiterContext;
}

AttackVessel *ArmoryFacade::getAttackVessel() const {
    return attackVessel;
}

void ArmoryFacade::setAttackVessel(AttackVessel *attackVessel) {
    ArmoryFacade::attackVessel = attackVessel;
}

SuppliesTransport *ArmoryFacade::getSuppliesTransport() const {
    return suppliesTransport;
}

void ArmoryFacade::setSuppliesTransport(SuppliesTransport *suppliesTransport) {
    ArmoryFacade::suppliesTransport = suppliesTransport;
}

WeaponTransport *ArmoryFacade::getWeaponTransport() const {
    return weaponTransport;
}

void ArmoryFacade::setWeaponTransport(WeaponTransport *weaponTransport) {
    ArmoryFacade::weaponTransport = weaponTransport;
}
