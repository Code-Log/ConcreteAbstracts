#include <BattleGround.h>


BattleGround::BattleGround(std::string location)
    : WarTheatre(std::move(location))
{
    attackers = new RecruiterContext();
    defenders = new RecruiterContext();
}

BattleGround::~BattleGround(){
    delete attackers;
    attackers = nullptr;
    delete defenders;
    defenders = nullptr;
}

int BattleGround::damageTotal()
{
    return getDamage();
}

WarTheatre* BattleGround:: getTrap()
{
    return nullptr;
}

void BattleGround::add(WarTheatre* trap)
{
    //nothing to add
}

