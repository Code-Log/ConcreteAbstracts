
#include <WarPadel.h>
#include <random>
#include <util/ListSelectionPrompt.h>
#include <sstream>

std::string countryData(Country *);
std::string toString(int);
int randomNumGenerator(int, int);
void WarPadel::startPedaling()
{
    Phase1();
    Phase2();
    Phase3();
}

void WarPadel::Phase1()
{
    std::cout << "--PHASE 1--" << std::endl;
    // make countries
    countries = new Country *[8];
    for (int x = 0; x < 8; x++)
    {
        countries[x] = nullptr;
    }

    UserCountryInput();

    for (int x = 1; x < 8; x++)
    {
        countries[x] = new Country(nameGenerator());
    }

    std::cout << "Country Data: " << std::endl;
    std::cout << outPutCountries() << std::endl;

    std::cout << "Power Levels Before War:" << std::endl;
    std::cout << countryRanks() << std::endl;

    std::cout << "************Saving country state with MEMENTO PATTERN. Deep copies with PROTOTYPE********************" << std::endl;
    std::cout << "Continue..." << std::endl;
    std::string a;
    std::cin >> a;

    for (int x = 0; x < 8; x++)
    {
        historyBook->addCommit(countries[x]->createMemento(countries[x]));
    }

    std::cout << "****************************************************************************************" << std::endl;

    Dispute();

    update();
}

void WarPadel::Phase2()
{
    std::cout << "--PHASE 2--" << std::endl;
    std::cout << std::endl;

    WarPrep(1,4);
    bool cont = true;
    while (cont)
    {
        cont = makeDecisionPhase2();
    }

    update();

    std::cout << "!!!!!!!!*The ammo has been bought, bunkers been built. The time for talk is over and the bloody part of war has begun. Let's make history and fight for our buds. TASTEbuds, that is*!!!!" << std::endl
              << std::endl;
}

void WarPadel::Phase3()
{
    fireExchange();
    countryRanks();
    for (int x = 0; x < 8; x++)
    {
        returnRefugees(countries[x]);
    }

    update();
    countryRanks();
    Negotiations();

    WarPrep(0,7);
    fireExchange();
    update();
    countryRanks();

    std::cout << "*****************************************************************************" << std::endl;
    std::cout << "************ REST OF MEMENTO DESIGN PATTERN. Retrieving data from the CARETAKER ********************" << std::endl;
    std::cout << "Continue..." << std::endl;
    std::string a;
    std::cin >> a;
    history();
    std::cout << "Don't forget to ask if uml stays the same if not upgrade diagrams to at least match uml. Also implement winner and GUI, doxygen and format code it's not changed. also video" << std::endl;

}

void WarPadel::history()
{
     ListSelectionPrompt prompt = {
        countries[7]->getName(), countries[6]->getName(), countries[5]->getName(), countries[4]->getName(), countries[3]->getName(), countries[2]->getName(), countries[1]->getName(), countries[0]->getName(), "All"};

    int index = prompt.getSelectionIndex("Which history logs do you need to see? ");

    std::cout << std::endl;

    int counter = 0;
    if(index ==8)
    {
        counter=-1;
    }
    std::cout<<"---------WAR HISTORY--------"<<std::endl;
    Country* tempC = new Country("");
    int war = historyChapters*8;
    while(index>0)
    {
        tempC->reinstateMemento(historyBook->removeCommit());
        war--;
       // delete tempC;
       index--;
    }

    
    while(war >0)
    {
        if(counter==0)
        {
            tempC->reinstateMemento(historyBook->removeCommit());
            std::cout<< countryData(tempC)<<std::endl;
            war--;
            counter = 7;
        }
        else if(counter== -1)
        {
            tempC->reinstateMemento(historyBook->removeCommit());
           std::cout<< countryData(tempC)<<std::endl;
            war--;
            std::cout<<std::endl;
        
        }
        else
        {
            tempC->reinstateMemento(historyBook->removeCommit());
            counter--;
            war--;
        
        }

        
    }

    std::cout<<"----------------------------------"<<std::endl;

}

