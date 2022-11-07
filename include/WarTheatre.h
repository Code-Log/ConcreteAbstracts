/**
 * @file WarTheatre.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef WARTHEATRES_H
#define WARTHEATRES_H

#include <string>
#include "Recruits.h"
#include "RecruiterContext.h"

class WarTheatre
{
public:
    /**
     * @brief Construct a new War Theatre object
     * 
     * @param location 
     */
    explicit WarTheatre(std::string location);
    
    /**
     * @brief Destroy the War Theatre object
     * 
     */
    virtual ~WarTheatre();

    /**
     * @brief Get the Location object
     * 
     * @return std::string 
     */
    std::string getLocation();

    /**
     * @brief 
     * 
     * @param trap 
     */
    virtual void add(WarTheatre* trap)=0;

    /**
     * @brief Get the Damage using a random value between o and the damage member of the trap
     * 
     * @return int 
     */
    int getDamage() const;

    /**
     * @brief Set the Damage object
     * 
     * @param damage 
     */
    void setDamage(int damage);

    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int damageTotal()=0;

    /**
     * @brief 
     * 
     * @return WarTheatre*
     */
    virtual WarTheatre* getTrap()=0;

    /**
     * @brief The casualties gained from environmental extremities (function could evolve to have other factors)
     * 
     * @param recruits
     * @return int
     */
    virtual int penalty(Recruits* recruits) = 0;
    std::string getName();
    void setName(std::string name);
protected:
    std::string name;
private:
    int damage;
    std::string location; //the type Land Air, Sea,Space
    // enum location {Land,Air,Sea,Space}
};

#endif