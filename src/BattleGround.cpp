#include <BattleGround.h>

BattleGround::BattleGround(std::string location)
    : WarTheatre(std::move(location))
{
    recruitContext = new RecruiterContext();
}

BattleGround::~BattleGround(){
    delete recruitContext;
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

RecruiterContext* BattleGround::geRecruitContext(){
    return recruitContext;
}