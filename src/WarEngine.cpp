#include<WarEngine.h>

void WarEngine::run()
{

}

void WarEngine::runEngine()
{
    
}

void WarEngine::stopEngine()
{
    
}

void WarEngine::runGUIEngine()
{
    
}

AllyRegistry WarEngine::getAllyRegistry()
{
    return allyRegistry;
}

BattleRegistry WarEngine::getBattleRegistry()
{
    return battleRegistry;
}

void WarEngine::setTest(int data)
{
    test = data;
}

int WarEngine::getTest() const
{
    return test;
}

void WarEngine::setAllyRegistry(AllyRegistry &ar)
{
    this->allyRegistry = ar;
}

void WarEngine::setBattleRegistry(BattleRegistry &br)
{
    this->battleRegistry = br;
}

WarEngine& WarEngine::getInstanceWarEngine()
{
    static WarEngine onlyInstance_;
    return onlyInstance_;
}
/**
 * @brief Destroy the War Engine:: War Engine object
 * 
 */
WarEngine::~WarEngine()
{
    
}



void WarEngine::prePhase1()
{
    
}

void WarEngine::phase1()
{
    
}

void WarEngine::phase2()
{
    
}

void WarEngine::phase3()
{
    
}

void WarEngine::selectCountry()
{
    
}

void WarEngine::selectPoliticalRegime()
{
    
}

void WarEngine::setAllies()
{
    
}

void WarEngine::partitionRecruite()
{
    
}

void WarEngine::buyAndDestributeWeapons()
{
    
}

void WarEngine::setWarTheatres()
{
    
}

void WarEngine::setTraps()
{
    
}

void WarEngine::printEngineReport()
{
    
}

void WarEngine::makeDecision(Country* c)
{
    
}

void WarEngine::increaseAllies()
{
    
}

void WarEngine::sendRecruitAndAttack()
{
    
}

void WarEngine::sendRecruit()
{
    
}

void WarEngine::buyAndSetTraps()
{
    
}

void WarEngine::surrender()
{
    
}

void WarEngine::PrintWarReport()
{
    
}


WarEngine::WarEngine()
{
    
}
