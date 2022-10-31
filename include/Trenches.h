/**
 * @file Trenches.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TRENCHES_H
#define TRENCHES_H

#include "Trap.h"

class Trenches : public Trap
{
public:
    /**
     * @brief Construct a new Trenches object
     * 
     */
    Trenches();

    /**
     * @brief Destroy the Trenches object
     * 
     */
    ~Trenches() override;
};

#endif