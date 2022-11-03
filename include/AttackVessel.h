/**
 * @file AttackVessel.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_ATTACKVESSEL_H
#define CONCRETEABSTRACTS_ATTACKVESSEL_H

#include <Transport.h>
#include <VesselWeaponCreator.h>
#include <TankCreator.h>
#include <ShipCreator.h>
#include <JetCreator.h>
#include <SpacecraftCreator.h>
#include <Recruits.h>

class AttackVessel : public Transport
{
public:
    /**
     * @brief Construct a new Attack Vessel object
     * 
     */
    AttackVessel();

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchase(Recruits *recruits, int purchaseType) override ;

protected:

private:
    VesselWeaponCreator* factory[4];
};

#endif //CONCRETEABSTRACTS_ATTACKVESSEL_H
