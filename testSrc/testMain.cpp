#include <AbstractCountry.h>
#include <cstring>
#include <Country.h>
#include <RecuiterContext.h>
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
int testRecruit(Recruits *recruit,RecuiterContext *myContext)
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
    RecuiterContext *myContext = new RecuiterContext();
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

    auto* recruits = new Recruits;

    auto* suppliesTransport = new SuppliesTransport;
    auto* weaponTransport = new WeaponTransport;
    auto* attackVessel = new AttackVessel;

    auto* context = new TransportContext(suppliesTransport);
    context->purchase(recruits);

    context->setStrategy(weaponTransport);
    context->purchase(recruits);

    context->setStrategy(attackVessel);
    context->purchase(recruits);

    delete context;
    delete suppliesTransport;
    delete weaponTransport;
    delete attackVessel;

    return result;
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

//    To add a new test
//    if (std::strcmp(argv[1], "myTest") == 0)
//        return myTest();
}
