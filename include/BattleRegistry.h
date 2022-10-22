#ifndef CONCRETEABSTRACTS_BATTLEREGISTRY_H
#define CONCRETEABSTRACTS_BATTLEREGISTRY_H

#pragma once

#include <Registry.h>
#include <vector>

class BattleRegistry : public Registry
{
private:
    std::vector<UnorderedPair<AbstractCountry*>> battles;

public:
    BattleRegistry();
    ~BattleRegistry() override = default;

    void addRecord(AbstractCountry* country1, AbstractCountry* country2) override;
    std::vector<UnorderedPair<AbstractCountry*>> getRecords(AbstractCountry* country) override;
};

#endif //CONCRETEABSTRACTS_BATTLEREGISTRY_H
