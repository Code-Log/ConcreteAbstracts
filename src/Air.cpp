#include <Air.h>
#include <iostream>

Air::Air() : BattleGround("Air")
{
    std::cout<<"The Skies Shall Rain Death"<<std::endl;
    setDamage(0);
}

Air::~Air() = default;

int Air::penalty(int* recruitNumber)
{
    int force = (*recruitNumber * gForce())/100;

    *recruitNumber = *recruitNumber - force;
    return force;
}

int Air::gForce()
{
    return 18;
}