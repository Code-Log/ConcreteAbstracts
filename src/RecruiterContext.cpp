#include <RecruiterContext.h>

RecruiterContext::RecruiterContext(/* args */)
{
    
}

void RecruiterContext::request()
{
    /// \todo - Implement RecruiterContext::request()
}

void RecruiterContext::setState(Recruits *state)
{
    this->state = state;
}

Recruits* RecruiterContext::getState()
{
    return state;
}
