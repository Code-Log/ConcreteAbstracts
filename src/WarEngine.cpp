#include<WarEngine.h>
#include<util/ListSelectionPrompt.h>
#include<random>

void WarEngine::run(bool human)
{
    prePhase1(human);
    phase1(human);
    phase2(human);
    phase3(human);
    printWarReport();
}

void WarEngine::runEngine()
{
    run(false);
}

void WarEngine::stopEngine()
{
    
}

void WarEngine::runGUIEngine()
{
    run(true);
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
/**
 * @brief Destroy the War Engine:: War Engine object
 * 
 */
WarEngine::~WarEngine()
{
    for(int i = 0;i<8;i++){
        delete countries[i];
    }
}



void WarEngine::prePhase1(bool human)
{
    selectCountry(human);
    selectPoliticalRegime();
}

void WarEngine::phase1(bool human)
{
    
}

void WarEngine::phase2(bool human)
{
    setAllies();
    partitionRecruite();
    buyAndDestributeWeapons();
    setWarTheatres();
    destributeRecruiteToWarTheatres();
    setTraps();
}

void WarEngine::phase3(bool human)
{
    
}
void WarEngine::warLoop () {
    while (disputeActive) {
	    EngineSimulation();
	    printEngineReport();  
    }
}
void WarEngine::EngineSimulation(){
    for(auto c : countries){
        makeDecision(c); //engine strategically 
    }
}

void WarEngine::selectCountry(bool humanCountry)
{
    ListSelectionPrompt countryIndex = {"1","2","3","4","5","6","7","8"};
    std::string countryNames[] = {"South Africa", "United States", "Germany", "Russia", "China", "Argentina", "North Korea", "Australia"};
    
    if(humanCountry) // If human present
    {
        std::string output = "Please select a country:\n";
        int index = 0;
        for (std::string name : countryNames)
        {
            std::string countrySelect = std::to_string(index++) + ". " + name + "\n";
            output += countrySelect;
        }
        int userCountry = std::stoi(countryIndex.getSelection(output));
        
        countries[userCountry] = new Country(countryNames[userCountry]);
        this->humanIndex = userCountry; // there is a human country at index [userCountry]

        for (int i = 0; i < sizeof(countries); i++)
        {
            if (countries[i]->getName() != countryNames[userCountry])
            {
                countries[i] = new Country(countryNames[i]);
            }
        }  
    }
    else  // All countries are AI
    {
        this->humanIndex = -1;
        for (int i = 0; i < sizeof(countries); i++)
        {
            countries[i] = new Country(countryNames[i]);
        }  
    }    
}

void WarEngine::destributeRecruiteToWarTheatres(){

}
void WarEngine::selectPoliticalRegime()
{

    ListSelectionPrompt regime = { "c", "s"};
    std::string prompt = "";
    prompt = "Is ";
    prompt += countries[humanIndex]->getName();
    prompt += " a capatalist nation or socialist society (c/s): ";
    auto ans = regime.getSelection(prompt);
   
    if(ans=="c")
    {
        int economy = countries[humanIndex]->getEconomy();
        economy = economy*1.2;
        countries[humanIndex]->setEconomy(economy);

        std::cout<<countries[humanIndex]->getName()<<"'s economy has risen by 20%. Cheers to the free market!"<<std::endl<<std::endl;
    }
    else
    {
        int people = countries[humanIndex]->getNotEnlisted();
        people = people*1.2;
        countries[humanIndex]->setNotEnlisted(people);

        std::cout<<countries[humanIndex]->getName()<<"'s man power has risen by 20%. A nation is as powerful as it's people!!!"<<std::endl<<std::endl;
    }
}

void WarEngine::setAllies()
{
    
}

void WarEngine::partitionRecruite()
{
    
}

void WarEngine::buyAndDestributeWeapons()
{
    
}

void WarEngine::setWarTheatres()
{
    std::string theatreTypes[] = {"Land", "Sea", "Air", "Space"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 3);

    int oppotunity=4;
    int random;

    for(int x=0; x<8; x++)
    {
        while(oppotunity>0)
        {
            random= dist(gen);
            countries[x]->addWarFront(theatreTypes[random]);
            oppotunity--;
        }
        oppotunity=4;

        std::cout<<countries[x]->getName()<<" war fronts: "<<std::endl;
        std::cout<<countries[x]->allWarFronts()<<std::endl<<std::endl;
    }
}

void WarEngine::setTraps()
{
    
}

void WarEngine::printEngineReport()
{
    
}

void WarEngine::makeDecision(Country* c)
{
    ListSelectionPrompt prompt = {
        "Increase Allies", "Send Recruit and Attack",
        "Send Recruit", "Buy Weapons and allocate to Recruits",
        "Buy and set Traps", "Surrender"
    };

    int index = prompt.getSelectionIndex("Please select an action: ");
    switch (index)
    {
        case 0:
            increaseAllies();
            break;
        case 2:
            sendRecruitAndAttack();
            break;
        case 3:
            buyAndDestributeWeapons();
            break;
        case 4:
            buyAndSetTraps();
            break;
        case 5:
            surrender();
            break;
        default:
            break;
    }
}

void WarEngine::increaseAllies()
{
    
}

void WarEngine::sendRecruitAndAttack()
{
    
}

void WarEngine::sendRecruit()
{
    
}

void WarEngine::buyAndSetTraps()
{
    
}

void WarEngine::surrender()
{
    
}

void WarEngine::printWarReport()
{
    
}


WarEngine::WarEngine()
{
    
}
