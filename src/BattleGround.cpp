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
std::string BattleGround::getName(){
    return name;
}
void BattleGround::setName(std::string name){
    this->name = name;
}
RecruiterContext* BattleGround::geRecruitContext(){
    return recruitContext;
}