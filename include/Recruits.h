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
    bool isEnlisted; //removed as no longer working with individiuals?
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

    /**
     * @brief Returns militaryType
     * @return string
     * 
     */
    std::string getMilitaryType();

     /**
     * @brief sets militaryType
     * 
     */
    void setMilitaryType(std::string type);

    
};


#endif // __RECRUITS_H__