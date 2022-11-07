#include "Space.h"

#include <iostream>

Space::Space() : BattleGround("Space")
{
    std::cout<<"The Battle Has Left The Stratosphere"<<std::endl;
    setDamage(0);
}

Space::~Space() = default;

int Space::penalty(Recruits* recruits)
{
    int size = recruits->getGroupSize();
    int casualties = ( size * SpaceAdaptationSyndrome())/100;

    recruits->setGroupSize(size - casualties);
    std::cout<<"##### "<<recruits->getCountry()->getName()<<" lost "<<casualties<<" men to Space Adaptation Syndrome #####"<<std::endl;
    return casualties;
}

int Space::SpaceAdaptationSyndrome()
{
    return 27; //Space force loses 27 percent of pilots from the nature of the environment
}