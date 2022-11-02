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

WarEngine::~WarEngine()
{
    
}


WarEngine::WarEngine()
{
    
}