void WarPadel::Negotiations()
{
    std::cout << "This is no longer a YOU problem. The world is noticing an asking you war mongers questions. Does seafood count as meat? Do vegans ride horses or do the horses ride them?\n They are joining the show. WHo do you pick?" << std::endl
              << std::endl;

    std::string a = countries[4]->getName();
    a += ": 'TOTALLY on your side. In fact our people think we should extend on our livestock demands and add vegans to the menu.' Yeah, we all don't like how... passionate ";
    a += countries[4]->getName();
    a += " has become but they've got the guns. Team up and address their...appetites later.\n";

    std::string b = countries[5]->getName();
    b += ": 'Keep the meat. Why fight when we can set some boundaries like Meatless Mondays. Tofu Tuesdays. Fasting Fridays. Yeah, let's just pretend like we care for the vegans.' Hopefully, they won't PRETEND to be your ally.\n";

    std::string c = countries[6]->getName();
    c += ": 'So, If it tastes like meat but isn't meat, is that okay? Soy milk?...okay. I guess vegan ice-scream isn't that bad. Wait, is honey anti-vegan? Vegetarian?' ";
    c += countries[6]->getName();
    c += " is clearly confused. Shouldn't be hard for your ambassadors to manipulate.\n";

    std::string d = countries[7]->getName();
    d += ": 'Meat livestock causes climate change, Burger King vegan burgers aren't vegan because they were in contact with real patties. You all complain a lot. We'll shoot just to shut them up.' ...as long as they vegans are annoying they could be of use.\n";

    std::cout << std::endl;

    ListSelectionPrompt prompt = {
        a, b, c, d};

    int index = prompt.getSelectionIndex("Who will you pamper to: ");

    std::cout << std::endl;

    switch (index)
    {
    case 0:

        std::cout << "Brave choice. Just spend a bit more on supplies to Make sure your new ally recruits NEVER GET HUNGRY" << std::endl;

        countries[0]->setEconomy(countries[0]->getEconomy() * 0.90);
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << countries[0]->getName() << "'s economy has dropped by 10%. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;

        allyRegistry->addRecord(countries[0], countries[4]);
        battleRegistry->addRecord(countries[1], countries[4]);

        break;
    case 1:

        std::cout << "The new allies gave you a loan!!!! What's that? Fine print? High interest rates, you don't say." << std::endl;

        countries[0]->setEconomy(countries[0]->getEconomy() * 1.40);
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << countries[0]->getName() << "'s economy has risen by 40%. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;

        allyRegistry->addRecord(countries[0], countries[5]);
        battleRegistry->addRecord(countries[1], countries[5]);

        break;
    case 2:

        std::cout << "While the new allies debate whether wool is anti-vegan or not here is their army for you to use" << std::endl;

        countries[0]->setNotEnlisted(countries[0]->getNotEnlisted() * 1.30);
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << countries[0]->getName() << "'s man power has risen by 30%. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;

        allyRegistry->addRecord(countries[0], countries[6]);
        battleRegistry->addRecord(countries[1], countries[6]);

        break;
    case 3:

        std::cout << "Maybe, better an ally than enemy, you thought. Your people, however don't like this alliance." << std::endl;

        countries[0]->setNotEnlisted(countries[0]->getNotEnlisted() * 0.95);
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << countries[0]->getName() << "'s man power has dropped by 5%. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;

        allyRegistry->addRecord(countries[0], countries[7]);
        battleRegistry->addRecord(countries[1], countries[7]);

        break;
    default:
        break;
    }

    std::cout << "A war is amongst the diplomats. The battlefield is just their way of ROCK PAPER SCISSORS. But what fun is treaties and debates. Let luck handle the rest and return to the field." << std::endl;

    index += 4;
    int left = randomNumGenerator(4, 7);

    while (index == left)
    {
        left = randomNumGenerator(4, 7);
    }

    for (int x = 4; x < 8; x++)
    {
        if (x == index || x == left)
        {
            if (x != index)
            {

                allyRegistry->addRecord(countries[0], countries[x]);

                battleRegistry->addRecord(countries[1], countries[x]);
            }
        }
        else
        {

            allyRegistry->addRecord(countries[1], countries[x]);

            battleRegistry->addRecord(countries[0], countries[x]);
        }
    }

    unsavedUpdate();

    teams();
}

