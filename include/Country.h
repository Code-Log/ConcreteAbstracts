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
#include <WarTheatre.h>
#include <Citizens.h>
#include <Refugee.h>
#include <ArmoryFacade.h>

class Recruits;

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
     * @brief Destroy the Country object
     * 
     */
    ~Country() = default;
private:
    std::string countryName;
    int power;
    int populationSize;
    int economy;
    std::vector<WarTheatre*> warTheatres;
    std::vector<Recruits*> recruits;
    Citizens citizens;
    Refugee refugees;
    ArmoryFacade armoryFacade;
};

#endif