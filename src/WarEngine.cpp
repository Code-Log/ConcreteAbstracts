#include<WarEngine.h>

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

int WarEngine::getTest()
{
    return test;
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