void WarPadel::fireExchange()
{
    auto allyTeam = allyRegistry->getRecords(countries[0]);
    auto enemyTeam = allyRegistry->getRecords(countries[1]);

    attack(countries[0], countries[1]);
    std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
    attack(countries[1], countries[0]);
    std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
    for (int x = 0; x < allyTeam.size(); x++)
    {
        for (int i = 0; i < enemyTeam.size(); i++)
        {

            attack(allyTeam[x].getOther(countries[0]), enemyTeam[i].getOther(countries[1]));
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
            attack(enemyTeam[i].getOther(countries[1]), allyTeam[x].getOther(countries[0]));
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
        }
    }
}

void WarPadel::attack(Country *attacker, Country *defender)
{

    if (CountryHasFallen(attacker) || CountryHasFallen(defender))
    {
        return;
    }
    std::cout << attacker->getName() << " has invaded " << defender->getName() << std::endl;
    std::string types[] = {"Soldier", "Marine", "Pilot", "Gaurdian"};
    std::string typesL[] = {"Land", "Sea", "Air", "Space"};
    std::string typesV[] = {"Tank", "Ship", "Jet", "Spacecraft"};
    Recruits *invaders;
    Recruits *deflectors;
    bool defended;

    for (int i = 0; i < 4; i++)
    {
        invaders = attacker->searchAndRetrieve(types[i]);
        if (invaders != nullptr)
        {
            std::cout << "=========" << attacker->getName() << " deploying their " << types[i] << "s!========" << std::endl;
            if (defender->getWarFront(typesL[i]) != nullptr)
            {
                std::cout << defender->getName() << " has defended its territoy!!!!" << std::endl;
                defender->getWarFront(typesL[i])->penalty(invaders);
                setOffTraps(invaders, defender->getIndexWarFront(i), typesV[i]);
                deflectors = defender->searchAndRetrieve(types[i]);
                if (deflectors != nullptr)
                {
                    defender->getWarFront(typesL[i])->penalty(deflectors);
                    combat(invaders, deflectors);
                }
                else
                {
                    if (invaders->getGroupSize() > 0)
                    {
                        battleWon(attacker, defender);
                    }
                }
            }
            else
            {
                std::cout << defender->getName() << " has NOT defended its territoy!!!!" << std::endl;
                battleWon(attacker, defender);
            }
        }
    }
}

void WarPadel::combat(Recruits *attacker, Recruits *defender)
{
    std::cout << "********" << attacker->getCountry()->getName() << "'s and " << defender->getCountry()->getName() << "'s men have clashed on the battle field******" << std::endl
              << std::endl;
    while (attacker->getGroupSize() > 0 && defender->getGroupSize() > 0)
    {
        if (attacker->amoryEmpty())
        {
            defender->setGroupSize(defender->getGroupSize() - 1);
        }
        else
        {
            attacker->fireWeapon(defender);
        }

        if (defender->amoryEmpty())
        {
            attacker->setGroupSize(attacker->getGroupSize() - 1);
        }
        else
        {
            defender->fireWeapon(attacker);
        }
    }

    if (attacker->getGroupSize() < defender->getGroupSize())
    {
        battleWon(attacker->getCountry(), defender->getCountry());
    }
    else
    {
        battleWon(defender->getCountry(), attacker->getCountry());
    }
}

void WarPadel::setOffTraps(Recruits *invaders, WarTheatre *battleField, std::string &vessel)
{

    int traps = battleField->damageTotal();
    int sheilds = invaders->getDefense(vessel);
    traps -= sheilds;

    if (traps > invaders->getGroupSize())
    {
        invaders->setGroupSize(0);
    }
    else
    {
        invaders->setGroupSize(invaders->getGroupSize() - traps);
    }

    std::cout << "XXXXXXXXX " << traps << " of " << invaders->getCountry()->getName() << "'s men were killed by traps XXXXXXXX" << std::endl
              << std::endl;
}

