#include <Country.h>

Country::Country(std::string countryName)
    : countryName(std::move(countryName))
{
}

Country* Country::cloneCountry()
{
    /// \todo - Implement Country::cloneCountry()
    return nullptr;
}

const std::string& Country::getName() const
{
    return countryName;
}

int Country::getPower() const
{
    return power;
}

void Country::setPower(int power)
{
    Country::power = power;
}

int Country::getEconomy() const
{
    return economy;
}

void Country::setEconomy(int economy)
{
    Country::economy = economy;
}
