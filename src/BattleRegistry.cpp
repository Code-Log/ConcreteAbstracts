#include <BattleRegistry.h>
#include <unordered_map>

BattleRegistry::BattleRegistry()
    : battles()
{
}

void BattleRegistry::addRecord(AbstractCountry* country1, AbstractCountry* country2)
{
    battles.emplace_back(country1, country2);
}

std::vector<UnorderedPair<AbstractCountry*>> BattleRegistry::getRecords(AbstractCountry* country)
{
    std::vector<UnorderedPair<AbstractCountry*>> results;
    for (auto record : battles)
    {
        if (record.first == country)
            results.emplace_back(record);
    }
    return results;
}

