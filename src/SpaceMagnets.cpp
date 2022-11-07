#include <iostream>

#include "SpaceMagnets.h"

SpaceMagnets::SpaceMagnets() : Trap()
{
    this->type = enums::SpaceMagnets;
    std::cout<<"Charging Magnetic Fields"<<std::endl;
    setDamage(200);
}

SpaceMagnets::~SpaceMagnets() = default;