void WarPadel::battleWon(Country *winner, Country *loser)
{
    unsavedUpdate();

    std::cout << "!!!!!" << winner->getName() << " won this battle with " << loser->getName() << " !!!!!" << std::endl
              << std::endl;
    int luck = randomNumGenerator(1, 15);
    int populationLoss = 10000 / luck;

    Recruits *medics = loser->searchAndRetrieve("Medic");

    while (medics != nullptr && populationLoss > 0)
    {
        if (medics->getGroupSize() < populationLoss)
        {
            populationLoss -= medics->getGroupSize();
            medics->setGroupSize(0);
            medics = loser->searchAndRetrieve("Medic");
        }
        else
        {
            populationLoss = 0;
        }
    }

    if (transportRefugees(loser, populationLoss * 0.25))
    {
        populationLoss = populationLoss * 0.75;
        loser->setCitizens(loser->getCitizens() - populationLoss);
        std::cout << "======" << loser->getName() << " suffered " << populationLoss << " casualties=====" << std::endl
                  << std::endl;
    }

    unsavedUpdate();
}

bool WarPadel::transportRefugees(Country *country, int amount)
{

    auto allies = allyRegistry->getRecords(country);
    if (allies.size() > 0)
    {
        Country *helper = allies[0].getOther(country);
        if (CountryHasFallen(helper) == false)
        {
            std::cout << ">>>>" << country->getName() << " sending " << amount << " refugees to " << helper->getName() << "<<<<<" << std::endl
                      << std::endl;
            helper->addRefugee(country, amount);
            return true;
        }
    }

    return false;
}

void WarPadel::returnRefugees(Country *country)
{
    auto refugees = country->getRefugees();
    for (int x = 0; x < refugees.size(); x++)
    {
        if (refugees[x]->getGroupSize() > 0)
        {
            Country *friendly = refugees[x]->getCountry();
            friendly->setCitizens(friendly->getCitizens() + refugees[x]->getGroupSize());
            refugees[x]->setGroupSize(0);
            std::cout << " -------- Refugees returned back to " << friendly->getName() << "-------" << std::endl;
        }
    }

    unsavedUpdate();
}

