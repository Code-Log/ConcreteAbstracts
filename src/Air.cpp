#include <Air.h>
#include <iostream>

Air::Air() : BattleGround("Air")
{
    std::cout<<"The Skies Shall Rain Death"<<std::endl;
    setDamage(0);
}

Air::~Air() = default;

int Air::penalty(Recruits* recruits)
{
    int size = recruits->getGroupSize();
    int casualties = ( size * gForce())/100;

    std::cout<<"##### "<<recruits->getCountry()->getName()<<" lost "<<casualties<<" men to G-Force effects on their bodies #####"<<std::endl;
   

    recruits->setGroupSize(size - casualties);
    return casualties;
}

int Air::gForce()
{
    return 18;
}