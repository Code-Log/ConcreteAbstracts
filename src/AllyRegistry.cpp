#include <AllyRegistry.h>

AllyRegistry::AllyRegistry()
    : allies()
{
}

void AllyRegistry::addRecord(AbstractCountry* country1, AbstractCountry* country2)
{
    auto newEntry = UnorderedPair(country1, country2);
    for (auto entry : allies)
    {
        if (entry == newEntry)
            return;
    }
    allies.push_back(newEntry);
}

std::vector<UnorderedPair<AbstractCountry*>> AllyRegistry::getRecords(AbstractCountry* country)
{
    std::vector<UnorderedPair<AbstractCountry*>> result;

    for (auto record : allies)
    {
        if (record.has(country))
            result.push_back(record);
    }

    return result;
}