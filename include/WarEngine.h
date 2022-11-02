#include<BattleRegistry.h>
#include<AllyRegistry.h>
#include<Country.h>

class WarEngine //Meyers Implementation
{
private:
    AllyRegistry allyRegistry;
    BattleRegistry battleRegistry;
    int test;//for testing purposes
    bool disputeActive;
    Country* countries[8];
    int humanIndex = -1; //-1 means only AI countries.
    //Otherwise this is the index of the human operated country in the countries array
protected:
    WarEngine();
    ~WarEngine();
public:
    /**
     * @brief calls prePhase1(), phase1(), phase2(),phase3(), printWarReport()
     *
     */
    void run();

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
    void selectCountry(bool humanCountry);

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
    void partitionRecruite();

    /**
     * @brief
     *
     */
    void buyAndDestributeWeapons();

    /**
     * @brief It was decided that the wartheatres would be decided randomly. The function gives each country 4 opportunities to pick a warfront. Since they pick randomly they could pick an existing warfront and their request denied. At the end of the function each country has a minimum of 1 and max of 4 war theatres
     *
     */
    void setWarTheatres();

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
    void increaseAllies();

    /**
     * @brief
     *
     */
    void sendRecruitAndAttack();

    /**
     * @brief
     *
     */
    void sendRecruit();

    /**
     * @brief
     *
     */
    void buyAndSetTraps();

    /**
     * @brief
     *
     */
    void surrender();

    /**
     * @brief
     *
     */
    void PrintWarReport();

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

    void setTest(int data); //for testing purposes.
    int getTest() const;//for testing purposes.

    void setAllyRegistry(AllyRegistry &ar);
    void setBattleRegistry(BattleRegistry &br);
    static WarEngine& getInstanceWarEngine();
};


