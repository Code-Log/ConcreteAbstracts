#include <CountryHistory.h>

void CountryHistory::addCommit(CountryMemento* memento)
{
    history.push_back(memento);
}

CountryMemento* CountryHistory::removeCommit()
{
    auto* result = history.back();
    history.pop_back();
    return result;
}