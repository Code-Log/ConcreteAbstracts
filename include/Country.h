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
#include <Recruits.h>
#include <Citizens.h>
#include <Refugee.h>
#include <ArmoryFacade.h>

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
    void addWarFront(std::string location);
    

    /**
     * @brief Destroy the Country object
     * 
     */
    ~Country(); // = default; why default
private:
    std::string countryName;
    int power;
    int populationSize;
    int economy;
    int notEnlisted;
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