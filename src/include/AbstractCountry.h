#ifndef ABSTRACTCOUNTRY_H
#define ABSTRACTCOUNTRY_H

#include <iostream>
#include <string>
#include <vector>

class AbstractCountry 
{
    public:
        AbstractCountry(std::string countryName);
        std::string getName();

        virtual AbstractCountry* cloneCountry() = 0;    
    private:
        std::string countryName;
};

#endif