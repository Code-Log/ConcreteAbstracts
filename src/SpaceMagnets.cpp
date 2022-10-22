#include <iostream>

#include "SpaceMagnets.h"

SpaceMagnets :: SpaceMagnets() : Trap()
{
    std::cout<<"Charging Magnetic Fields"<<std::endl;
    setDamage(200);
}

SpaceMagnets :: ~SpaceMagnets()
{

}