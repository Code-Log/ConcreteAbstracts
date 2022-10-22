#ifndef CONCRETEABSTRACTS_REGISTRY_H
#define CONCRETEABSTRACTS_REGISTRY_H

#pragma once

#include <vector>
#include <Country.h>
#include <util/UnorderedPair.hpp>

class Registry
{
protected:
    std::vector<Country*> countries;
public:
    virtual void addRecord(Country* country1, Country* country2) = 0;
    virtual std::vector<UnorderedPair<Country*>> getRecords(Country* country) = 0;
    virtual ~Registry() = default;
};

#endif //CONCRETEABSTRACTS_REGISTRY_H