bool WarPadel::CountryHasFallen(Country *country)
{
    if (country->getPopulation() < 0 || country->getEconomy()<0)
    {
       
        return true;
    }

    return false;
}
void WarPadel::WarPrep(int start, int end)
{
    std::cout << "Preparations for war..." << std::endl;
    for (int x = start; x < end; x++)
    {
        if(!(CountryHasFallen(countries[x])))
            setWarTheatres(countries[x]);
    }

    std::cout << "************Setting traps using DECORATOR DESIGN PATTERN********************" << std::endl;
    std::cout << "Continue..." << std::endl;
    std::string a;
    std::cin >> a;
    for (int x = start; x < end; x++)
    {
        if(!(CountryHasFallen(countries[x])))
            setTraps(countries[x]);
    }
    std::cout << "*****************************************************************************" << std::endl;
    std::cout << "************ Getting recruits. Use of STATE DESIGN PATTERN: soldier, marine, pilot, guardian, medic********************" << std::endl;
    std::cout << "Continue..." << std::endl;
    std::cin >> a;

    for (int x = start; x < end; x++)
    {
        if(!(CountryHasFallen(countries[x])))
            setMilitary(countries[x]);
    }

    std::cout << "*****************************************************************************" << std::endl;

    std::cout << "************FACADE DESIGN PATTERN COMBO - weapons from ABSTRACT FACTORY transported using STRATEGY PATTERN transport. Distributed to STATE PATTERN recruits by FACADE********************" << std::endl;
    std::cout << "Continue..." << std::endl;
    std::cin >> a;

    for (int x = start; x < end; x++)
    {
        if(!(CountryHasFallen(countries[x])))
            purchaseWeapons(countries[x]);
    }

    std::cout << "*****************************************************************************" << std::endl;
}
void WarPadel::Dispute()
{
    std::cout << "If two vegans argue is it still called beef? Meat is good. Meat is tasty. But not everyone thinks so and " << countries[0]->getName() << " is willing to go cannibal to keep " << countries[1]->getName() << " from their rare steaks. Steak knives vs chopsticks. It's WAR!!!!!!!!!!" << std::endl
              << std::endl;

    std::cout << "************************From now will be utilising the TEMPLATE DESIGN PATTERN to bond either enemies or friends********************" << std::endl;
    std::cout << "Continue..." << std::endl;
    std::string a;
    std::cin >> a;

    allyRegistry = new AllyRegistry();
    battleRegistry = new BattleRegistry();
    battleRegistry->addRecord(countries[0], countries[1]);
    std::cout << std::endl;

    std::cout << countries[2]->getName() << " can smell the beef between you two. They are more of a tofu people but can't live without milk and cookies." << std::endl;

    ListSelectionPrompt dispute1 = {"yes", "no"};
    std::string prompt = "Do you want to join forces with ";
    prompt += countries[2]->getName();
    prompt += " and roast some ass? It will cost you some cash. They don't come cheap.";
    auto ans = dispute1.getSelection(prompt);

    std::cout << std::endl;
    if (ans == "yes")
    {
        countries[0]->setEconomy(countries[0]->getEconomy() * 0.80);
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << countries[0]->getName() << "'s economy has dropped by 20%. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;
        allyRegistry->addRecord(countries[0], countries[2]);
        battleRegistry->addRecord(countries[1], countries[2]);
    }
    else
    {
        std::cout << "Rejection is hard to digest. You've made an enemy" << std::endl;
        battleRegistry->addRecord(countries[0], countries[2]);
        allyRegistry->addRecord(countries[1], countries[2]);
    }
    std::cout << std::endl;

    std::cout << countries[3]->getName() << " overheard you sharpening your butcher knives. They need some  help with their issues. It will only cost a few million people. If you agree they promise to help with your war on vegetables" << std::endl;

    ListSelectionPrompt dispute2 = {"yes", "no"};
    prompt = "Do you want to take a risk and help ";
    prompt += countries[3]->getName();
    prompt += ". Keep in mind something called karma.";
    auto ans2 = dispute1.getSelection(prompt);

    std::cout << std::endl;
    if (ans2 == "yes")
    {
        countries[0]->setNotEnlisted(countries[0]->getNotEnlisted() * 0.85);
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << countries[0]->getName() << "'s man power has dropped by 15%.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;
        allyRegistry->addRecord(countries[0], countries[3]);
        battleRegistry->addRecord(countries[1], countries[3]);
    }
    else
    {
        std::cout << "Looks like the vegans could help " << countries[3]->getName() << ". Ah oh!" << std::endl;
        allyRegistry->addRecord(countries[1], countries[3]);
        std::cout << "So obviously the enemy of my friend is my enemy" << std::endl;
        battleRegistry->addRecord(countries[0], countries[3]);
    }

    teams();
}

void WarPadel::teams()
{
    std::vector<UnorderedPair<Country *>> teamA = allyRegistry->getRecords(countries[0]);
    std::vector<UnorderedPair<Country *>> teamB = allyRegistry->getRecords(countries[1]);
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    std::cout << "Team A" << std::endl;
    std::cout << countries[0]->getName() << std::endl;
    for (int x = 0; x < teamA.size(); x++)
    {
        if (CountryHasFallen(teamA[x].getOther(countries[0])))
        {
             std::cout << "<<<<<<<<<<< " << teamA[x].getOther(countries[0])->getName() << " has fallen >>>>>>>>>>>" << std::endl;
        }
        else
        {
            std::cout << teamA[x].getOther(countries[0])->getName() << std::endl;
        }
            
    }

    std::cout << "VS" << std::endl;
    std::cout << "Team B" << std::endl;
    std::cout << countries[1]->getName() << std::endl;
    for (int x = 0; x < teamB.size(); x++)
    {
        if (CountryHasFallen(teamB[x].getOther(countries[1])))
        {
             std::cout << "<<<<<<<<<<< " << teamB[x].getOther(countries[1])->getName() << " has fallen >>>>>>>>>>>" << std::endl;
        }
        else
        {
            std::cout << teamB[x].getOther(countries[1])->getName() << std::endl;
        }
    }
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
}

