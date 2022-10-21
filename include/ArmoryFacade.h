//
// Created by andreas on 2022/10/21.
//

#ifndef CONCRETEABSTRACTS_ARMORYFACADE_H
#define CONCRETEABSTRACTS_ARMORYFACADE_H

#include "TransportContext.h"
#include "RecuiterContext.h"

class ArmoryFacade
{
public:
    ArmoryFacade();
    // Did purchase succeed
    bool purchaseWeapon(Recruits* recruits);
    bool purchaseAttackVessel(Recruits* recruits);
    bool purchaseSupplies(Recruits* recruits);
private:
    TransportContext* transportContext;
    RecuiterContext* recuiterContext;
};

#endif //CONCRETEABSTRACTS_ARMORYFACADE_H
