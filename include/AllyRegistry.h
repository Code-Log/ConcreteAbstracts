#ifndef CONCRETEABSTRACTS_ALLYREGISTRY_H
#define CONCRETEABSTRACTS_ALLYREGISTRY_H

#pragma once

#include <Registry.h>
#include <util/UnorderedPair.hpp>

class AllyRegistry : public Registry
{
private:
    std::vector<UnorderedPair<Country*>> allies;

public:
    AllyRegistry();
    ~AllyRegistry() override = default;

    void addRecord(Country* country1, Country* country2) override;
    std::vector<UnorderedPair<Country*>> getRecords(Country* country) override;
};

#endif //CONCRETEABSTRACTS_ALLYREGISTRY_H
