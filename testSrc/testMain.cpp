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
#include <WarTheatre.h>
#include <BattleGround.h>
#include <Trap.h>
#include <Mines.h>
#include <Air.h>
#include <Land.h>
#include <Sea.h>
#include <Trenches.h>
#include <Barricades.h>
#include <SpaceMagnets.h>
#include <Space.h>
 #include <ArmoryFacade.h>



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
    RecruiterContext *myContext = new RecruiterContext();
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

int testWarTheatre()
{
    int result = 0;
    //cout<<"Laat ons begin"<<endl;
    //cout<<"******************** Basic Test**********************"<<endl;

    WarTheatre* theatre;
    theatre = new Mines();
    theatre->add(new Barricades());
    theatre->add(new SpaceMagnets());
    theatre->add(new Trenches());
    theatre->add(new Land());
    //cout << "Damage = " << 
    theatre->damageTotal();//<< endl;
    delete theatre;

    //cout<<"***********************More Intensive******************************"<<endl;

    struct 
    {
        int cash=100;
        int* recruits = new int(100);
    }mockCountry;

    struct 
    {
        int* recruits = new int (100);
        int hp=10000;
    }mockEnemy;

   /* cout<<"MockCountry Recruits: "<<*mockCountry.recruits<<endl;
    cout<<"MockCountry Cash: "<<mockCountry.cash<<endl;

    cout<<"MockEnemy Recruits: "<<*mockEnemy.recruits<<endl;
    cout<<"MockCountry hp: "<<mockEnemy.hp<<endl;

    cout<<"MockCountry creates wartheatres-- The engine or which ever class is responsible should checks if country is eligible for the theatres (has a guardians, marines etc)-- Our mock country has all"<<endl;
    cout<<endl;*/
    
    WarTheatre* L = new Land();
    WarTheatre* S = new Sea();
    WarTheatre* A = new Air();
    WarTheatre* SP = new Space();

   // cout<<endl;
   // cout<<"Pretend battle at sea. Both sides first suffer from the penalty "<<endl;

    S->penalty(mockCountry.recruits);
   // cout<<"MockCountry Recruits: "<<*(mockCountry.recruits)<<endl;
    S->penalty(mockEnemy.recruits);
   // cout<<"MockEnemy Recruits: "<<*(mockEnemy.recruits)<<endl;

    if(*(mockCountry.recruits)==100)
    {
        result = -1;
    }

   // cout<<endl;
   // cout<<"Only enemy suffers from traps"<<endl;
   // cout<<endl;

    //cout<<"MockEnemy HP: " <<(
    mockEnemy.hp = mockEnemy.hp - S->damageTotal();
    //)<<endl;
    //cout<<"HP should stay the same as no traps were set. (Also if HP(or whatever it's called in our system) is refernce structure the function can manipulate it if desired"<<endl;

    if(mockEnemy.hp != 10000)
    {
        result =-1;
    }
   // cout<<"Now adding traps. Subtracting from Economy..."<<endl;
    mockCountry.cash = mockCountry.cash- 30;

    WarTheatre* Temp;
    Temp = new Mines();
    Temp->add(new Barricades());
    mockCountry.cash = mockCountry.cash- 10;
    Temp->add(S);
    S=Temp;

   // cout<<"Again, Engine (or responsible class will need to fireWeapon the finance). And also make sure traps are added to appropriate threates."<<endl;
    //cout<<"Next battle:"<<endl<<endl;;
    //cout<<"Penalties:"<<endl;

    S->penalty(mockCountry.recruits);
   // cout<<"MockCountry Recruits: "<<*(mockCountry.recruits)<<endl;
    S->penalty(mockEnemy.recruits);
    //cout<<"MockEnemy Recruits: "<<*(mockEnemy.recruits)<<endl<<endl;

    //cout<<"Damage to Enemy:"<<endl;
    //cout<<"MockEnemy HP: " <<()
    mockEnemy.hp -S->damageTotal();//<<endl<<endl;
    if(mockEnemy.hp == 10000)
    {
        result = -1;
    }

   // cout<<"Perfect!!"<<endl<<endl;

    //cout<<"Now to loop Enemy stepping over traps until the traps are all dismatled. Basically testing if bool Active does switch to false as traps are triggered"<<endl<<endl;

    int thenHP;
    int nowHP;
    do{
        thenHP= mockEnemy.hp;
        mockEnemy.hp -S->damageTotal();

        nowHP = mockEnemy.hp;

    }
    while(thenHP != nowHP);

    //cout<<"If you seeing this the loop was not infinite and the traps were deactivated. But one more check to be sure...\n Damage: "<<S->damageTotal()<<endl;
    //cout<<"Is it 0? Perfect."<<endl;
    //cout<<"Swap out Sea for the other threatres and other traps but they function identical.\n Also should there be a reactivate() function that awakens traps that are weaker but at a discount XD!!"<<endl;

    delete S;
    delete L;
    delete SP;
    delete A;
    delete mockCountry.recruits;
    delete mockEnemy.recruits;

    //cout<<"****************************END***************************************"<<endl;

    return result;
    
}

int testArmoryFacade()
{
    int result = 0;
        ArmoryFacade* armoryFacade = new ArmoryFacade();
        Recruits* recruits = new Recruits();

        armoryFacade->purchaseAttackVessel(recruits);
        armoryFacade->purchaseSupplies(recruits);
        armoryFacade->purchaseWeapon(recruits);

        delete armoryFacade;
        delete recruits;
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
      if (std::strcmp(argv[1], "testWarTheatre") == 0)
        return testWarTheatre();


//    To add a new test
//    if (std::strcmp(argv[1], "myTest") == 0)
//        return myTest();
}
