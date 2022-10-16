#include <AbstractCountry.h>

AbstractCountry::AbstractCountry(std::string countryName) : countryName(countryName) 
{}

std::string AbstractCountry::getName() 
{
    return countryName;
}