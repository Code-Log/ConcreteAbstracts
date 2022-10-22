#ifndef CONCRETEABSTRACTS_TRANSPORT_H
#define CONCRETEABSTRACTS_TRANSPORT_H

#include <Recruits.h>

class Transport
{
public:
    virtual void purchase(Recruits* recruits) = 0;
};

#endif //CONCRETEABSTRACTS_TRANSPORT_H
