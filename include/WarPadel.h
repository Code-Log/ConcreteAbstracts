//Somewhat of blackbox testing and letting off emotions

#include<BattleRegistry.h>
#include<AllyRegistry.h>
#include<Country.h>
#include<CountryHistory.h>
#include<iostream>
#include<string>
class WarPadel //Meyers Implementation
{
private:
    Country** countries;
    std::string* names;
    Registry* allyRegistry;
    Registry* battleRegistry;
    CountryHistory* historyBook;
    int historyChapters;
    ArmoryFacade* capatalists;
    int test;//for testing purposes
protected:
    WarPadel();
    ~WarPadel();
public:
    void Phase1();
    void Phase2();
    void Phase3();
    void startPedaling();
    void stopPedaling();
    // void runGUIEngine();
    // AllyRegistry getAllyRegistry();
    Registry* getBattleRegistry();

    void UserCountryInput();
    std::string nameGenerator();
    void setWarTheatres(Country* country);
    void selectWarTheatres();
    std::string outPutCountries();
    std::string countryRanks(); //sorts countries by rank ank returns string
    bool makeDecisionPhase2();
    void Dispute();
    void update();
    void WarPrep(int start, int end);
    void setTraps(Country* country);
    void setMilitary(Country* country);
    void purchaseWeapons(Country* country);
    bool Randomise();
    void buyTraps();
    void enlisting();
    void purchaseInput();
    void fireExchange();
    bool CountryHasFallen(Country* country);
    void attack(Country* attacker, Country* defender);
    bool transportRefugees(Country* country, int amount);
    void combat(Recruits* attacker, Recruits* defender);
    void setOffTraps(Recruits* invaders, WarTheatre* battleField, std::string& Vessel);
    void battleWon(Country* winner, Country* loser);
    void unsavedUpdate();
    void returnRefugees(Country* country);
    void teams();
    void Negotiations();
    void history();




    // void setTest(int data); //for testing purposes.
    // int getTest();//for testing purposes.
    // void setAllyRegistry(AllyRegistry &ar);
    // void setBattleRegistry(BattleRegistry &br);
    static WarPadel& getInstanceWarPadel();
    
};


