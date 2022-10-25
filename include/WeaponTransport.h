/**
 * @file WeaponTransport.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_WEAPONTRANSPORT_H
#define CONCRETEABSTRACTS_WEAPONTRANSPORT_H

#pragma once

#include <Transport.h>

class WeaponTransport : public Transport
{
public:
    /**
     * @brief Construct a new Weapon Transport object
     * 
     */
    WeaponTransport() = default;

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchase(Recruits* recruits) override;
};

#endif //CONCRETEABSTRACTS_WEAPONTRANSPORT_H
