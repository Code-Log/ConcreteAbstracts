#include <ArmoryFacade.h>

ArmoryFacade::ArmoryFacade()
{
    weaponTransport = new WeaponTransport();
    suppliesTransport = new SuppliesTransport();
    attackVessel = new AttackVessel();
    recruiterContext = new RecuiterContext;
    transportContext = new TransportContext(weaponTransport);
}

bool ArmoryFacade::purchaseWeapon(Recruits *recruits)
{
    transportContext->setStrategy(weaponTransport);
    // TODO: Implement ArmoryFacade::purchaseWeapon
    return true;
}

bool ArmoryFacade::purchaseAttackVessel(Recruits *recruits)
{
    transportContext->setStrategy(attackVessel);
    // TODO: Implement ArmoryFacade::purchaseAttackVessel
    return true;
}

bool ArmoryFacade::purchaseSupplies(Recruits *recruits)
{
    transportContext->setStrategy(suppliesTransport);
    // TODO: Implement ArmoryFacade::purchaseSupplies
    return true;
}

ArmoryFacade::~ArmoryFacade() {
    delete transportContext;
    delete weaponTransport;
    delete suppliesTransport;
    delete attackVessel;
    delete recruiterContext;
}
