#ifndef CONCRETEABSTRACTS_COUNTRYMEMENTO_H
#define CONCRETEABSTRACTS_COUNTRYMEMENTO_H

#include <AbstractCountry.h>

class Country;

class CountryMemento
{
private:
    AbstractCountry* state;
    CountryMemento(AbstractCountry* state);
public:
    ~CountryMemento();
    friend class AbstractCountry;
};

#endif //CONCRETEABSTRACTS_COUNTRYMEMENTO_H