bool WarPadel::Randomise()
{

    setWarTheatres(countries[0]);
    setTraps(countries[0]);
    setMilitary(countries[0]);
    purchaseWeapons(countries[0]);

    return false;
}

void WarPadel::UserCountryInput()
{
    std::cout << "Name for your country: ";
    std::string name;
    std::cin >> name;

    Country *userCountry = new Country(name);
    std::cout << "Is your country capatalist or socialist (c/s): ";
    std::string ans;
    std::cin >> ans;

    if (ans == "c")
    {
        int economy = userCountry->getEconomy();
        economy = economy * 1.2;
        userCountry->setEconomy(economy);

        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << userCountry->getName() << "'s economy has risen by 20%. !!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;
    }
    else
    {
        int people = userCountry->getNotEnlisted();
        people = people * 1.2;
        userCountry->setNotEnlisted(people);

        std::cout << "!!!!!!!!!!!!!!!!!!!!!!" << userCountry->getName() << "'s man power has risen by 20%. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
                  << std::endl;
    }

    countries[0] = userCountry;
}

void WarPadel::unsavedUpdate()
{
    for (int x = 0; x < 8; x++)
    {
        countries[x]->updatePopulationSize();
        countries[x]->updatePower();
    }
}

void WarPadel::update()
{
    historyChapters++;
    std::cout << "****** UPDATING COUNTRY DATA. Use of ITERATOR DESIGN PATTERN to traverse through recruits*******" << std::endl;
    std::cout << "Continue..." << std::endl;
    std::string a;
    std::cin >> a;
    for (int x = 0; x < 8; x++)
    {
        countries[x]->updatePopulationSize();
        countries[x]->updatePower();
    }

    std::cout << "************************************************************************************************" << std::endl;

    std::cout << countryRanks() << std::endl;

    for (int x = 0; x < 8; x++)
    {
        historyBook->addCommit(countries[x]->createMemento(countries[x]));
    }

    std::cout << std::endl;
}

std::string WarPadel::nameGenerator()
{
    bool found = false;
    int i = randomNumGenerator(0, 6);

    while (!found)
    {
        if (names[i] != "")
        {
            found == true;
            std::string pick = names[i];
            names[i] = "";
            return pick;
        }
        i = randomNumGenerator(0, 6);
    }

    return "";
}

std::string WarPadel::outPutCountries()
{

    std::string output = "";
    for (int x = 0; x < 8; x++)
    {

        output += countryData(countries[x]);
    }

    return output;
}

std::string WarPadel::countryRanks()
{
    Country *ranks[8];
    for (int x = 0; x < 8; x++)
    {
        ranks[x] = countries[x];
    }

    for (int step = 0; step < 8 - 1; step++)
    {
        for (int i = 0; i < 8 - step - 1; i++)
        {
            if (ranks[i]->getPower() < ranks[i + 1]->getPower())
            {
                auto *temp = ranks[i];
                ranks[i] = ranks[i + 1];
                ranks[i + 1] = temp;
            }
        }
    }

    std::string out = "";
    out += "1.";
    for (int x = 0; x < 8; x++)
    {
        out += ranks[x]->getName();
        out += "\t";
        out += toString(ranks[x]->getPower());

        if (ranks[x]->getPower() < 0)
        {
            out += "\t Fallen";
        }
        out += "\n";
        out += "-----------------------------------------------------------------";
        out += "\n";
    }

    return out;
}

void WarPadel::selectWarTheatres()
{
    ListSelectionPrompt prompt = {
        "Land", "Sea", "Air", "Space"};

    int index = prompt.getSelectionIndex("Select battlefield to defend(Only one per type): ");
    switch (index)
    {
    case 0:
        countries[0]->addWarFront("Land");
        break;
    case 1:
        countries[0]->addWarFront("Sea");
        break;
    case 2:
        countries[0]->addWarFront("Air");
        break;
    case 3:
        countries[0]->addWarFront("Space");
        break;
    default:
        break;
    }

    std::cout << std::endl;
}
void WarPadel::setWarTheatres(Country *country)
{
    std::string theatreTypes[] = {"Land", "Sea", "Air", "Space"};

    int oppotunity = 4;
    int random;

    while (oppotunity > 0)
    {
        random = randomNumGenerator(0, 3);
        country->addWarFront(theatreTypes[random]);
        oppotunity--;
    }
    oppotunity = 4;

    std::cout << std::endl;
    std::cout << country->getName() << " War Fronts: " << std::endl;
    std::cout << country->allWarFronts() << std::endl
              << std::endl;
}

