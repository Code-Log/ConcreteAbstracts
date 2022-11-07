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
#include <Pilot.h>
#include <Soldier.h>
#include <Guardian.h>
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
#include<CountryMemento.h>
#include<Iterator.h>
#include<RecruitIterator.h>


class Recruits;
class CountryMemento;
enum EconomicClass
{
    FIRST_WORLD = 1,
    SECOND_WORLD = 2,
    THIRD_WORLD = 3
};

// enum LocationTypes
// {
//   Land = 0,
//   Sea = 1,
//   Air = 2,
//   Space = 3
// };

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
     * @brief Create a Memento object
     * 
     * @param country 
     * @return CountryMemento* 
     */
    CountryMemento* createMemento(Country* country);

    /**
     * @brief 
     * 
     * @param mem 
     */
    void reinstateMemento(CountryMemento* mem);

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
     * @brief Setter for the NotEnlisted object
     *
     * @param Amount
     */
    void setNotEnlisted(int Amount);

    std::vector<Refugee*> getRefugees();
    
       /**
     * @brief Get the Population object
     *
     * @return double
     */
    double getPopulation() const;

    /**
     * @brief Get the Power object
     * 
     * @return double 
     */
    double getPower() const;

    /**
     * @brief Set the Power object
     * 
     * @param power 
     */
    void setPower(double power);

    /**
     * @brief Get the Economy object
     * 
     * @return int 
     */
    double getEconomy() const;

    /**
     * @brief Set the Economy object
     * 
     * @param economy 
     */
    void setEconomy(double economy);
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
     * @brief Get the Recruits object
     * 
     * @return std::vector<Recruits*> 
     */
    std::vector<Recruits*> getRecruits();

    /**
     * @brief 
     * 
     * @param Type 
     * @return Recruits* 
     */
    Recruits* searchAndRetrieve(std::string Type);
     /**
     * @brief gets the index of the wartheatre type. Land =0, Sea=1, Air=2, Space =3
     * @param Type
     * @return int
     */
    int getIndex(const std::string& Type);

    /**
     * @brief Create a Recruit Iterator object
     * 
     * @param rec 
     * @return Iterator* 
     *
    */
    RecruitIterator* createRecruitIterator( std::vector<Recruits*> rec);

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
    WarTheatre* getWarFront(const std::string& Type);

      /**
     * @brief returns specified wartheatre if it exists
     * 
     */
    WarTheatre** getWarFront();

     /**
     * @brief Adds traps to avalable wartheatres. ? Restricts the what kinds of traps can be added to a wartheatre.
     * @param battleGround
     * @param TrapName 
     * 
     */
    void setTrap(const std::string& battleGround, const std::string& TrapName );
     /**
     * @brief removes wartheatre
     * @param Location
     * 
     */
    void removeFront(const std::string& Location);

    /**
     * @brief retrieves total damage from all or individual warfronts. parameter Land, Sea, Air, Space, All. Calls damageTotal so will decrease trap lifespan
     * @param totalOf
     * @return int
     */
    int warFrontDanger(const std::string& totalOf);

     /**
     * @brief returns a string of all wartheatres
     * @return string
     */
    std::string allWarFronts();

    /**
     * @brief 
     * 
     * @param ally 
     * @param amount 
     */
    void addRefugee(Country* ally, int amount);

    /**
     * @brief Set the Citizens object
     * 
     * @param amount 
     */
    void setCitizens(int amount);

    /**
     * @brief Get the Citizens object
     * 
     * @return int 
     */
    int getCitizens();

    /**
     * @brief Get the Index War Front object
     * 
     * @param i 
     * @return WarTheatre* 
     */
    WarTheatre* getIndexWarFront(int i);



    /**
     * @brief Destroy the Country object
     * 
     */
    ~Country();

protected:

private:
    std::string countryName;
    double power;
    double populationSize;
    double economy;
    int notEnlisted; 
    EconomicClass economicClass;
    // bool Marines;
    // bool Guardians;
    // bool Pilots;
    // bool Soldiers;
    WarTheatre** warTheatres;
    std::vector<Recruits*> recruits;
    Citizens* citizens;
    std::vector<Refugee*> refugees;
    ArmoryFacade armoryFacade;
};

#endif
