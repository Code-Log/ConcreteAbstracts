#include <ArmoryFacade.h>

ArmoryFacade::ArmoryFacade(std::string countryName) : countryName(countryName)
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
