/**
 * @file WeaponTransport.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_WEAPONTRANSPORT_H
#define CONCRETEABSTRACTS_WEAPONTRANSPORT_H

#pragma once

#include <Transport.h>
#include <AttackWeaponCreator.h>
#include <NuclearWeaponCreator.h>
#include <ExplosiveWeaponCreator.h>
#include <MeleeWeaponCreator.h>
#include <RangedWeaponCreator.h>
#include <Recruits.h>
#include <AttackWeapon.h>

class WeaponTransport : public Transport
{
public:
    /**
     * @brief Construct a new Weapon Transport object
     * 
     */
    WeaponTransport();

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchase(Recruits *recruits, int purchaseType) override;

    ~WeaponTransport() = default;

protected:

private:
    AttackWeaponCreator* factory[4];
};

#endif //CONCRETEABSTRACTS_WEAPONTRANSPORT_H
