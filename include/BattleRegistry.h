#ifndef CONCRETEABSTRACTS_BATTLEREGISTRY_H
#define CONCRETEABSTRACTS_BATTLEREGISTRY_H

#pragma once

#include <Registry.h>
#include <vector>

class BattleRegistry : public Registry
{
private:
    std::vector<UnorderedPair<Country*>> battles;

public:
    BattleRegistry();
    ~BattleRegistry() override = default;

    void addRecord(Country* country1, Country* country2) override;
    std::vector<UnorderedPair<Country*>> getRecords(Country* country) override;
};

#endif //CONCRETEABSTRACTS_BATTLEREGISTRY_H
