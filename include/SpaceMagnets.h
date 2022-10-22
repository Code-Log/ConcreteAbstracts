/*{Decorator Design Pattern: ConcreteDecorator}*/
#ifndef SPACEMAGNETS_H
#define SPACEMAGNETS_H

#include "Trap.h"

class SpaceMagnets : public Trap
{
    private:
        /* data */
    public:
        SpaceMagnets(/* args */);
        ~SpaceMagnets();
};

#endif