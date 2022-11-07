/**
 * @file Refugee.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_REFUGEE_H
#define CONCRETEABSTRACTS_REFUGEE_H

#include "People.h"
class Refugee : public People
{
public:
    /**
     * @brief Construct a new Refugee object
     * 
     */
    Refugee();

    /**
     * @brief 
     * 
     */
    void influenceEconomy();


protected:

private:
    Country* OwnerCountry;
};


#endif // CONCRETEABSTRACTS_REFUGEE_H