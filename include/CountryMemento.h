#ifndef CONCRETEABSTRACTS_COUNTRYMEMENTO_H
#define CONCRETEABSTRACTS_COUNTRYMEMENTO_H

#include <Country.h>

class Country;

class CountryMemento
{
private:
    Country* state;
    CountryMemento(Country* state);
public:
    ~CountryMemento();
    friend class AbstractCountry;
};

#endif //CONCRETEABSTRACTS_COUNTRYMEMENTO_H
