#include <BattleGround.h>

BattleGround::BattleGround(std::string location)
    : WarTheatre(std::move(location))
{
    
}

BattleGround::~BattleGround() = default;

int BattleGround::damageTotal()
{
    return getDamage();
}

void BattleGround::add(WarTheatre* trap)
{
    //nothing to add
}
