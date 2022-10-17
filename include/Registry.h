#ifndef CONCRETEABSTRACTS_REGISTRY_H
#define CONCRETEABSTRACTS_REGISTRY_H

#pragma once

#include <vector>
#include <AbstractCountry.h>
#include <util/UnorderedPair.hpp>

class Registry
{
protected:
    std::vector<AbstractCountry*> countries;
public:
    virtual void addRecord(AbstractCountry* country1, AbstractCountry* country2) = 0;
    virtual std::vector<UnorderedPair<AbstractCountry*>> getRecords(AbstractCountry* country) = 0;
    virtual ~Registry() = default;
};

#endif //CONCRETEABSTRACTS_REGISTRY_H
