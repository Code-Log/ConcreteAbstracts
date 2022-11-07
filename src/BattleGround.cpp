#include <BattleGround.h>


BattleGround::BattleGround(std::string location)
    : WarTheatre(std::move(location))
{
    attackers = new RecruiterContext();
    defenders = new RecruiterContext();
}

BattleGround::~BattleGround(){
    delete attackers;
    delete defenders;
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

RecruiterContext* BattleGround::getDefenders()
{
    return defenders;
}
void BattleGround::setDefenders(RecruiterContext* defenders)
{

}
RecruiterContext* BattleGround::getAttackers()
{
    return attackers;
}
void BattleGround::setAttackers(RecruiterContext* attackers)
{

}