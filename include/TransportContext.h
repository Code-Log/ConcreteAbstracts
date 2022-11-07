/**
 * @file TransportContext.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_TRANSPORTCONTEXT_H
#define CONCRETEABSTRACTS_TRANSPORTCONTEXT_H

// #pragma once

#include <Transport.h>
#include <Recruits.h>

class TransportContext
{
public:
    /**
     * @brief Construct a new Transport Context object
     * 
     * @param defaultStrategy 
     */
    explicit TransportContext(Transport* defaultStrategy);

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchase(Recruits* recruits);

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchaseInput(Recruits* recruits);

    /**
     * @brief Set the Strategy object
     * 
     * @param newStrategy 
     */
    void setStrategy(Transport* newStrategy);

protected:

private:
    Transport* strategy;
};

#endif //CONCRETEABSTRACTS_TRANSPORTCONTEXT_H
