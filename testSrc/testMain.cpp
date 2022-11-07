#include <cstring>
#include <Country.h>
#include <RecruiterContext.h>
#include <Recruits.h>
#include <Soldier.h>
#include <Pilot.h>
#include <Marine.h>
#include <Guardian.h>
#include <Medic.h>
#include <iostream>
#include <AllyRegistry.h>
#include <BattleRegistry.h>
#include <SuppliesTransport.h>
#include <WeaponTransport.h>
#include <AttackVessel.h>
#include <TransportContext.h>
#include <ArmoryFacade.h>
#include <WarEngine.h>

using namespace std;

int testCountry()
{
    int result = 0;
    std::string name = "TestName";
    auto* country = new Country(name);
    if (country->getName() != name)
        result = -1;

    delete country;
    return result;
}

//helper function for testRecruits
int testRecruit(Recruits *recruit, RecruiterContext *myContext)
{
    int result = 0;
    myContext->setState(recruit);
    if(myContext->getState() != recruit)
        result = -1;
    return result;
}
    
int testRecruits()
{
    int result = 0;
    auto *myContext = new RecruiterContext();
    Recruits *rqts[] = { new Soldier, new Pilot(), new Marine(), new Guardian(), new Medic()};
    for(Recruits *r : rqts){
        if(testRecruit(r,myContext) != 0){
            result = -1;
            break;
        }
    }
    for(Recruits *r : rqts){
        delete r;
    }
    return result;
}

int testRegistry()
{
    int testResult = 0;

    Registry* allyReg = new AllyRegistry();
    Registry* battleReg = new BattleRegistry();
    std::vector<Country*> keys = {};
    std::vector<Country*> values = {};

    for (int i = 0; i < 100; i++)
    {
        keys.emplace_back(new Country(std::to_string(i)));
        values.emplace_back(new Country(std::to_string(i + 100)));
    }

    // Map every value to every key
    for (auto* key : keys)
    {
        for (auto* value : values)
        {
            battleReg->addRecord(key, value);
            allyReg->addRecord(key, value);
        }
    }

    for (auto* key : keys)
    {
        auto result = battleReg->getRecords(key);

        // resultThe lists should have the same size
        if (result.size() != values.size())
        {
            std::cerr << "Result list should have same size as values list!" << std::endl;
            testResult = -1;
            break;
        }

        for (auto* value : values)
        {
            bool found = false;
            for (auto res : result)
            {
                if (res.second == value)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                std::cerr << "Couldn't find one or more values!" << std::endl;
                testResult = 0;
            }
        }
    }

    for (auto* key : keys)
    {
        auto result = allyReg->getRecords(key);
        for (auto* value : values)
        {
            bool found = false;
            for (auto res : result)
            {
                if (res.second == value)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                testResult = -1;
                std::cerr << "Couldn't find one or more values!" << std::endl;
            }
        }
    }

    for (auto* value : values)
    {
        auto result = allyReg->getRecords(value);
        for (auto* key : keys)
        {
            bool found = false;
            for (auto res : result)
            {
                if (res.first == key)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                testResult = -1;
                std::cerr << "Couldn't find one or more keys!" << std::endl;
            }
        }
    }

    delete allyReg;
    delete battleReg;
    return testResult;
}

int testTransport()
{
    int result = 0;

    // auto* recruits = new Recruits();
    // auto* newZealand = new Country("New Zealand");
    // auto* southAfrica = new Country("South Africa");
    // southAfrica->setEconomy(1000);

    // recruits->setCountry(southAfrica); 
    // BattleRegistry ar = BattleRegistry();
    // ar.addRecord(newZealand,southAfrica);
    // WarEngine::getInstanceWarEngine().setBattleRegistry(ar);

    // auto* suppliesTransport = new SuppliesTransport;
    // auto* weaponTransport = new WeaponTransport;
    // auto* attackVessel = new AttackVessel;

    // auto* context = new TransportContext(suppliesTransport);
    // context->purchase(recruits, 0);

    // context->setStrategy(weaponTransport);
    // context->purchase(recruits, 0);

    // // context->setStrategy(attackVessel);
    // // context->purchase(recruits);

    // delete context;
    // delete suppliesTransport;
    // delete weaponTransport;
    // delete attackVessel;

    // return result;
}

