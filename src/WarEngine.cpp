#include <WarEngine.h>
#include <util/ListSelectionPrompt.h>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <util/enums.h>

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
    initCountryAttributes();
    selectPoliticalRegime(human);
}
void WarEngine::initCountryAttributes(){
    for(auto c : countries){
        c->setEconomy(1000);
    }
}
void WarEngine::phase1(bool human)
{
    std::string reasonsForWar[] = {"Land", "Vengence", "Veganism", "Nationalism"};
    int index;
    int ans;
    int warInit = human ? humanIndex : randomNumGenerator(0,4); //the country starting the war. 
    std::cout<<countries[warInit]->getName()<<" is feeling restless and wishes to declare war on a country"<<std::endl;
    if(human){
        
        warInit = humanIndex;
        ListSelectionPrompt cOptions;
        for(auto c : this->countries){
            cOptions.append(c->getName());
        }
        index = cOptions.getSelectionIndex(std::string(countries[humanIndex]->getName())+"! Who do you want to declare war against"+"!?");
      

        ListSelectionPrompt dispute = {"Land", "Vengence", "Veganism", "Nationalism"};
        ans = dispute.getSelectionIndex(std::string("Why do you want to declare war on ")+countries[index]->getName() + "!?");
    }
    else{// only AI
        index = randomNumGenerator(0,8);
        ans = randomNumGenerator(0,4);
        mainAiIndex = warInit;
        // warInit = randomNumGenerator(0,4);
    }
    std::cout<<countries[warInit]->getName()<<" has declared war on "<<countries[index]->getName()<<" over "<<reasonsForWar[ans]<<"!"<<std::endl;
    battleRegistry.addRecord(countries[humanIndex],countries[index]);
    switch (ans)
    {
        case 0:
            std::cout<<"The is a reason why Empires are great. Rome wasn't built on two blocks and colonisers don't settle for a few square metres. LAND!!! We want it, you've got it but not for long!"<<std::endl;
            break;
        case 1:
            std::cout<<"No, we not crying over spilt milk. We're merely moping up the mess with the decapitated heads of enemies. Nothing to worry about."<<std::endl;
            break;
        case 2:
            std::cout<<"If two vegans argue is it still called beef. Meat is good. Meat is tasty. But not everyone thinks so and we are willing to go cannibal to keep them from our steaks. Steak knives vs chopsticks. It's WAR!!"<<std::endl;
            break;
        case 3:
            std::cout<<"? any ideas on nationalism?"<<std::endl;
            break;
        default:
            break;
    }  
}




void WarEngine::phase2(bool human)
{
    setAllies(human);
    partitionRecruits();
    buyAndDistributeWeapons(human);
    setWarTheatres();
    destributeRecruiteToWarTheatres();
    // setTraps();
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
    std::string countryNames [] = {"South Africa", "United States", "Germany", "Russia", "China", "Asgard", "Westeros", "Australia"};
    ListSelectionPrompt countryIndex = {"South Africa", "United States", "Germany", "Russia", "China", "Asgard", "Westeros", "Australia"};
    
    if(humanCountry) // If human present
    {
        std::string output = "Please select a country: ";
        int userCountry = countryIndex.getSelectionIndex(output);
        countries[userCountry] = new Country(countryNames[userCountry]);
        this->humanIndex = userCountry; // there is a human country at index [userCountry]

       for (int i = 0; i < 8; i++)
        {
            if(countries[i] == NULL)
            {
                countries[i] = new Country(countryNames[i]);
            }      
        }   
    }
    else  // All countries are AI
    {
        for (int i = 0; i < 8; i++)
        {
            countries[i] = new Country(countryNames[i]);
        }
    }
}

