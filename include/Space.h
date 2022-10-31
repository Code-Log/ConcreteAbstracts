/**
 * @file Space.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SPACE_H
#define SPACE_H

#include "BattleGround.h"

class Space : public BattleGround
{
public:
    /**
     * @brief Construct a new Space object
     * 
     */
    Space();

    /**
     * @brief Destroy the Space object
     * 
     */
    ~Space() override;

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
    int SpaceAdaptationSyndrome();
};

#endif