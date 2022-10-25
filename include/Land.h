/**
 * @file Land.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LAND_H
#define LAND_H

#include "BattleGround.h"

class Land : public BattleGround
{
private:
    /* data */
public:
    /**
     * @brief Construct a new Land object
     * 
     */
    Land();

    /**
     * @brief Destroy the Land object
     * 
     */
    ~Land();

    /**
     * @brief 
     * 
     * @param recruitNumber 
     * @return int 
     */
    int penalty(int* recruitNumber) override;
};


#endif