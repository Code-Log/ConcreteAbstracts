/**
 * @file AttackVessel.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_ATTACKVESSEL_H
#define CONCRETEABSTRACTS_ATTACKVESSEL_H

#include <Transport.h>

class AttackVessel : public Transport
{
public:
    /**
     * @brief Construct a new Attack Vessel object
     * 
     */
    AttackVessel() = default;

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchase(Recruits* recruits) override;
};

#endif //CONCRETEABSTRACTS_ATTACKVESSEL_H
