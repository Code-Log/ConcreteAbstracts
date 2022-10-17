#include <AbstractCountry.h>

AbstractCountry::AbstractCountry(std::string countryName) : countryName(std::move(countryName))
{
}

std::string AbstractCountry::getName() 
{
    return countryName;
}