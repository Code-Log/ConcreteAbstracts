#include <iostream>

#include "Mines.h"

Mines::Mines() : Trap()
{
    this->type = enums::Mines;
    std::cout<<"Planting Mines"<<std::endl;
    setDamage(400);
}

Mines::~Mines() = default;