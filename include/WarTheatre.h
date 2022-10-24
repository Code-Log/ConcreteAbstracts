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

class WarTheatre
{
private:
    int damage;
    std::string location;

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
     * @brief Get the Damage object
     * 
     * @return int 
     */
    int getDamage();

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
     * @param recruitNumber 
     * @return int 
     */
    virtual int penalty(int* recruitNumber) = 0;
};

#endif