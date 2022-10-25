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
     * @brief 
     * 
     */
    void handle();

    /**
     * @brief Destroy the Recruits object
     * 
     */
    virtual ~Recruits();
};


#endif // __RECRUITS_H__