#ifndef ABSTRACTCOUNTRY_H
#define ABSTRACTCOUNTRY_H

#include <iostream>
#include <string>
#include <vector>

class AbstractCountry 
{
public:
    explicit AbstractCountry(std::string countryName);
    std::string getName();
    virtual ~AbstractCountry() = default;

    virtual AbstractCountry* cloneCountry() = 0;
private:
    std::string countryName;
};

#endif