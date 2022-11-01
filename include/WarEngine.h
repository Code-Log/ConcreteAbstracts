#include<BattleRegistry.h>
#include<AllyRegistry.h>
class WarEngine //Meyers Implementation
{
private:
    AllyRegistry allyRegistry;
    BattleRegistry battleRegistry;
    int test;//for testing purposes
protected:
    WarEngine();
    ~WarEngine();
public:
    void runEngine();
    void stopEngine();
    void runGUIEngine();
    AllyRegistry getAllyRegistry();
    BattleRegistry getBattleRegistry();



    void setTest(int data); //for testing purposes.
    int getTest();//for testing purposes.
    void setAllyRegistry(AllyRegistry &ar);
    void setBattleRegistry(BattleRegistry &br);
    static WarEngine& getInstanceWarEngine();
    
};