void WarEngine::destributeRecruiteToWarTheatres(){

}
void WarEngine::selectPoliticalRegime(bool human)
{
    for(auto c : countries){
        if(c != countries[humanIndex] && c != nullptr){
            int choice = randomNumGenerator(0,1);
            if(choice == 0){
                std::cout<<c->getName()<<" is a capitalist country!"<<std::endl;
                c->setPoliticalRegime(enums::Capitalism);
            }       
            else {
                std::cout<<c->getName()<<" is a socialist country!"<<std::endl;
                c->setPoliticalRegime(enums::socialism);
            }       
        }
    }
    if(!human)
        return;

    ListSelectionPrompt regime = { "Capitalism", "Socialism"};
    std::string prompt;
    prompt = "Is ";
    prompt += countries[humanIndex]->getName();
    prompt += " a capatalist nation or socialist society: ";
    auto ans = regime.getSelectionIndex(prompt);
    // std::cout<<ans<<std::endl;
    if(ans==0)
    {
        countries[humanIndex]->setPoliticalRegime(enums::Capitalism); 
        // int economy = countries[humanIndex]->getEconomy();
        // economy = economy*1.2;
        // countries[humanIndex]->setEconomy(economy);

        std::cout<<countries[humanIndex]->getName()<<"'s economy has risen by 20%. Cheers to the free market!"<<std::endl<<std::endl;
    }
    else
    {
        countries[humanIndex]->setPoliticalRegime(enums::socialism); //population size is now set in partionRecruits
        // int people = countries[humanIndex]->getNotEnlisted();
        // people = people*1.2;
        // countries[humanIndex]->setNotEnlisted(people);
        

        std::cout<<countries[humanIndex]->getName()<<"'s man power has risen by 20%. A nation is as powerful as it's people!!!"<<std::endl<<std::endl;
    }
}

