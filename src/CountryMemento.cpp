#include <CountryMemento.h>

CountryMemento::CountryMemento(Country* state)
    : state(state)
{
}

CountryMemento::~CountryMemento()
{
    delete state;
    state = nullptr;
}
