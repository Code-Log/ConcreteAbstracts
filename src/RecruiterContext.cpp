#include <RecuiterContext.h>
RecuiterContext::RecuiterContext(/* args */)
{
    
}

void RecuiterContext::request()
{
    /// \todo - Implement RecuiterContext::request()
}

void RecuiterContext::setState(Recruits *state)
{
    this->state = state;
}

Recruits* RecuiterContext::getState()
{
    return state;
}