void WarEngine::setAllies(bool human)
{
    ListSelectionPrompt countryIndex = {"South Africa", "United States", "Germany", "Russia", "China", "Asgard", "Westeros", "Australia"};
    
    if(human)
    {
        // Make allies?
        std::string choice;
        std::cout << "Would you like to make allies? [y/n] :";
        std::cin >> choice;
        int userAllyCount = 0;
        int enemyAllyCount = 0;
        int enemyAllyLimit = randomNumGenerator(1, 6 - userAllyCount); // Use 6 to exclude ourCountry and enemyCountry

        //find enemy
        std::vector<UnorderedPair<Country*>> userBattles = this->battleRegistry.getRecords(countries[humanIndex]);
        Country *enemy = userBattles[0].getOther(countries[humanIndex]); // Only one item in battleRegistry so use index 0
        int enemyIndex = 0;
        for(int i = 0; i < 8; i++)
        {
            if(countries[i]->getName() == enemy->getName()) // Find enemy country's index in countries[] attribute
            {
                enemyIndex = i;
                break;
            }    
        }
        auto userAllies = this->allyRegistry.getRecords(countries[humanIndex]);
        auto enemyAllies = this->allyRegistry.getRecords(enemy);
        //We should probably change this to a do while loop
        while(true) // At most 4 allies (break statement at the end to end while loop)
        { 
            //find allies and enemies
            userAllies = this->allyRegistry.getRecords(countries[humanIndex]);
            enemyAllies = this->allyRegistry.getRecords(enemy);
            //allow human to select country
            if(choice == "y" || choice == "Y")
            { 
                bool invalidChoice = true;
                // std::string output = ;
                int allyIndex;
                while(invalidChoice)
                {  
                    bool flag3 = false;
                    allyIndex = countryIndex.getSelectionIndex("Please select a country: ");
                    if(allyIndex == humanIndex){
                        std::cout<<"you can't ally with yourself!"<<std::endl;
                        flag3 = true;
                    }
                    bool flag1 = false;
                    bool flag2 = false;
                    for(auto userAlly : userAllies){ //does userAlly have the country? 
                        if(userAlly.has(countries[allyIndex])){
                            std::cout <<countries[allyIndex]->getName()<< " is already your ally!" << std::endl;
                            flag1 = true;
                        }
                    }
                    for(auto enemyAlly : enemyAllies){ //does enemyAllyies have the country?
                        if(enemyAlly.has(countries[allyIndex])){
                            std::cout <<countries[allyIndex]->getName()<< " is an enemy country!" << std::endl;
                            flag2 = true;
                        }
                    }
                    if(!(flag1 || flag2 || flag3))
                    {
                        invalidChoice = false;
                    }
                    // else
                    // {
                    //     std::cout << "This is the enemy country!" << std::endl;
                    // }
                }
                std::cout<<countries[humanIndex]->getName()<<" has allied itself with "<<countries[allyIndex]->getName()<<std::endl;
                this->allyRegistry.addRecord(countries[humanIndex],countries[allyIndex]);
                userAllyCount++;
                int economy = countries[humanIndex]->getEconomy(); // our country's economy
                countries[humanIndex]->setEconomy(economy - (economy * 0.15)); // Cost is 15% of economy
            }
                
            auto userAllies = this->allyRegistry.getRecords(countries[humanIndex]);
            auto enemyAllies = this->allyRegistry.getRecords(enemy);
            // Initially battleRegistry = {(ourCountry, enemyCountry)} or {(enemyCountry,ourCountry)}

            //allow ai to select country
            if(enemyAllyCount <= enemyAllyLimit)
            {// a better way to do this is just to create a list selection prompt of all the applicable countries choices and randomise that
               while(true)
                {
                    int randomIndex = randomNumGenerator(1, 8); // randomize ally country index
                    bool flag1 = false;
                    bool flag2 = false;
                    for(auto userAlly : userAllies){ //does userAlly have the country? 
                        if(userAlly.has(countries[randomIndex])){
                            flag1 = true;
                            break;
                        }
                    }
                    for(auto enemyAlly : enemyAllies){ //does enemyAllyies have the country?
                        if(enemyAlly.has(countries[randomIndex])){
                            flag2 = true;
                            break;
                        }
                    }
                    if(!flag1 && !flag2) // If not an ally of ourCountry we can make it an ally of the enemy && if not the enemy country itself(or it's allies)
                    {
                        this->allyRegistry.addRecord(enemy,countries[randomIndex]);
                        std::cout<<enemy->getName()<<" has allied itself with "<<countries[randomIndex]->getName()<<std::endl;
                        int economy = countries[humanIndex]->getEconomy(); // our country's economy
                        countries[humanIndex]->setEconomy(economy - (economy * 0.15)); // Cost is 15% of economy
                        enemyAllyCount++;
                        break;
                    } // else loop again to find a suitable enemy ally
                }
            }  
            if(userAllyCount <4)  
                std::cout << "Would you like to make more allies? [y/n] :";
            std::cin >> choice;
            if((userAllyCount == 4 || (choice == "n" || choice == "N")) && enemyAllyCount == enemyAllyLimit){
                std::cout<<"Ally selection has closed"<<std::endl;
                break;
            }
            if((userAllyCount + enemyAllyCount)>= 6){
                std::cout<<"Ally selection has closed"<<std::endl;
                break;
            }
        }
    }
    else // Only AI counrties
    {
        // std::cout<<"human index: "<<humanIndex<<std::endl;
        std::vector<UnorderedPair<Country*>> userAllies = this->allyRegistry.getRecords(countries[mainAiIndex]);
        std::vector<UnorderedPair<Country*>> userBattles = this->battleRegistry.getRecords(countries[mainAiIndex]);
        std::cout<<"do we even get here?"<<std::endl;
        // Initially battleRegistry = {(ourCountry, enemyCountry)} or {(enemyCountry,ourCountry)}
        Country *enemy = userBattles[0].getOther(countries[mainAiIndex]); // Only one item in battleRegistry so use index 0
        int enemyIndex = 0;
        for(int i = 0; i < 8; i++)
        {
            if(countries[i]->getName() == enemy->getName()) // Find enemy country's index in countries[] attribute
            {
                enemyIndex = i;
                break;
            }      
        }

        // The AI user
        int userAllyLimit = randomNumGenerator(1, 4); // Use 6 to exclude ourCountry and enemyCountry
        int userAllyCount = 0;
        int randomIndex  = 0;
        int AIUserIndex = randomNumGenerator(1, 8);
        while(userAllyCount <= userAllyLimit)
        {
            randomIndex = randomNumGenerator(1, 8); // randomize ally country index
            if(AIUserIndex != randomIndex && AIUserIndex != enemyIndex)
            {
                this->allyRegistry.addRecord(countries[AIUserIndex],countries[randomIndex]);
                userAllyCount++;
            }
        }

        int enemyAllyLimit = randomNumGenerator(1, 6 - userAllyCount); // Use 6 to exclude ourCountry and enemyCountry
        int enemyAllyCount = 0;
        while(enemyAllyCount <= enemyAllyLimit)
        {
            randomIndex = randomNumGenerator(1, 8); // randomize ally country index
            
            for(auto userAlly : userAllies)
            {
                if(!userAlly.has(countries[humanIndex]) && enemyIndex != randomIndex) // If not an ally of ourCountry we can make it an all of the enemy
                {
                    this->allyRegistry.addRecord(countries[enemyIndex],countries[randomIndex]);
                    enemyAllyCount++;
                } // else loop again untill enemyAllyLimit reached
            }
        }
    }    
}

