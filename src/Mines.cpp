#include <iostream>

#include "Mines.h"

Mines :: Mines() : Trap()
{
    std::cout<<"Planting Mines"<<std::endl;
    setDamage(400);
}

Mines :: ~Mines()
{

}