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
    int penalty(int* recruitNumber) override;
    int seaSickness();
};


#endif