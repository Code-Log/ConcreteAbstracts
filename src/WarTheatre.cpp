#include "WarTheatre.h"

WarTheatre :: WarTheatre(string location)
{
    this->location = location;
    damage=0;
}

WarTheatre :: ~WarTheatre()
{
    
}

void WarTheatre :: setDamage(int damage)
{
    this->damage = damage;
}

int WarTheatre :: getDamage()
{
    int damageLevel = rand()%(this->damage-0 + 1) + 0;
    return damageLevel;
}

string WarTheatre :: getLocation()
{
    return location;
}