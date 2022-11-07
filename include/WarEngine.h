#include<BattleRegistry.h>
#include<AllyRegistry.h>
#include<Country.h>
#include<vector>
class WarEngine //Meyers Implementation
{
private:
    AllyRegistry allyRegistry;
    BattleRegistry battleRegistry;
    int test;//for testing purposes
    bool disputeActive = true;
    bool human;
    int humanIndex = -1; //-1 means only AI countries.
    //Otherwise this is the index of the human operated country in the countries array
    int mainAiIndex = -1; // The leading role AI's index. 
    std::vector<std::string> warLog;
protected:
    WarEngine();
    ~WarEngine();
public:
    Country* countries[8];
    void setHuman(bool Human);
    /**
     * @brief calls prePhase1(), phase1(), phase2(),phase3(), printWarReport()
     *
     */
    void run(bool human);

    /**
     * @brief stops the engine
     *
     */
    void stopEngine();

    /**
     * @brief For real mode. Creates 8 AI countries/users and calls run().
     *
     */
    void runEngine();

    /**
     * @brief For design mode. Creates 7 AI countries/users and 1 human user and calls run().
     *
     */
    void runGUIEngine();

    /**
     * @brief This function calls the following functions: selectCountry() and selectPolicalRegime();
     *
     */
    void prePhase1();

    /**
     * @brief
     *
     */
    void phase1();

    /**
     * @brief
     *
     */
    void phase2();

    /**
     * @brief
     *
     */
    void phase3();

    /**
     * @brief Allows a user to select country. Note no 2 users should have the same country
     *
     */
    void selectCountry();

    /**
     * @brief
     *
     */
    void selectPoliticalRegime();

    /**
     * @brief Set the Allies object
     *
     */
    void setAllies();

    /**
     * @brief
     *
     */
    void partitionRecruits();

    /**
     * @brief
     *
     */
    void buyAndDistributeWeapons();

    /**
     * @brief It was decided that the wartheatres would be decided randomly. The function gives each country 4 opportunities to pick a warfront. Since they pick randomly they could pick an existing warfront and their request denied. At the end of the function each country has a minimum of 1 and max of 4 war theatres
     *
     */
    void setWarTheatres();


    /**
     * @brief 
     * 
     */
    void destributeRecruiteToWarTheatres();

    /**
     * @brief
     *
     */
    void setTraps();

    /**
     * @brief
     *
     */
    void printEngineReport();

    /**
     * @brief
     *
     */
    void makeDecision(Country* c);

    /**
     * @brief
     *
     */
    void increaseAllies(Country* c);

    /**
     * @brief
     *
     */
    void sendRecruitAndAttack(Country* c);

    /**
     * @brief
     *
     */
    void sendRecruit(Country* c);

    void buyWeaponsAndAllocateToRecruits(Country* c);

    /**
     * @brief
     *
     */
    void buyAndSetTraps(Country* c);

    /**
     * @brief
     *
     */
    void surrender(Country* c);

    /**
     * @brief One country conquers the other. All resorces are transfered to the conquering country. 
     * 
     * @param conqueror 
     * @param conquered 
     */
    void conquers(Country* conqueror,Country* conquered);

    /**
     * @brief
     *
     */
    void printWarReport();

    /**
     * @brief Get the Ally Registry object
     *
     * @return AllyRegistry
     */
    AllyRegistry getAllyRegistry();

    /**
     * @brief Get the Battle Registry object
     *
     * @return BattleRegistry
     */
    BattleRegistry getBattleRegistry();

    /**
     * @brief Generate a random number in range
     *
     * @return int
     */
    int randomNumGenerator(int min, int max);


    void warLoop();
    void EngineSimulation();

    void setTest(int data); //for testing purposes.
    int getTest() const;//for testing purposes.

    void setAllyRegistry(AllyRegistry &ar);
    void setBattleRegistry(BattleRegistry &br);
    static WarEngine& getInstanceWarEngine();
};