void WarEngine::partitionRecruits()
{
    for(Country* country : countries) // Partition population for each country
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1e4, 5e4);

        // Set total population for passed country
        country->setPopulation(dist(gen));

        // Refugees
        country->setRefugees(new Refugee());
        country->getRefugees()->setGroupSize(country->getPopulation() * 0.1); // Initially 10% refugees at start

        // Recruits
        int totalRecruitsLimit = country->getPopulation() - country->getRefugees()->getGroupSize();
        country->setRecruits(std::vector<Recruits*> {new Soldier(), new Pilot(), new Marine(), new Guardian(), new Medic()});
        const int s = 100, m=150, p = 200, g=300, med=150; //prices of each recruit type
        std::vector<int> prices{s, p, m, g, med};

        // Initialize all recruit type sizes to 0
        for(int i = 0; i < 5; i++)
        {
            country->getRecruits()[i]->setGroupSize(0); 
        }

        ListSelectionPrompt prompt = {"Soldier", "Pilot", "Marine", "Guardian", "Medic"};
        std::vector<std::string> types = {"Soldiers", "Pilots", "Marines", "Guardians", "Medics"};
        int totalRecruitsSize = 0;

        std::cout << "Select the type of recruit you wish to have:" << std::endl;
        std::string choice = "y";
        while(choice == "y" || choice == "Y" && country->getEconomy() > 0) // At most 4 allies
        {
            int typeSelected = prompt.getSelectionIndex("Please select an option from 1 to 5: ");
            int size = 0;
            std::cout << "How many " << types[typeSelected] << " do you want? ";
            std::cin >> size;

            int recruitsPrice = size * prices[typeSelected];

            // Check if country has enough money and bought recruits don't exceed the recruit limit
            if(recruitsPrice <= country->getEconomy() && totalRecruitsSize < totalRecruitsLimit)
            {
                totalRecruitsSize += size;
                country->getRecruits()[0]->setGroupSize(size);
                country->setEconomy(country->getEconomy() - recruitsPrice); // setEconomy(currentEconomy - (groupSize * price))

                std::cout << "Do you wish to get More recruits? [y/n] :";
                std::cin >> choice;
            }
            else
            {
                std::cout << "Cannot buy any more recruits!";
            }
        }

        // Citizens
        country->setCitizens(new Citizens());
        country->getCitizens()->setGroupSize(country->getPopulation() - totalRecruitsSize - country->getRefugees()->getGroupSize());
       
        country->setNotEnlisted(country->getPopulation() - totalRecruitsSize); // Not enlisted people will be equal to population - recruits
    }
}

void WarEngine::buyAndDistributeWeapons(bool humanCountry)
{
    for(int i = 0; i < 8; i++)
    {
        ArmoryFacade armoryFacade = countries[i]->getArmoryFacade();


        
        if(humanCountry && i == 0)
        {
            bool desireToPurchaseMore = true;
            while(desireToPurchaseMore){
                ListSelectionPrompt selectRecruitsGroup = {"Group 1", "Group 2", "Group 3", "Group 4"};
                auto userResponse= selectRecruitsGroup.getSelectionIndex("Please select a recruit group to buy weapons for (a/b/c/d): ");

                ListSelectionPrompt selectWeapon = {"Nuclear Weapon", "Explosive Weapon", "Melee Weapon", "Ranged Weapon"};
                auto choice =  selectWeapon.getSelectionIndex("What kind of weapon do you wish to produce?\n") ;// Refactored from WeaponTransport


                armoryFacade.purchaseWeapon(countries[i]->getRecruits()[userResponse], choice);

                ListSelectionPrompt desire = {"yes", "no"};
                int desireChoice = desire.getSelectionIndex("Do you wish to purchase more weapons?");
                if (desireChoice == 1)
                    desireToPurchaseMore = false;
            }
            
        } else {
            for(auto recruit : countries[i]->getRecruits())
            {
                armoryFacade.purchaseWeapon(recruit, randomNumGenerator(0,3));
            }
        }

    }


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
            switch(random){
                case 0:
                    countries[x]->addWarFront(new Land());
                    break;
                case 1:
                    countries[x]->addWarFront(new Sea());
                case 2:
                    countries[x]->addWarFront(new Air());
                case 3:
                    countries[x]->addWarFront(new Space());
            }
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
            increaseAllies(c);
            break;
        case 2:
            sendRecruitAndAttack(c);
            break;
        case 3:
            sendRecruit(c);
            break;
        case 4:
            buyWeaponsAndAllocateToRecruits(c);
            break;
        case 5:
            buyAndSetTraps(c);
            break;
        case 6:
            surrender(c);
            break;
        default:
            break;
    }
}

