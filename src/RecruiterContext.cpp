#include <RecruiterContext.h>

RecruiterContext::RecruiterContext(/* args */)
{
    this->state = nullptr;
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

RecruiterContext::~RecruiterContext(){
    delete state;
    state = nullptr;
}
