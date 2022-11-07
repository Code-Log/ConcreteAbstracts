#include "Sea.h"

#include <iostream>

Sea::Sea() : BattleGround("Sea")
{
   // std::cout<<"Do The Tides Command This Ship?"<<std::endl;
    setDamage(0);
}

Sea::~Sea() = default;

int Sea::penalty(Recruits* recruits)
{
    int size = recruits->getGroupSize();
    int casualties = ( size * seaSickness())/100;

    recruits->setGroupSize(size - casualties);
    return casualties;
}

int Sea::seaSickness()
{
    return 9; //Navy loses 9 percent of pilots from the nature of the environment
}