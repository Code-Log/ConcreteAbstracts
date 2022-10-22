#include "Land.h"

#include <iostream>

Land :: Land() : BattleGround("Land")
{
    std::cout<<"Battle Fields Ready For Blood"<<std::endl;
    setDamage(0);
}

Land :: ~Land()
{

}

int Land :: penalty(int* recruitNumber)
{
    return 0;
}