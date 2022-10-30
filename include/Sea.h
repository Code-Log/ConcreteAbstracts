/**
 * @file Sea.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SEA_H
#define SEA_H

#include "BattleGround.h"

class Sea : public BattleGround
{
private:
    /* data */
public:
    /**
     * @brief Construct a new Sea object
     * 
     */
    Sea();

    /**
     * @brief Destroy the Sea object
     * 
     */
    ~Sea() override;

    /**
     * @brief The casualties gained from environmental extremities (function could evolve to have other factors)
     * 
     * @param recruits
     * @return int 
     */
    int penalty(Recruits* recruits) override;

    /**
     * @brief 
     * 
     * @return int 
     */
    int seaSickness();
};


#endif