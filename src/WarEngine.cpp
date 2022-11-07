#include <WarEngine.h>
#include <util/ListSelectionPrompt.h>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <util/enums.h>
#include <bits/stdc++.h>
#include <util/colours.h>

void WarEngine::setHuman(bool human){
    this->human = human;
}
void WarEngine::run(bool human)
{
    this->human = human;
    prePhase1();
    phase1();
    phase2();
    phase3();
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



void WarEngine::prePhase1()
{
    selectCountry();
    initCountryAttributes();
    selectPoliticalRegime();
}
void WarEngine::initCountryAttributes(){
    for(auto c : countries){
        c->setEconomy(5000);
    }
}
void WarEngine::phase1()
{
    std::string reasonsForWar[] = {"Land", "Vengence", "Veganism", "Nationalism"};
    int index;
    int ans;
    int warInit = human ? humanIndex : randomNumGenerator(0,4); //the country starting the war. 
    std::cout<<colours::CYAN<<countries[warInit]->getName()<<colours::RESET<<" is feeling restless and wishes to "<<colours::RED<<"declare war "<<colours::RESET<<"on a country"<<std::endl;
    if(human){
        
        warInit = humanIndex;
        ListSelectionPrompt cOptions;
        for(auto c : this->countries){
            cOptions.append(c->getName());
        }
        while(index == humanIndex){
            index = cOptions.getSelectionIndex(std::string(countries[humanIndex]->getName())+"! Who do you want to declare war against"+"!?");
            if(index == humanIndex){
                std::cout<<"You can't declare war on yourself!"<<std::endl;
            }
        }
        

        ListSelectionPrompt dispute = {"Land", "Vengence", "Veganism", "Nationalism"};
        ans = dispute.getSelectionIndex(std::string("Why do you want to declare war on ")+countries[index]->getName() + "!?");
    }
    else{// only AI
        index = randomNumGenerator(0,7);
        ans = randomNumGenerator(0,3);
        mainAiIndex = warInit;
        // warInit = randomNumGenerator(0,4);
    }
    std::cout<<colours::CYAN<<countries[warInit]->getName()<<colours::RESET<<" has declared war on "<<colours::RED<<countries[index]->getName()<<colours::RESET<< " over "<<reasonsForWar[ans]<<"!"<<std::endl;
    battleRegistry.addRecord(countries[warInit],countries[index]);
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




void WarEngine::phase2()
{
    setAllies();
    partitionRecruits();
    buyAndDistributeWeapons();
    setWarTheatres();
    destributeRecruiteToWarTheatres();
    // setTraps();
}

void WarEngine::phase3()
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

void WarEngine::selectCountry()
{
    std::cout<<colours::BLUE_UNDERLINED<<"COUNTRY SELECTION"<<colours::RESET<<std::endl;
    std::cout<<colours::BLUE<<"Making allies stores it in the Registry which uses a Template Method Pattern"<<colours::RESET<<std::endl;
    std::string countryNames[] = {"South Africa", "United States", "Germany", "Russia", "China", "Asgard", "Westeros", "Australia"};
    

    ListSelectionPrompt countryIndex = {"South Africa", "United States", "Germany", "Russia", "China", "Asgard", "Westeros", "Australia"};
    
    if(human) // If human present
    {        
        std::cout<<"__________________________________________________________________"<<std::endl;
        std::cout<<colours::BLUE_UNDERLINED<<"COUNTRIES"<<colours::RESET<<std::endl;
        std::cout<<colours::BLUE<<"Countries makes use of the Prototype Pattern"<<colours::RESET<<std::endl;
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

    Iterator* it = createCountryIterator(countries);

    while(it->hasNext())
    {
        std::string name = it->current()->getName();
        std::cout<<name<<std::endl;
        it->next();
    }
    std::cout<<"_______________________________________________________________________"<<std::endl;
}

void WarEngine::destributeRecruiteToWarTheatres(){

}
void WarEngine::selectPoliticalRegime()
{
    std::cout<<colours::BLUE_UNDERLINED<<"REGIMES"<<colours::RESET<<std::endl;
    for(auto c : countries){
        if(c != countries[humanIndex] && c != nullptr){
            int choice = randomNumGenerator(0,1);
            if(choice == 0){
                std::cout<<c->getName()<<" is a "<<colours::GREEN<< "capitalist country!"<<colours::RESET<<std::endl;
                c->setPoliticalRegime(enums::Capitalism);
            }       
            else {
                std::cout<<c->getName()<<" is a "<<colours::RED<< "socialist country!"<<colours::RESET<<std::endl;
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
    std::cout<<"_______________________________________________________________________"<<std::endl;
}

void WarEngine::setAllies()
{
    std::cout<<"_______________________________________________________________________"<<std::endl;
    std::cout<<colours::BLUE_UNDERLINED<<"ALLIES"<<colours::RESET<<std::endl;
    std::cout<<colours::BLUE<<"Making allies stores it in the Registry which uses a Template Method Pattern"<<colours::RESET<<std::endl;

    ListSelectionPrompt countryIndex = {"South Africa", "United States", "Germany", "Russia", "China", "Asgard", "Westeros", "Australia"};
    Country *enemy;
    if(human)
    {
        // Make allies?
        std::string choice;
        std::cout << "Would you like to make allies? [y/n] :";
        std::cin >> choice;
        int userAllyCount = 0;
        int enemyAllyCount = 0;
        int enemyAllyLimit = randomNumGenerator(1, 6 - userAllyCount); // Use 6 to exclude ourCountry and enemyCountry
        std::cout<<colours::BLUE_UNDERLINED<<"COUNTRIES:"<<colours::RESET<<std::endl;
        //find enemy
        std::vector<UnorderedPair<Country*>> userBattles = this->battleRegistry.getRecords(countries[humanIndex]);
        enemy = userBattles[0].getOther(countries[humanIndex]); // Only one item in battleRegistry so use index 0
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
                    if(allyIndex == enemyIndex)
                    {
                        std::cout <<countries[allyIndex]->getName()<< " is an enemy country!" << std::endl;
                        flag2 = true;
                    }
                    else
                    {
                        for(auto enemyAlly : enemyAllies){ //does enemyAllyies have the country?
                            if(enemyAlly.has(countries[allyIndex])){
                                std::cout <<countries[allyIndex]->getName()<< " is an enemy country!" << std::endl;
                                flag2 = true;
                            }
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
                std::cout<<colours::CYAN<<countries[humanIndex]->getName()<<colours::RESET<<" has allied itself with "<<countries[allyIndex]->getName()<<std::endl;
                this->allyRegistry.addRecord(countries[humanIndex],countries[allyIndex]);
                userAllyCount++;
                int economy = countries[humanIndex]->getEconomy(); // our country's economy
                countries[humanIndex]->setEconomy(economy - (economy * 0.15)); // Cost is 15% of economy
            }
            else
            {
                break;
            }   
            auto userAllies = this->allyRegistry.getRecords(countries[humanIndex]);
            auto enemyAllies = this->allyRegistry.getRecords(enemy);
            // Initially battleRegistry = {(ourCountry, enemyCountry)} or {(enemyCountry,ourCountry)}

            //allow ai to select country
            if(enemyAllyCount <= enemyAllyLimit)
            {// a better way to do this is just to create a list selection prompt of all the applicable countries choices and randomise that
               while(true)
                {
                    int randomIndex = randomNumGenerator(0, 7); // randomize ally country index
                    bool flag1 = false;
                    bool flag2 = false;
                    bool flag3 = false;
                    if(randomIndex == enemyIndex){
                        flag3 = true;
                    }
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
                    if(!(flag1 || flag2 || flag3)) // If not an ally of ourCountry we can make it an ally of the enemy && if not the enemy country itself(or it's allies)
                    {
                        this->allyRegistry.addRecord(enemy,countries[randomIndex]);
                        std::cout<<colours::RED<<enemy->getName()<<colours::RESET<<" has allied itself with "<<countries[randomIndex]->getName()<<std::endl;
                        int economy = countries[randomIndex]->getEconomy(); // our country's economy
                        countries[randomIndex]->setEconomy(economy - (economy * 0.15)); // Cost is 15% of economy
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
        auto userAllies = this->allyRegistry.getRecords(countries[mainAiIndex]);
        auto enemyAllies = this->allyRegistry.getRecords(enemy);
        
        auto userBattles = this->battleRegistry.getRecords(countries[mainAiIndex]);
        enemy = userBattles[0].getOther(countries[mainAiIndex]); // Only one item in battleRegistry so use index 0
        
        int enemyIndex = 0;
        for(int i = 0; i < 8; i++)
        {
            if(countries[i]->getName() == enemy->getName()) // Find enemy country's index in countries[] attribute
            {
                enemyIndex = i;
                break;
            }      
        }

        //we will be swapping the values these temp variable to simulate turn based vhoosing. 
        int warInit = mainAiIndex; //the one who initialised the war
        int eInd = enemyIndex;
        int count = 0;    
        while(true)
        {
            userAllies = this->allyRegistry.getRecords(countries[warInit]);
            enemyAllies = this->allyRegistry.getRecords(countries[eInd]);
            int randomIndex = randomNumGenerator(0, 7); // randomize ally country index
            bool flag1 = false;
            bool flag2 = false;
            bool flag3 = false;
            if(countries[randomIndex]->getName() == countries[eInd]->getName()){//can't ally with yourself.
                flag3 = true;
            }
            for(auto userAlly : userAllies){ //does userAlly have the country? 
                if(userAlly.has(countries[randomIndex])){
                    flag1 = true;
                    break;
                }
            }
            for(auto enemyAlly : enemyAllies){ //does enemyAllies have the country?
                if(enemyAlly.has(countries[randomIndex])){
                    flag2 = true;
                    break;
                }
            }
            if(!(flag1 || flag2 || flag3)) // If not an ally of ourCountry we can make it an ally of the enemy && if not the enemy country itself(or it's allies)
            {
                this->allyRegistry.addRecord(countries[eInd],countries[randomIndex]);
                std::cout<<countries[eInd]->getName()<<" has allied itself with "<<countries[randomIndex]->getName()<<std::endl;
                int economy = countries[randomIndex]->getEconomy(); // our country's economy
                countries[randomIndex]->setEconomy(economy - (economy * 0.15)); // Cost is 15% of economy
                count++;
                std::swap(warInit,eInd);//let the enemy choose too
                if(count == 6)
                    break;
            }    
        }
        // The AI user
        // int userAllyLimit = randomNumGenerator(1, 4); // Use 6 to exclude ourCountry and enemyCountry
        // int userAllyCount = 0;
        // int randomIndex  = 0;
        // int AIUserIndex = randomNumGenerator(1, 8);
        // while(userAllyCount <= userAllyLimit)
        // {
        //     randomIndex = randomNumGenerator(1, 8); // randomize ally country index
        //     if(AIUserIndex != randomIndex && AIUserIndex != enemyIndex)
        //     {
        //         this->allyRegistry.addRecord(countries[AIUserIndex],countries[randomIndex]);
        //         userAllyCount++;
        //     }
        // }

        // int enemyAllyLimit = randomNumGenerator(1, 6 - userAllyCount); // Use 6 to exclude ourCountry and enemyCountry
        // int enemyAllyCount = 0;
        // while(enemyAllyCount <= enemyAllyLimit)
        // {
        //     randomIndex = randomNumGenerator(1, 8); // randomize ally country index
            
        //     for(auto userAlly : userAllies)
        //     {
        //         if(!userAlly.has(countries[humanIndex]) && enemyIndex != randomIndex) // If not an ally of ourCountry we can make it an all of the enemy
        //         {
        //             this->allyRegistry.addRecord(countries[enemyIndex],countries[randomIndex]);
        //             enemyAllyCount++;
        //         } // else loop again untill enemyAllyLimit reached
        //     }
        // }
    }  
    //the allies of my enemy are my enemies  
    int warInit = human ? humanIndex : mainAiIndex; //who initialised the war?
    for(auto r :  this->allyRegistry.getRecords(enemy))
    {
        this->battleRegistry.addRecord(countries[warInit],r.getOther(enemy));
    }
    //enemy is the enemy of my allies
    for(auto a : this->allyRegistry.getRecords(countries[warInit]))
    {
        this->battleRegistry.addRecord(enemy,a.getOther(countries[warInit]));
    }
}

void WarEngine::partitionRecruits()
{ 
    std::cout<<"_______________________________________________________________________"<<std::endl;
    std::cout<<colours::BLUE_UNDERLINED<<"SET UP POPULATION"<<colours::RESET<<std::endl;
    std::cout<<colours::BLUE<<"The Population consists of People which forms part of a State Pattern"<<colours::RESET<<std::endl;
    std::cout<<colours::BLUE<<"People can be swapped out by their respective types:"<<colours::RESET<<std::endl;
    std::cout<<colours::BLUE<<"-Recruits\n-Citizens\n-Refugee"<<colours::RESET<<std::endl;

    int index = 0;

    for(Country* country : countries) // Partition population for each country
    {
        if(index == humanIndex && mainAiIndex == -1)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1e4, 5e4);

            // Set total population for passed country
            country->setPopulation(dist(gen));
            country->setCitizens(new Citizens());
            country->getCitizens()->setGroupSize(0); // Initialize to 0 before recruits are purchased

            // Refugees
            country->setRefugees(new Refugee());
            country->getRefugees()->setGroupSize(country->getPopulation() * 0.1); // Initially 10% refugees at start

            // Recruits
            country->setRecruits(std::vector<Recruits*> {new Soldier(), new Pilot(), new Marine(), new Guardian(), new Medic()});

            // Initialize all recruit type sizes to 0
            for(int i = 0; i < 5; i++)
            {
                country->getRecruits()[i]->setGroupSize(0); 
            }

            int totalRecruitsLimit = country->getPopulation() - country->getRefugees()->getGroupSize();
            const int s = 100, m=150, p = 200, g=300, med=150; //prices of each recruit type
            std::vector<int> prices{s, p, m, g, med};

            ListSelectionPrompt prompt = {"Soldier", "Pilot", "Marine", "Guardian", "Medic"};
            std::vector<std::string> types = {"Soldiers", "Pilots", "Marines", "Guardians", "Medics"};
            int totalRecruitsSize = 0;

            std::string choice = "y";
            while(choice == "y" || choice == "Y" && country->getEconomy() > 0) // At most 4 allies
            {
                // --- Summary Output ---
                std::cout<<"======================\n"
                <<colours::WHITE_BOLD<<country->getName()<<colours::RESET<<" Summary"
                <<colours::YELLOW<<"\nEconomy: "<<colours::RESET<<std::to_string(country->getEconomy())
                <<colours::CYAN<<"\nTotal Population: "<<colours::RESET<<std::to_string(country->getPopulation())
                <<colours::BLUE<<"\nRecruits: "<<colours::RESET<<std::to_string(totalRecruitsSize)
                <<"\n- Soldiers: "<<colours::RESET<<std::to_string(country->getRecruits()[0]->getGroupSize())
                <<"\n- Pilots: "<<colours::RESET<<std::to_string(country->getRecruits()[1]->getGroupSize())
                <<"\n- Marines: "<<colours::RESET<<std::to_string(country->getRecruits()[2]->getGroupSize())
                <<"\n- Guardians: "<<colours::RESET<<std::to_string(country->getRecruits()[3]->getGroupSize())
                <<"\n- Medics: "<<colours::RESET<<std::to_string(country->getRecruits()[4]->getGroupSize())
                <<colours::GREEN<<"\nCitizens: "<<colours::RESET<<std::to_string(country->getCitizens()->getGroupSize())
                <<colours::PURPLE<<"\nRefugees: "<<colours::RESET<<std::to_string(country->getRefugees()->getGroupSize())<<std::endl;
                std::string summary ="Select the type of recruit you wish to have:";
                std::cout << summary << std::endl;
                // --- Summary Output ---

                int typeSelected = prompt.getSelectionIndex("Please select an option from 1 to 5: ");
                int size = 0;
                std::cout << "How many " << types[typeSelected] << " do you want? ";
                std::cin >> size;

                std::string confirm = "y";
                int recruitsPrice = size * prices[typeSelected];
                std::cout << "Purchase " << size << " " << types[typeSelected] << " with a price of " << recruitsPrice <<" ?[y/n]";
                std::cin >> confirm;
                if(confirm == "y" || confirm == "Y") 
                {
                // Check if country has enough money and bought recruits don't exceed the recruit limit
                    if(recruitsPrice <= country->getEconomy() && totalRecruitsSize < totalRecruitsLimit)
                    {
                        totalRecruitsSize += size;
                        country->getRecruits()[typeSelected]->setGroupSize(size);
                        country->setEconomy(country->getEconomy() - recruitsPrice); // setEconomy(currentEconomy - (groupSize * price))

                        std::cout << "Do you wish to get More recruits? [y/n] :";
                        std::cin >> choice;
                    }
                    else
                    {
                        std::cout << "Cannot buy any more recruits!";
                        break;
                    }     
                }
                // Citizens 
                country->getCitizens()->setGroupSize(country->getPopulation() - totalRecruitsSize - country->getRefugees()->getGroupSize());
            }
            country->setNotEnlisted(country->getPopulation() - totalRecruitsSize); // Not enlisted people will be equal to population - recruits
        }
        else
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1e4, 5e4);

            // Set total population for passed country
            country->setPopulation(dist(gen));
            country->setCitizens(new Citizens());
            country->getCitizens()->setGroupSize(0); // Initialize to 0 before recruits are purchased

            // Refugees
            country->setRefugees(new Refugee());
            country->getRefugees()->setGroupSize(country->getPopulation() * 0.1); // Initially 10% refugees at start
            
            // Recruits
            country->setRecruits(std::vector<Recruits*> {new Soldier(), new Pilot(), new Marine(), new Guardian(), new Medic()});
            int totalRecruitsSize = 0;
            int size = 0;
            int totalRecruitsLimit = country->getPopulation() - country->getRefugees()->getGroupSize();

            const int s = 100, m=150, p = 200, g=300, med=150; //prices of each recruit type
            std::vector<int> prices{s, p, m, g, med};

            for(int i = 0; i < 5; i++)
            {
                size = randomNumGenerator(1,5);
                int recruitsPrice = size * prices[i];
                if(recruitsPrice <= country->getEconomy()*0.8 && totalRecruitsSize < totalRecruitsLimit) // Economy shouldn't get to 0, recruitsPrice <= country->getEconomy()*0.8 to ensure recruitsPrice isn't exactly equal to economy
                {
                    totalRecruitsSize += size;
                    country->getRecruits()[i]->setGroupSize(size);
                    country->setEconomy(country->getEconomy() - recruitsPrice); // setEconomy(currentEconomy - (groupSize * price))
                }
            }
            // Citizens
            country->getCitizens()->setGroupSize(country->getPopulation() - totalRecruitsSize - country->getRefugees()->getGroupSize());
            country->setNotEnlisted(country->getPopulation() - totalRecruitsSize); // Not enlisted people will be equal to population - recruits

            // --- Summary Output ---
            std::cout<<"======================\n"
            <<colours::WHITE_BOLD<<country->getName()<<colours::RESET<<" Summary"
            <<colours::YELLOW<<"\nEconomy: "<<colours::RESET<<std::to_string(country->getEconomy())
            <<colours::CYAN<<"\nTotal Population: "<<colours::RESET<<std::to_string(country->getPopulation())
            <<colours::BLUE<<"\nRecruits: "<<colours::RESET<<std::to_string(totalRecruitsSize)
            <<"\n- Soldiers: "<<colours::RESET<<std::to_string(country->getRecruits()[0]->getGroupSize())
            <<"\n- Pilots: "<<colours::RESET<<std::to_string(country->getRecruits()[1]->getGroupSize())
            <<"\n- Marines: "<<colours::RESET<<std::to_string(country->getRecruits()[2]->getGroupSize())
            <<"\n- Guardians: "<<colours::RESET<<std::to_string(country->getRecruits()[3]->getGroupSize())
            <<"\n- Medics: "<<colours::RESET<<std::to_string(country->getRecruits()[4]->getGroupSize())
            <<colours::GREEN<<"\nCitizens: "<<colours::RESET<<std::to_string(country->getCitizens()->getGroupSize())
            <<colours::PURPLE<<"\nRefugees: "<<colours::RESET<<std::to_string(country->getRefugees()->getGroupSize())<<std::endl;
            // --- Summary Output ---
        }
    index++;  
    }
}

void WarEngine::buyAndDistributeWeapons()
{
    for(int i = 0; i < 8; i++)
    {
        ArmoryFacade armoryFacade = countries[i]->getArmoryFacade();


        
        if(human && i == 0)
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
    ListSelectionPrompt prompt1;
    for(auto r : c->getRecruits()){
        prompt1.append(r->getName());
    }
    int out1 = prompt1.getSelectionIndex("Which recruits do you wish to send out?");
    ListSelectionPrompt prompt2;
    for(auto w : c->getWarTheatres()){
        prompt2.append(w->getLocation());
    }
    int out2 = prompt2.getSelectionIndex("Which war theatre do you wish to send your recruits?");
    ((BattleGround*)c->getWarTheatres()[out2])->geRecruitContext()->setState(c->getRecruits()[out1]);
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

Iterator* WarEngine::createCountryIterator(Country** countryList)
{

    return new CountryIterator(countryList);
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
