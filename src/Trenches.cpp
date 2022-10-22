#include <iostream>

#include "Trenches.h"

Trenches :: Trenches() : Trap()
{
    std::cout<<"Digging trenches"<<std::endl;
    setDamage(300);
}

Trenches :: ~Trenches()
{

}