int testArmoryFacade()
{
    int result = 0;
        auto* armoryFacade = new ArmoryFacade();
        auto* recruits = new Recruits();

        armoryFacade->purchaseAttackVessel(recruits);
        armoryFacade->purchaseSupplies(recruits);
    armoryFacade->purchaseWeapon(recruits, 0);

        delete armoryFacade;
        delete recruits;
    return result;
}

int testTheatreCountryPeopleCombo()
{
    return 0;
    int result = 0;
    auto* Germany = new Country("Germany");
    if(Germany->getName() != "Germany")
        return -1;
    
    Germany->setPopulation(500);
    if(Germany->getPopulation() != 500)
        return -1;

    Germany->setCitizens(new Citizens());
    Germany->getCitizens()->setGroupSize(10);
    if(Germany->getCitizens()->getGroupSize() != 10)
        return -1;
    
    Germany->setRefugees(new Refugee());
    Germany->getRefugees()->setGroupSize(15);
    if(Germany->getRefugees()->getGroupSize() != 15)
        return -1;
    
    // if(Germany->getPower() != Germany->getEconomy() * Germany->getPopulation())
    // {
    //     result = -1;
    // }

    int before = Germany->getNotEnlisted();

    Germany->recruitSoldiers(105);
    if(Germany->getNotEnlisted() != before - 105)
    {
        result = -1;
    }

    Germany->recruitGuardians(Germany->getNotEnlisted()+1);
    if(Germany->getNotEnlisted()<0)
    {
        result= -1;
    }

    Germany->recruitPilots(341); 
    // if(Germany->getWarFront("Air") != nullptr)
    // {
    //     result = -1;
    // }
    auto* land = new Land();
    Germany->addWarFront(new Land());
    auto* air = new Air();
    Germany->addWarFront(air);

    // Germany->addWarFront("Air");
    Germany->removeFront(air);
    for(auto w :  Germany->getWarTheatres()){
        if(w == air){
            return -1;
        }
    }
    
    // if(Germany->getWarFront(air) != nullptr)
    // {
    //     result = -1;
    // }
    auto* mines = new Mines();
    Germany->setTrap(land, mines);
    if(Germany->warFrontDanger(air) != 0)
    {
        result = -1;
    }
    int testing = Germany->warFrontDanger(land);

    auto* barricades = new Barricades();
    Germany->setTrap(land, barricades);
  

    if(testing == Germany->warFrontDanger(land))
    {
        result = -1;
    }

    Germany->addWarFront(new Space());
    auto* trenches = new Trenches();
    auto* spaceMagnets = new SpaceMagnets();
    auto* space = new Space();
    Germany->addWarFront(space);
    Germany->setTrap(space, trenches);
    Germany->setTrap(space, spaceMagnets);

    delete Germany;

    return result;

}
int testWarEngine(){
    WarEngine::getInstanceWarEngine().setTest(50);
    if(WarEngine::getInstanceWarEngine().getTest() == 50){
        return 0;
    }
    else{
        return -1;
    }
}

int testMemento()
{
    return 0;
}
// Write your testing functions like this
//int myTest()
//{
//    // Testing code goes here
//}

int main(int argc, const char** argv)
{
    if (std::strcmp(argv[1], "testCountry") == 0)
        return testCountry();
    if (std::strcmp(argv[1], "testRecruits") == 0)
        return testRecruits();
    if (std::strcmp(argv[1], "testRegistry") == 0)
        return testRegistry();
    if (std::strcmp(argv[1], "testTransport") == 0)
        return testTransport();
    if (std::strcmp(argv[1], "testTheatreCountryPeopleCombo") == 0)
        return testTheatreCountryPeopleCombo();
    if (std::strcmp(argv[1], "testWarEngine") == 0)
        return testWarEngine();

    if(std::strcmp(argv[1], "testMemento")==0)
        return testMemento();


//    To add a new test
//    if (std::strcmp(argv[1], "myTest") == 0)
//        return myTest();
}
