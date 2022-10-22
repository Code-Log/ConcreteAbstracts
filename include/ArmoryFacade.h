#ifndef CONCRETEABSTRACTS_ARMORYFACADE_H
#define CONCRETEABSTRACTS_ARMORYFACADE_H

#include <TransportContext.h>
#include <RecuiterContext.h>
#include <WeaponTransport.h>
#include <SuppliesTransport.h>
#include <AttackVessel.h>

class ArmoryFacade
{
public:
    ArmoryFacade();

    virtual ~ArmoryFacade();

    // Did purchase succeed
    bool purchaseWeapon(Recruits* recruits);
    bool purchaseAttackVessel(Recruits* recruits);
    bool purchaseSupplies(Recruits* recruits);
private:
    TransportContext* transportContext;
    RecuiterContext* recruiterContext;

    AttackVessel* attackVessel;
    SuppliesTransport* suppliesTransport;
    WeaponTransport* weaponTransport;
};

#endif //CONCRETEABSTRACTS_ARMORYFACADE_H
