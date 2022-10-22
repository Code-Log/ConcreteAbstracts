#ifndef CONCRETEABSTRACTS_COUNTRYHISTORY_H
#define CONCRETEABSTRACTS_COUNTRYHISTORY_H

#pragma once

#include <vector>
#include <CountryMemento.h>

class CountryHistory
{
private:
    std::vector<CountryMemento*> history;

public:
    CountryHistory() = default;
    void addCommit(CountryMemento* memento);
    CountryMemento* removeCommit();
};

#endif //CONCRETEABSTRACTS_COUNTRYHISTORY_H
