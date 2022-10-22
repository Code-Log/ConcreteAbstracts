#include <CountryMemento.h>

CountryMemento::CountryMemento(AbstractCountry* state)
    : state(state)
{
}

CountryMemento::~CountryMemento()
{
    delete state;
}