void WarPadel::setTraps(Country *country)
{
    std::cout << country->getName() << " is:" << std::endl;
    int amount = randomNumGenerator(10, 30);
    std::string location[] = {"Land", "Sea", "Air", "Space"};
    std::string type[] = {"Trenches", "Barricades", "SpaceMagnets", "Mines"};

    for (; amount > 0; amount--)
    {
        int l = randomNumGenerator(0, 3);
        int t = randomNumGenerator(0, 3);

        country->setTrap(location[l], type[t]);
    }

    std::cout << std::endl;
}

void WarPadel::setMilitary(Country *country)
{
    int recruit;
    int groupsize;
    int oppotunity = randomNumGenerator(10, 20);

    std::cout << country->getName() << " Empowering Army.." << std::endl;

    while (oppotunity > 0)
    {
        oppotunity--;
        recruit = randomNumGenerator(0, 4);
        groupsize = randomNumGenerator(100, 500);

        switch (recruit)
        {
        case 0:
            country->recruitSoldiers(groupsize);
            break;
        case 1:
            country->recruitMarines(groupsize);
            break;
        case 2:
            country->recruitPilots(groupsize);
            break;
        case 3:
            country->recruitGuardians(groupsize);
            break;
        case 4:
            country->recruitMedics(groupsize);
            break;
        default:
            break;
        }
    }

    std::cout << std::endl;
}

void WarPadel::purchaseWeapons(Country *country)
{
    std::cout << country->getName() << " is purchasing..." << std::endl;
    capatalists = new ArmoryFacade();
    std::vector<Recruits *> recruit = country->getRecruits();

    for (int x = 0; x < recruit.size(); x++)
    {
        if (recruit[x] != nullptr)
        {
            if (recruit[x]->getMilitaryType() != "Medic")
            {
                capatalists->purchaseAttackVessel(recruit[x]);
                capatalists->purchaseWeapon(recruit[x]);
                capatalists->purchaseSupplies(recruit[x]);
            }
        }
    }

    std::cout << std::endl;
}

void WarPadel::purchaseInput()
{
    std::vector<Recruits *> recruit = countries[0]->getRecruits();
    ListSelectionPrompt prompt2 = {"Soldiers", "Marines", "Pilots", "Gaurdians"};
    int p = prompt2.getSelectionIndex("Which of your military regiment are you supplying? ");
    bool found = false;
    int index = -1;

    switch (p)
    {
    case 0:
        for (int x = 0; x < recruit.size(); x++)
        {
            if (recruit[x]->getMilitaryType() == "Soldier")
            {
                found = true;
                index = x;
            }
        }
        break;
    case 1:
        for (int x = 0; x < recruit.size(); x++)
        {
            if (recruit[x]->getMilitaryType() == "Marine")
            {
                found = true;
                index = x;
            }
        }
        break;
    case 2:
        for (int x = 0; x < recruit.size(); x++)
        {
            if (recruit[x]->getMilitaryType() == "Pilot")
            {
                found = true;
                index = x;
            }
        }
        break;
    case 3:
        for (int x = 0; x < recruit.size(); x++)
        {
            if (recruit[x]->getMilitaryType() == "Gaudian")
            {
                found = true;
                index = x;
            }
        }

        break;
    default:
        break;
    }

    if (found == false)
    {
        std::cout << "Regiment does not have men" << std::endl;
        return;
    }

    ListSelectionPrompt prompt = {
        "Attack Weapons", "Vessel Weapons", "Supplies", "Nothing"};

    index = prompt.getSelectionIndex("What will you purchase: ");
    switch (index)
    {
    case 0:
        capatalists->purchaseWeaponInput(recruit[index]);
        break;
    case 1:
        capatalists->purchaseAttackVessel(recruit[index]);
        break;
    case 2:
        capatalists->purchaseSupplies(recruit[index]);
        break;
    default:
        break;
    }
}

