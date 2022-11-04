#include <iostream>

#include "Barricades.h"

Barricades::Barricades() : Trap()
{
    this->type = enums::Barricades;
    std::cout<<"Setting Up Barricades"<<std::endl;
    setDamage(100);
}

Barricades::~Barricades() = default;