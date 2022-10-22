#include <BattleRegistry.h>
#include <unordered_map>

BattleRegistry::BattleRegistry()
    : battles()
{
}

void BattleRegistry::addRecord(Country* country1, Country* country2)
{
    battles.emplace_back(country1, country2);
}

std::vector<UnorderedPair<Country*>> BattleRegistry::getRecords(Country* country)
{
    std::vector<UnorderedPair<Country*>> results;
    for (auto record : battles)
    {
        if (record.first == country)
            results.emplace_back(record);
    }
    return results;
}

