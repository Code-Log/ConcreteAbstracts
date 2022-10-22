#include "Air.h"

#include <iostream>

Air :: Air() : BattleGround("Air")
{
    std::cout<<"The Skies Shall Rain Death"<<std::endl;
    setDamage(0);
}

Air :: ~Air()
{

}

int Air :: penalty(int* recruitNumber)
{
    int force = (*recruitNumber * gForce())/100;

    *recruitNumber = *recruitNumber - force; //if function is to alter the value directly. Depends if recruits is pointer
    return force;
}

int Air :: gForce()
{
    return 18; //Air force loses 18 percent of pilots from the nature of the environment
}