#include <TransportContext.h>

TransportContext::TransportContext(Transport* defaultStrategy)
    : strategy(defaultStrategy)
{
}

void TransportContext::purchase(Recruits *recruits, int numSelection)
{
    strategy->purchase(recruits, numSelection);
}

void TransportContext::setStrategy(Transport* newStrategy)
{
    strategy = newStrategy;
}

TransportContext::~TransportContext(){
    delete strategy;
    strategy = nullptr;
}
