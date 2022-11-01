/**
 * @file Country.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <vector>
#include <Marine.h>
#include <Soldier.h>
#include <Guardian.h>
#include <Pilot.h>
#include <Medic.h>
#include <WarTheatre.h>
#include <Sea.h>
#include <Land.h>
#include <Air.h>
#include <Space.h>
#include <Trenches.h>
#include <Barricades.h>
#include <Mines.h>
#include <SpaceMagnets.h>
#include <Recruits.h>
#include <Citizens.h>
#include <Refugee.h>
#include <ArmoryFacade.h>

class Recruits;

enum EconomicClass
{
    FIRST_WORLD = 1,
    SECOND_WORLD = 2,
    THIRD_WORLD = 3
};

class Country
{
public:
    /**
     * @brief Construct a new Country object
     * 
     * @param countryName 
     */
    explicit Country(std::string countryName);

    /**
     * @brief 
     * 
     * @return Country* 
     */
    Country* cloneCountry();

    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    const std::string& getName() const;

      /**
     * @brief Get the NotEnlisted object
     *
     * @return int
     */
    int getNotEnlisted() const;

       /**
     * @brief Get the Population object
     *
     * @return int
     */
    int getPopulation() const;

    /**
     * @brief Get the Power object
     * 
     * @return int 
     */
    int getPower() const;

    /**
     * @brief Set the Power object
     * 
     * @param power 
     */
    void setPower(int power);

    /**
     * @brief Get the Economy object
     * 
     * @return int 
     */
    int getEconomy() const;

    /**
     * @brief Set the Economy object
     * 
     * @param economy 
     */
    void setEconomy(int economy);
     /**
     * @brief Recruits Soldiers
     *
     * @param squadSize
     */
    void recruitSoldiers(int squadSize);
     /**
     * @brief Recruits Guardians
     *
     * @param squadSize
     */
    void recruitGuardians(int squadSize);
     /**
     * @brief Recruits Medics
     *
     * @param squadSize
     */
    void recruitMedics(int squadSize);
     /**
     * @brief Recruits Marines
     *
     * @param squadSize
     */
    void recruitMarines(int squadSize);
     /**
     * @brief Recruits Pilots
     * s
     * @param squadSize
     */
    void recruitPilots(int squadSize);

    /**
     * @brief Updates the population size by counting the survivers.
     *
     */
    void updatePopulationSize();

     /**
     * @brief Updates the power of a country
     *
     */
    void updatePower();

     /**
     * @brief Adds warTheatre. If the warTheatre type already exists does nothing. ?Only add if relevent recruits exist?
     * @param location
     */
    void addWarFront(const std::string& location);
      /**
     * @brief returns specified wartheatre if it exists
     * @param Type
     */
    WarTheatre* getWarFront(std::string Type);

     /**
     * @brief Adds traps to avalable wartheatres. ? Restricts the what kinds of traps can be added to a wartheatre.
     * @param battleGround
     * @param TrapName 
     * 
     */
    void setTrap(WarTheatre* battleGround, std::string TrapName );

    /**
     * @brief Destroy the Country object
     * 
     */
    ~Country();
private:
    std::string countryName;
    int power;
    int populationSize;
    int economy;
    int notEnlisted;
    EconomicClass economicClass;
    // bool Marines;
    // bool Guardians;
    // bool Pilots;
    // bool Soldiers;
    std::vector<WarTheatre*> warTheatres;
    std::vector<Recruits*> recruits;
    Citizens* citizens;
    Refugee* refugees;
    ArmoryFacade armoryFacade;
};

#endif
