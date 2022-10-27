/**
 * @file Recruits.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __RECRUITS_H__
#define __RECRUITS_H__

#include <string>
#include <vector>

#include <People.h>
#include <AttackWeapon.h>
#include <VesselWeapon.h>

class Recruits: public People{
private:
    bool isEnlisted;
    std::string militaryType;
    int weaponDamage;
    std::vector<AttackWeapon*> armory;
    std::vector<VesselWeapon*> vehicles;

public:
    /**
     * @brief Construct a new Recruits object
     * 
     */
    Recruits();

    /**
     * @brief If armory is not empty, then fire the weapon currently at the start of the vector.
     * @brief Fire weapon and use up weapon's durability.
     * 
     */
    void fireWeapon();

    /**
     * @brief Destroy the Recruits object
     * 
     */
    virtual ~Recruits();
};


#endif // __RECRUITS_H__