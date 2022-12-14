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
#include <util/colours.h>

class Recruits;

class Transport
{
public:
    /**
     * @brief 
     * 
     * @param recruits 
     */
    virtual void purchase(Recruits *recruits, int purchaseType) = 0;
    virtual ~Transport();

protected:

private:
};

#endif //CONCRETEABSTRACTS_TRANSPORT_H
