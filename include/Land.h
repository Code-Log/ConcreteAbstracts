/*{Decorator Design Pattern: ConcreteComponent}*/
#ifndef LAND_H
#define LAND_H

#include "BattleGround.h"

class Land : public BattleGround
{
    private:
        /* data */
    public:
        Land(/* args */);
        ~Land();

        virtual int penalty(int* recruitNumber);
};


#endif