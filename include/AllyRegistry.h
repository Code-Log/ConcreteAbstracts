#ifndef CONCRETEABSTRACTS_ALLYREGISTRY_H
#define CONCRETEABSTRACTS_ALLYREGISTRY_H

#pragma once

#include <Registry.h>
#include <util/UnorderedPair.hpp>

class AllyRegistry : public Registry
{
private:
    std::vector<UnorderedPair<AbstractCountry*>> allies;

public:
    AllyRegistry();
    ~AllyRegistry() override = default;

    void addRecord(AbstractCountry* country1, AbstractCountry* country2) override;
    std::vector<UnorderedPair<AbstractCountry*>> getRecords(AbstractCountry* country) override;
};

#endif //CONCRETEABSTRACTS_ALLYREGISTRY_H
