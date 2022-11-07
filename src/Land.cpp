#include "Land.h"

#include <iostream>

Land::Land() : BattleGround("Land")
{
    // std::cout<<"Battle Fields Ready For Blood"<<std::endl;
    setDamage(0);
}

Land::~Land() = default;

int Land::penalty(Recruits* recruits)
{
    return 0;
}