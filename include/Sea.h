/*{Decorator Design Pattern: ConcreteComponent}*/
#ifndef SEA_H
#define SEA_H

#include "BattleGround.h"

class Sea : public BattleGround
{
    private:
        /* data */
    public:
        Sea(/* args */);
        ~Sea();

       virtual int penalty(int* recruitNumber);
       int seaSickness();
};


#endif