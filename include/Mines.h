/**
 * @file Mines.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MINES_H
#define MINES_H

#include "Trap.h"

class Mines: public Trap
{
public:
    /**
     * @brief Construct a new Mines object
     * 
     */
    Mines();

    /**
     * @brief Destroy the Mines object
     * 
     */
    ~Mines() override;
};


#endif