#include "Space.h"

#include <iostream>

Space :: Space() : BattleGround("Space")
{
    std::cout<<"The Battle Has Left The Atmosphere"<<std::endl;
    setDamage(0);
}

Space :: ~Space()
{

}

int Space :: penalty(int* recruitNumber)
{
    int syndrome = (*recruitNumber * SpaceAdaptationSyndrome())/100;

   *recruitNumber = *recruitNumber - syndrome; //if function is to alter the value directly. Depends if recruits is pointer
    return syndrome;
}

int Space :: SpaceAdaptationSyndrome()
{
    return 27; //Space force loses 27 percent of pilots from the nature of the environment
}