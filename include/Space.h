/*{Decorator Design Pattern: ConcreteComponent}*/
#ifndef SPACE_H
#define SPACE_H

#include "BattleGround.h"

class Space : public BattleGround
{
public:
    Space(/* args */);
    ~Space();

    int penalty(int* recruitNumber) override;
    int SpaceAdaptationSyndrome();
};

#endif