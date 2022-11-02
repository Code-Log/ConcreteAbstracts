/**
 * @file SpaceMagnets.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SPACEMAGNETS_H
#define SPACEMAGNETS_H

#include "Trap.h"

class SpaceMagnets : public Trap
{
public:
    /**
     * @brief Construct a new Space Magnets object
     * 
     */
    SpaceMagnets();

    /**
     * @brief Destroy the Space Magnets object
     * 
     */
    ~SpaceMagnets() override;

protected:

private:
};

#endif