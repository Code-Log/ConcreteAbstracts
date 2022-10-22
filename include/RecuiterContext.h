#ifndef __RECUITERCONTEXT_H__
#define __RECUITERCONTEXT_H__

#include "Recruits.h"
class RecuiterContext
{
private:
    Recruits *state;
public:
    RecuiterContext(/* args */);
    void request();
    void setState(Recruits *state);
    Recruits* getState(); //for testing purposes
    // ~RecuiterContext();
};




#endif // __RECUITERCONTEXT_H__