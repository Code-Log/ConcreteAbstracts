#include <iostream>

#include "Trenches.h"

Trenches::Trenches() : Trap()
{
    this->type = enums::Trenches;
    std::cout<<"Digging trenches"<<std::endl;
    setDamage(300);
}

Trenches::~Trenches() = default;