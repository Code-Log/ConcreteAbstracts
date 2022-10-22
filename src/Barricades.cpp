#include <iostream>

#include "Barricades.h"

Barricades :: Barricades() : Trap()
{
    std::cout<<"Setting Up Barricades"<<std::endl;
    setDamage(100);
}

Barricades :: ~Barricades()
{

}