#ifndef COUNTRY_H
#define COUNTRY_H

#include "AbstractCountry.h"

class Country : public AbstractCountry
{
    public:
        Country(std::string countryName);
        virtual AbstractCountry* cloneCountry();
    private:
};

#endif