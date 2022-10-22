#include <Country.h>

Country::Country(std::string countryName)
    : countryName(std::move(countryName))
{
}

Country* Country::cloneCountry()
{
    // TODO - Implement Country::cloneCountry()
    return nullptr;
}

const std::string& Country::getName() const
{
    return countryName;
}