void WarPadel::buyTraps()
{
    std::string trap;
    std::string front;

    std::cout << "Which trap will you set? (Trenches, Barricades, Mines, SpaceMagnets) SPELLING" << std::endl;
    std::cin >> trap;

    std::cout << "Onto which war front? (Land, Sea, Air, Space) SPELLING" << std::endl;
    std::cin >> front;

    countries[0]->setTrap(front, trap);
}

void WarPadel::enlisting()
{
    ListSelectionPrompt prompt = {
        "Soldiers", "Marines", "Pilots", "Guardians", "Medics"};
    std::string ans;

    int index = prompt.getSelectionIndex("Select regiments to enlist: ");
    std::cout << "Group size?: ";
    std::cin >> ans;
    std::stringstream toInt;
    toInt << ans;
    int size;
    toInt >> size;

    switch (index)
    {

    case 0:
        countries[0]->recruitSoldiers(size);
        break;
    case 1:
        countries[0]->recruitMarines(size);
        break;
    case 2:
        countries[0]->recruitPilots(size);
        break;
    case 3:
        countries[0]->recruitGuardians(size);
        break;
    case 4:
        countries[0]->recruitMedics(size);
        break;
    default:
        break;
    }
}

bool WarPadel::makeDecisionPhase2()
{
    std::cout << std::endl;
    bool cont = true;
    ListSelectionPrompt prompt = {
        "Prepare Battlground", "Buy and set Traps", "Enlist recruits", "Buy Weapons", "Randomise", "Done"};

    int index = prompt.getSelectionIndex("Please select an action: ");

    switch (index)
    {
    case 0:
        std::cout << std::endl;
        selectWarTheatres();
        break;
    case 1:
        buyTraps();
        break;
    case 2:
        enlisting();
        break;
    case 3:
        purchaseInput();
        break;
    case 4:
        cont = Randomise();
        break;
    case 5:
        cont = false;
        break;
    default:
        break;
    }

    return cont;
}

void WarPadel::stopPedaling()
{
}

// void WarPadel::runGUIEngine()
// {

// }

// AllyRegistry WarPadel::getAllyRegistry()
// {
//     return allyRegistry;
// }

Registry *WarPadel::getBattleRegistry()
{
    return battleRegistry;
}

// void WarPadel::setTest(int data)
// {
//     test = data;
// }

// int WarPadel::getTest()
// {
//     return test;
// }

// void WarPadel::setAllyRegistry(AllyRegistry &ar)
// {
//     this->allyRegistry = ar;
// }

// void WarPadel::setBattleRegistry(BattleRegistry &br)
// {
//     this->battleRegistry = br;
// }

WarPadel &WarPadel::getInstanceWarPadel()
{
    static WarPadel onlyInstance_;
    return onlyInstance_;
}

WarPadel::~WarPadel()
{
}

WarPadel::WarPadel()
{
    names = new std::string[7];
    // for now 7 names

    names[0] = "Asgard";
    names[1] = "New London";
    names[2] = "Westeros";
    names[3] = "Rome";
    names[4] = "Hell";
    names[5] = "Musk Mars";
    names[6] = "Wonder Land";

    historyBook = new CountryHistory();
    historyChapters=0;
}

int randomNumGenerator(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

std::string toString(int a)
{
    std::stringstream in;
    std::string st;
    in << a;
    in >> st;
    return st;
}
std::string countryData(Country *ca)
{
    std::string output = "";
    output += ca->getName();
    output += "\n";
    output += "Economy:\t ";
    output += toString(ca->getEconomy());
    output += "\n";
    output += "Population:\t ";
    output += toString(ca->getPopulation());
    output += "\n";
    output += "Man Power:\t ";
    output += toString(ca->getNotEnlisted());
    output += "\n";
    output += "POWER:\t ";
    output += toString(ca->getPower());
    output += "\n\n";

    return output;
}
