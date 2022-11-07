/**
 * @file ArmoryFacade.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_ARMORYFACADE_H
#define CONCRETEABSTRACTS_ARMORYFACADE_H

#include <TransportContext.h>
#include <WeaponTransport.h>
#include <SuppliesTransport.h>
#include <AttackVessel.h>
#include <iostream>

class Recruits;
class RecruiterContext;

class ArmoryFacade
{
public:
    /**
     * @brief Construct a new Armory Facade object
     *
     *
     */
    ArmoryFacade();

    /**
     * @brief Destroy the Armory Facade object
     * 
     */
    virtual ~ArmoryFacade();

    /**
     * @brief Purchase weapons for recruits from Transport
     * 
     * @param recruits 
     * @return true 
     * @return false 
     */
    bool purchaseWeapon(Recruits* recruits);

    /**
     * @brief 
     * 
     * @param recruits 
     * @return true 
     * @return false 
     */
    bool purchaseAttackVessel(Recruits* recruits);

    /**
     * @brief 
     * 
     * @param recruits 
     * @return true 
     * @return false 
     */
    bool purchaseSupplies(Recruits* recruits);

    /**!
     *
     * @return
     */
    TransportContext *getTransportContext() const;

    /**!
     *
     * @param transportContext
     */
    void setTransportContext(TransportContext *transportContext);

    /**!
     *
     * @return
     */
    RecruiterContext *getRecruiterContext() const;

    /**!
     *
     * @param recruiterContext
     */
    void setRecruiterContext(RecruiterContext *recruiterContext);

    /**
     * @brief 
     * 
     * @param recruits 
     * @return true 
     * @return false 
     */
    bool purchaseWeaponInput(Recruits *recruits);

    /**!
     *
     * @return
     */
    AttackVessel *getAttackVessel() const;

    /**!
     *
     * @param attackVessel
     */
    void setAttackVessel(AttackVessel *attackVessel);

    /**!
     *
     * @return
     */
    SuppliesTransport *getSuppliesTransport() const;

    /**!
     *
     * @param suppliesTransport
     */
    void setSuppliesTransport(SuppliesTransport *suppliesTransport);

    /**!
     *
     * @return
     */
    WeaponTransport *getWeaponTransport() const;

    /**!
     *
     * @param weaponTransport
     */
    void setWeaponTransport(WeaponTransport *weaponTransport);

protected:

private:
    TransportContext* transportContext;
    RecruiterContext* recruiterContext;
    AttackVessel* attackVessel;
    SuppliesTransport* suppliesTransport;
    WeaponTransport* weaponTransport;
};

#endif //CONCRETEABSTRACTS_ARMORYFACADE_H
