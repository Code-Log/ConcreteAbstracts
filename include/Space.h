/*{Decorator Design Pattern: ConcreteComponent}*/
#ifndef SPACE_H
#define SPACE_H

#include "BattleGround.h"

class Space : public BattleGround
{
    private:
        /* data */
    public:
        Space(/* args */);
        ~Space();

       virtual int penalty(int* recruitNumber);
       int SpaceAdaptationSyndrome();
};

#endif