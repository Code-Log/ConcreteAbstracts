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
    ~Sea();

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
    int seaSickness();
};


#endif