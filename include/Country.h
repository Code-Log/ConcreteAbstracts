#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

class Country
{
public:
    explicit Country(std::string countryName);
    Country* cloneCountry();
    const std::string& getName() const;
    ~Country() = default;
private:
    std::string countryName;
};

#endif