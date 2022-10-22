#include "Sea.h"

#include <iostream>

Sea :: Sea() : BattleGround("Sea")
{
    std::cout<<"Do The Tides Command This Ship?"<<std::endl;
    setDamage(0);
}

Sea :: ~Sea()
{

}

int Sea :: penalty(int* recruitNumber)
{
    int sickness = (*recruitNumber * seaSickness())/100;

    *recruitNumber = *recruitNumber - sickness; //if function is to alter the value directly. Depends if recruits is pointer
    return sickness;
}

int Sea :: seaSickness()
{
    return 9; //Navy loses 9 percent of pilots from the nature of the environment
}