#ifndef CONCRETEABSTRACTS_TRANSPORTCONTEXT_H
#define CONCRETEABSTRACTS_TRANSPORTCONTEXT_H

#pragma once

#include <Transport.h>
#include <Recruits.h>

class TransportContext
{
private:
    Transport* strategy;
public:
    explicit TransportContext(Transport* defaultStrategy);
    void purchase(Recruits* recruits);
    void setStrategy(Transport* newStrategy);
};

#endif //CONCRETEABSTRACTS_TRANSPORTCONTEXT_H
