/**
 * @file Barricades.h
 * @author ConcreteAbstracts 
 * @brief Decorator Design Pattern: ConcreteDecorator
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BARRICADES_H
#define BARRICADES_H

#include <Trap.h>

class Barricades : public Trap
{
private:
    /* data */
public:
    /**
     * @brief Create the Barricades object
     * 
     */
    Barricades(/* args */);

    /**
     * @brief Destroy the Barricades object
     * 
     */
    ~Barricades();
};



#endif