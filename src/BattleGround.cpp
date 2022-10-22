#include "BattleGround.h"

#include <iostream>

BattleGround :: BattleGround(std::string location) : WarTheatre(location)
{
    
}

BattleGround :: ~BattleGround()
{

}

int BattleGround :: damageTotal()
{
    return getDamage();
}