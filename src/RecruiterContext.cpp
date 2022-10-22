#include <RecuiterContext.h>
RecuiterContext::RecuiterContext(/* args */)
{
    
}

void RecuiterContext::request()
{
    //TODO - Implement RecuiterContext::request()
}

void RecuiterContext::setState(Recruits *state)
{
    this->state = state;
}

Recruits* RecuiterContext::getState()
{
    return state;
}
