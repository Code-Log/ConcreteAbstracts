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
    ~Space();

    /**
     * @brief 
     * 
     * @param recruitNumber 
     * @return int 
     */
    int penalty(int* recruitNumber) override;
    
    /**
     * @brief 
     * 
     * @return int 
     */
    int SpaceAdaptationSyndrome();
};

#endif