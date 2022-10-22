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

    int penalty(int* recruitNumber) override;
};


#endif