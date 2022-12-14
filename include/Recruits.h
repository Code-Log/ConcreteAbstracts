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
#ifndef CONCRETEABSTRACTS_RECRUITS_H
#define CONCRETEABSTRACTS_RECRUITS_H

#include <string>
#include <vector>

#include <People.h>
#include <AttackWeapon.h>
#include <VesselWeapon.h>

class Country;

class Recruits: public People
{
public:
    /**
     *
     * @return
     */
    int getWeaponDamage() const;

    /**!
     *
     * @param weaponDamage
     */
    void setWeaponDamage(int weaponDamage);\

    /**
     * @brief Construct a new Recruits object
     * 
     */
    Recruits();

    /**
     * @brief If armory is not empty, then fire the weapon currently at the start of the vector.
     * @brief Fire weapon and use up weapon's durability.
     * @brief When a weapon runs out of durability remove it and go the next weapon if a weapon exists.
     * 
     */
    void fireWeapon(Recruits* enemyRecruits);


    /**
     * @brief Add an attack weapon to the armory for the recruits.
     *
     * @param attackWeapon
     */
    void addWeapon(AttackWeapon* attackWeapon);

    /**
     * @brief Add a vessel to the vehicles vector
     *
     * @param vesselWeapon
     */
    void addVessel(VesselWeapon* vesselWeapon);

    /**
     * @brief
     *
     */
    void handle();

    /**
     * @brief Destroy the Recruits object
     * 
     */
    ~Recruits() override;

    /**
     * @brief Get the Country object
     *
     * @return Country*
     */
    Country* getCountry();

    /**
     * @brief Set the Country object
     * 
     * @param country 
     */
    void setCountry(Country* country);

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
    void setName(std::string name);
    std::string getName();
protected:

private:
    bool isEnlisted; //removed as no longer working with individiuals?
    std::string militaryType;
    int weaponDamage;
    std::vector<AttackWeapon*> armory;
    std::vector<VesselWeapon*> vehicles;
    Country* country;
    std::string name;
};


#endif // CONCRETEABSTRACTS_RECRUITS_H