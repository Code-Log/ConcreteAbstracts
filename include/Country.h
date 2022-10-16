#ifndef COUNTRY_H
#define COUNTRY_H

#include "AbstractCountry.h"

class Country : public AbstractCountry
{
    public:
        explicit Country(std::string countryName);
        virtual AbstractCountry* cloneCountry();
        ~Country() override = default;
    private:
};

#endif