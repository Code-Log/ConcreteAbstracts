#include <iostream>

#include "Trap.h"

Trap::Trap(): WarTheatre("trap")
{
    trap = nullptr;
    active = true;
    lifespan = 400;
}

Trap::~Trap()
{
    delete trap;
}

void Trap::add(WarTheatre* trap)
{
    std::cout<<"Setting trap"<<std::endl;
    if(this->trap == nullptr)
    {
        this->trap = trap;
    }
    else
    {
        this->trap->add(trap);
    }

}

bool Trap::getActive() const
{
    return active;
}

void Trap::setActive(bool active)
{
    this->active = active;
}

int Trap::damageTotal()
{
    if(trap == nullptr)
    {
        return getDamage();
    }
    else if(!active)
    {
        return 0;
    }
    else
    {
        int damage = getDamage();
        this->alterLifespan(damage);
        
        return (damage + trap->damageTotal());
    }
}

void Trap::alterLifespan(int decrease)
{
    this->lifespan = lifespan- decrease;

    if(lifespan<0)
    {
        setActive(false);
    }
}

int Trap::penalty(Recruits* recruits)
{
    if(trap == nullptr)
    {
        return 0;
    }
    else
    {
        return (0 + trap->penalty(recruits));
    }
}