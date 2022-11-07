#include <AllyRegistry.h>

AllyRegistry::AllyRegistry()
    : allies()
{
}

void AllyRegistry::addRecord(Country* country1, Country* country2)
{
    auto newEntry = UnorderedPair<Country*>(country1, country2);
    for (auto entry : allies)
    {
        if (entry == newEntry)
            return;
    }
    allies.push_back(newEntry);

    std::cout<<country1->getName()<<" + "<<country2->getName()<<std::endl;
}

std::vector<UnorderedPair<Country*>> AllyRegistry::getRecords(Country* country)
{
    std::vector<UnorderedPair<Country*>> result;

    for (auto record : allies)
    {
        if (record.has(country))
            result.push_back(record);
    }

    return result;
}