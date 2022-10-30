/**
 * @file Transport.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_TRANSPORT_H
#define CONCRETEABSTRACTS_TRANSPORT_H

class Recruits;

class Transport
{
public:
    /**
     * @brief 
     * 
     * @param recruits 
     */
    virtual void purchase(Recruits* recruits) = 0;
};

#endif //CONCRETEABSTRACTS_TRANSPORT_H
