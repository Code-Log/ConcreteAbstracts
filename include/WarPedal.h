//Somewhat of blackbox testing and letting off emotions

#include<BattleRegistry.h>
#include<AllyRegistry.h>
#include<Country.h>
#include<iostream>
#include<string>
class WarPedal //Meyers Implementation
{
private:
    Country** countries;
    std::string* names;
    AllyRegistry allyRegistry;
    BattleRegistry battleRegistry;
    int test;//for testing purposes
protected:
    WarPedal();
    ~WarPedal();
public:
    void Phase1();
    void Phase2();
    void Phase3();
    void startPedaling();
    void stopPedaling();
    // void runGUIEngine();
    // AllyRegistry getAllyRegistry();
    // BattleRegistry getBattleRegistry();

    void UserCountryInput();
    std::string nameGenerator();
    std::string outPutCountries();
    std::string countryRanks(); //sorts countries by rank ank returns string
    void Dispute();



    // void setTest(int data); //for testing purposes.
    // int getTest();//for testing purposes.
    // void setAllyRegistry(AllyRegistry &ar);
    // void setBattleRegistry(BattleRegistry &br);
    static WarPedal& getInstanceWarPedal();
    
};


