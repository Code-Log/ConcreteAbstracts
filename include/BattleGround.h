/**
 * @file BattleGround.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BATTLEGROUNDS_H
#define BATTLEGROUNDS_H

#include <WarTheatre.h>

class BattleGround: public WarTheatre
{
public:
    /**
     * @brief Construct a new Battle Ground object
     * 
     * @param location 
     */
    BattleGround(std::string location);

    /**
     * @brief Destroy the Battle Ground object
     * 
     */
    ~BattleGround();

    /**
     * @brief 
     * 
     * @param trap 
     */
    void add(WarTheatre* trap) override;

    /**
     * @brief 
     * 
     * @return int 
     */
    int damageTotal() override;

    /**
     * @brief The casualties gained from environmental extremities (function could evolve to have other factors)
     * 
     * @param recruitNumber 
     * @return int 
     */
    virtual int penalty(Recruits* recruits) = 0; //added
};


#endif