void WarEngine::buyWeaponsAndAllocateToRecruits(Country* c)
{

}

void WarEngine::increaseAllies(Country* c)
{
    std::vector<Country*> eligible(8);
    for (auto country : countries)
        eligible.push_back(country);

    for (auto pair : allyRegistry.getRecords(c))
    {
        auto other = pair.getOther(c);
        auto it = std::find(std::begin(eligible), std::end(eligible), other);
        if (it != std::end(eligible))
        {
            eligible.erase(it);
        }
    }

    for (auto pair : battleRegistry.getRecords(c))
    {
        auto other = pair.getOther(c);
        auto it = std::find(std::begin(eligible), std::end(eligible), other);
        if (it != std::end(eligible))
        {
            eligible.erase(it);
        }
    }

    for (auto country : eligible)
    {
        float powerRatio = (float)c->getPower() / (float)country->getPower();
        auto it = std::find(std::begin(eligible), std::end(eligible), country);
        if (powerRatio < 1.5f)
            eligible.erase(it);
    }

    int maxNewAllies = 3 - (int)c->getEconomicClass();
    for (int i = maxNewAllies; i > 0; i++)
    {
        ListSelectionPrompt prompt;
        for (auto & country : eligible)
            prompt.append(country->getName());

        prompt.append("Done");

        int idx = prompt.getSelectionIndex("Please select a country to add as an ally: ");
        if (idx == prompt.options.size() - 1)
            break;

        allyRegistry.addRecord(c, eligible[idx]);
        for (auto it = eligible.begin(); it != eligible.end(); it++)
        {
            if (*it == eligible[idx])
            {
                eligible.erase(it);
                break;
            }
        }
    }
}

void WarEngine::sendRecruitAndAttack(Country* c)
{
    
}

void WarEngine::sendRecruit(Country* c)
{
    int cost = 50; //we could change this later on.
}

void WarEngine::buyAndSetTraps(Country* c)
{
    
}

void WarEngine::surrender(Country* c)
{
    ListSelectionPrompt prompt;
    std::vector<UnorderedPair<Country*>> records = battleRegistry.getRecords(c);
    std::vector<Country*> enemies;
    for(auto r : records){
        enemies.emplace_back(r.getOther(c));
        prompt.append(r.getOther(c)->getName());
    }
    int index = prompt.getSelectionIndex("Which country do you wish to surrender to?");
    conquers(enemies[index],c);
}

void WarEngine::conquers(Country* conqueror,Country* conquered){
    conqueror->setEconomy(conqueror->getEconomy()+conquered->getEconomy());
    conquered->setEconomy(0);
    conqueror->setPower(conqueror->getPower()+conquered->getPower());
    conquered->setPower(0);
    conqueror->setPopulation(conqueror->getPopulation()+conquered->getPopulation());
    conquered->setPopulation(0);
    conqueror->getRecruits().insert(conqueror->getRecruits().end(), conquered->getRecruits().begin(), conquered->getRecruits().end());
    for(auto r : conquered->getRecruits()){
        r->setCountry(conqueror);
    }
    conquered->getRecruits().clear();
    int populationSize;
    conqueror->getCitizens()->setGroupSize(conqueror->getCitizens()->getGroupSize() + conquered->getCitizens()->getGroupSize());
    conquered->getCitizens()->setGroupSize(0);
    conqueror->getRefugees()->setGroupSize(conqueror->getRefugees()->getGroupSize() + conquered->getRefugees()->getGroupSize());
    conquered->getRefugees()->setGroupSize(0);
    // WarTheatre** warTheatres;
}

void WarEngine::printWarReport()
{
    for(auto r : warLog){
        std::cout<<r<<std::endl;
    }
}


WarEngine::WarEngine()
{
    
}

int WarEngine::randomNumGenerator(int min, int max)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(min, max);
  return dist(gen);
}

// std::vector<std::string> WarEngine::warLog()
// {
//     // TODO: Implement WarEngine::warLog()
//     return {};
// }
