#include <Country.h>
#include <random>

Country::Country(std::string countryName)
    : countryName(std::move(countryName))
{
    armoryFacade = new ArmoryFacade();
    //The below code will be modified and moved to WarEngine.cpp

    // Set up PRNG
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dist(1e4, 5e4);

    // this->populationSize = dist(gen);
    // this->citizens = new Citizens();
    // int cit = (int)(populationSize*0.7);
    // this->citizens->setGroupSize(cit);
    // this->notEnlisted = populationSize - cit;
    
    // dist = std::uniform_int_distribution<>(1, 3);
    // this->economicClass = static_cast<EconomicClass>(dist(gen));

    // std::uniform_int_distribution<> classDist;
    // switch (economicClass)
    // {
    //     case FIRST_WORLD:
    //         classDist = std::uniform_int_distribution<>(1e4, 5e4);
    //         break;
    //     case SECOND_WORLD:
    //         classDist = std::uniform_int_distribution<>(5e3, 1e4);
    //         break;
    //     case THIRD_WORLD:
    //         classDist = std::uniform_int_distribution<>(1e3, 5e3);
    //         break;
    // }
    // economy = classDist(gen);
    // this->power = populationSize * economy;

    // Marines= false;
    // Guardians= false;
    // Pilots= false;
    // Soldiers = false;

    // warTheatres = new WarTheatre*[4];
    // warTheatres[0] = nullptr;
    // warTheatres[1] = nullptr;
    // warTheatres[2] = nullptr;
    // warTheatres[3] = nullptr;
}

Country* Country::cloneCountry()
{
    auto* result = new Country(countryName);
    result->economy = economy;
    result->power = power;
    result->populationSize = populationSize;

    return result;
}

const std::string& Country::getName() const
{
    return countryName;
}
void Country::setName(std::string name){
    this->countryName = std::move(name);
}
int Country::getPower() const
{
    return power;
}

void Country::setPower(int power)
{
    Country::power = power;
}

int Country::getEconomy() const
{
    return economy;
}

void Country::setEconomy(int economy)
{
    Country::economy = economy;
}

void Country::recruitMarines(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    // bool found = false;
    // auto it = recruits.begin();

    // for(;it< recruits.end(); it++)
    // {
    //     if((*it)->getMilitaryType()=="Marine")
    //     {
    //         found=true;
    //         break;
    //     }
    // }

    // if(found)
    // {
    //     (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
    //     this->notEnlisted = this->notEnlisted - squadSize;

    // }
    // else
    // {
    Recruits *Navy = new Marine();
    Navy->setGroupSize(squadSize);
    Navy->setMilitaryType("Marine");
    this->notEnlisted = this->notEnlisted - squadSize;
    recruits.push_back(Navy);
    // }
}

void Country::recruitSoldiers(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    // bool found = false;
    // auto it = recruits.begin();

    // for(; it< recruits.end(); it++)
    // {
    //     if((*it)->getMilitaryType()=="Soldier")
    //     {
    //         found=true;
    //         break;
    //     }
    // }

    // if(found)
    // {
    //     (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
    //     this->notEnlisted = this->notEnlisted - squadSize;

    // }
    // else
    // {
    Recruits *Army = new Soldier();
    Army->setGroupSize(squadSize);
    Army->setMilitaryType("Soldier");
    this->notEnlisted = this->notEnlisted - squadSize;
    recruits.push_back(Army);
    // }
}

void Country::recruitMedics(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    // bool found = false;
    // auto it = recruits.begin();

    // for(; it< recruits.end(); it++)
    // {
    //     if((*it)->getMilitaryType()=="Medic")
    //     {
    //         found=true;
    //         break;
    //     }
    // }

    // if(found)
    // {
    //     (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
    //     this->notEnlisted = this->notEnlisted - squadSize;

    // }
    // else
    // {
    Recruits *Med = new Medic();
    Med->setGroupSize(squadSize);
    Med->setMilitaryType("Medic");
    this->notEnlisted = this->notEnlisted - squadSize;
    recruits.push_back(Med);
    // }
}

void Country::recruitGuardians(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    // bool found = false;
    // auto it = recruits.begin();

    // for(; it< recruits.end(); it++)
    // {
    //     if((*it)->getMilitaryType()=="Guardian")
    //     {
    //         found=true;
    //         break;
    //     }
    // }

    // if(found)
    // {
    //     (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
    //     this->notEnlisted = this->notEnlisted - squadSize;

    // }
    // else
    // {
       
    auto* Guard = new Guardian();
    Guard->setGroupSize(squadSize);
    Guard->setMilitaryType("Marine");
    this->notEnlisted = this->notEnlisted - squadSize;
    recruits.push_back(Guard);
    // }
}

void Country::recruitPilots(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    // bool found = false;
    // auto it = recruits.begin();

    // for(; it< recruits.end(); it++)
    // {
    //     if((*it)->getMilitaryType()=="Pilot")
    //     {
    //         found=true;
    //         break;
    //     }
    // }

    // if(found)
    // {
    //     (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
    //     this->notEnlisted = this->notEnlisted - squadSize;

    // }
    // else
    // {
    Recruits *pilot = new Pilot();
    pilot->setGroupSize(squadSize);
    pilot->setMilitaryType("Pilot");
    this->notEnlisted = this->notEnlisted - squadSize;
    recruits.push_back(pilot);
    // }
}

void Country::updatePopulationSize()
{
    int count=0;

    count+= citizens->getGroupSize();

    if(refugees != nullptr)
    {
        count += refugees->getGroupSize();
    }
    
    count += notEnlisted;

    auto it = recruits.begin();

    for(; it< recruits.end(); it++)
    {
        count += (*it)->getGroupSize();
    }

    this->populationSize = count;

}

void Country::updatePower()
{
    this->power = this->populationSize*economy;
}

void Country::setPopulation(int population){
    this->populationSize = population;
}

int Country::getPopulation() const
{
    return populationSize;
}

int Country::getNotEnlisted() const
{
    return notEnlisted;
}

void Country::setNotEnlisted(int Amount)
{
    this->notEnlisted = Amount;
}

std::vector<WarTheatre*> Country::getWarTheatres(){
    return wwarTheatres;
}
// WarTheatre* Country::getWarFront(const std::string& Type)
// { 
//     // int index = getIndex(Type);
//     // WarTheatre* front = warTheatres[index];

//     WarTheatre* front = nullptr;

//     for(auto* w : wwarTheatres){
//         if(w->getLocation() == Type){
//             front = w;
//         }
//     }
    
//     if(front != nullptr)
//     {
//         while(front->getLocation()== "Trap")
//         {
//             front = front->getTrap();
//         }
//     }

//     return front;
// }

void Country::addWarFront(/*const std::string& location*/BattleGround* battleGround)
{
    wwarTheatres.emplace_back(battleGround);
    // WarTheatre* check = getWarFront(location);

    // if(check == nullptr)
    // {
        // WarTheatre *warFront;

        // if(location == "Land")
        // {
        //     wwarTheatres.emplace_back(new Land());
        //     // warFront = new Land();
        //     // warTheatres[0] = warFront;
        // }
        // else if(location == "Sea")
        // {
        //     wwarTheatres.emplace_back(new Sea());
        //     // warFront = new Sea();
        //     // warTheatres[1] = warFront;
        // }
        // else if(location == "Air")
        // {
        //     wwarTheatres.emplace_back(new Air());
        //     // warFront = new Air();
        //     // warTheatres[2] = warFront;
        // }
        // else{
        //     wwarTheatres.emplace_back(new Space());
        //     // warFront = new Space();
        //     // warTheatres[3] = warFront;
        // }
    // }
}

// int Country::getIndex(const std::string& Type)
// {
//     int i=-1;
//     if(Type=="Land")
//     {
//         i=0;
//     }
//     else if(Type=="Sea")
//     {
//         i=1;
//     }
//     else if(Type=="Air")
//     {
//         i=2;
//     }
//     else
//     {
//         i=3;
//     }

//     return i;
// }

std::string Country:: allWarFronts()
{
    std::string out;
    for(auto w : wwarTheatres){
        out += "- " + w->getName() + "\n";
    }
    

    // if(warTheatres[0]!= nullptr)
    // {
    //     out += "Land\n";
    // }
    // if(warTheatres[1]!= nullptr)
    // {
    //     out += "Sea\n";
    // }
    // if(warTheatres[2]!= nullptr)
    // {
    //     out += "Air\n";
    // }
    // if(warTheatres[3]!= nullptr)
    // {
    //     out += "Space\n";
    // }
    return out;
}

void Country::setTrap(BattleGround *battleGround, /*const std::string& Trap*/ Trap *trap)
{
    // WarTheatre* check = getWarFront(battleGround);
    // if(check == nullptr)
    // {
    //     return;
    // }
    
    // WarTheatre* Temp;

    // if(Trap == "SpaceMagnets")
    // {
    //     if(battleGround->getLocation() == "Space")
    //     {
    //         return;
    //     }
        
    //     Temp = new SpaceMagnets();  
    // }

    // if(Trap == "Mines")
    // {
    //     if(battleGround->getLocation() == "Air")
    //     {
    //         return;
    //     }

    //     Temp = new Mines();
    // }

    // if(Trap == "Barricades")
    // {
    //     if(battleGround->getLocation() == "Air")
    //     {
    //         return;
    //     }

    //     Temp = new Barricades();
    // }

    // if(Trap == "Trenches")
    // {
    //     if(battleGround->getLocation() != "Land")
    //     {
    //         return;
    //     }

    //     Temp = new Trenches();

    // }
    
    // int index = getIndex(battleGround);
    // Temp->add(battleGround);
    // warTheatres[index]= Temp;

    WarTheatre* temp;
    switch (trap->getType())
    {
        case enums::SpaceMagnets:
            if(battleGround->getLocation() == "Space")
                temp = new SpaceMagnets();
            break;      
        case enums::Mines:
            if(battleGround->getLocation() != "Air")
                temp = new Mines();   
            break;
        case enums::Barricades:
            if(battleGround->getLocation() != "Air")
                temp = new Barricades();
            break;
        case enums::Trenches:
             if(battleGround->getLocation() == "Land")
                temp = new Trenches();
            break;
        default:
            std::cout<<"you can't add a "<<trap->getType()<<" "<<battleGround->getLocation()<<std::endl;
            return;
    }
    temp->add(battleGround);
    wwarTheatres.emplace_back(temp);
}

void Country::removeFront(BattleGround* battleGround)
{
    if(battleGround != nullptr)
        return;
 
    for (auto it = wwarTheatres.begin(); it != wwarTheatres.end(); ++it){
        if(*it == battleGround){
            wwarTheatres.erase(it);
            break;
        }       
    }
 

  
  
    // Printing the Vector
   
    // int index = getIndex(Location);

    // if(warTheatres[index]!= nullptr)
    // {
    //     delete warTheatres[index];
    // }

    // warTheatres[index]= nullptr;
}

int Country:: warFrontDanger(BattleGround* battleGround)
{
    int total =0;
    if(battleGround==nullptr)
    {
        
        for(auto w : wwarTheatres){
            if(w != nullptr){
                total += w->damageTotal();
            }
        }
        // for(int x=0; x<4; x++)
        // {
        //     if(warTheatres[x] != nullptr)
        //     {
        //         total += warTheatres[x]->damageTotal();
        //     }
        // }
    }
    else
    {
        return battleGround->damageTotal();
        // int index = getIndex(totalOf);

        // if(warTheatres[index] != nullptr)
        // {
        //     total = warTheatres[index]->damageTotal();
        // }
    }

    return total;
}

std::vector<Recruits*> Country::getRecruits(){
    return recruits;
}

void Country::setRecruits(std::vector<Recruits*> recruits){
    this->recruits = std::move(recruits);
}

Country::~Country()
{
    for(auto w : wwarTheatres)
    {
        if(w != nullptr)
        {
            delete w;
            w = nullptr;
        }        
    }
    wwarTheatres.clear();
    for(auto r : recruits)
    {
        if(r != nullptr)
        {
//            delete r;
            r = nullptr;
        }      
    }
    // delete armoryFacade;
    // armoryFacade = nullptr;
    recruits.clear();
 
    // for(int x=0; x<4; x++)
    // {
    //     delete warTheatres[x];
    // }

    // delete [] warTheatres;

    // while(!recruits.empty())
    // {
    //     Recruits* r = recruits.back();
    //     recruits.pop_back();
    //     delete r;
    // }
}

ArmoryFacade* Country::getArmoryFacade() const{
    return armoryFacade;
}

const Recruits* Country::getRecruit(int i) const {
    return this->recruits[i];
}

const std::vector<Recruits *> &Country::getRecruits() const {
    return recruits;
}

Refugee* Country::getRefugees(){
    return refugees;
}

void Country::setRefugees(Refugee* refugees)
{
    this->refugees = refugees;
}

Citizens* Country::getCitizens(){
    return citizens;
}

void Country::setCitizens(Citizens* citizens)
{
    this->citizens = citizens;
}

EconomicClass Country::getEconomicClass() const
{
    return economicClass;
}

enums::PoliticalRegime Country::getPoliticalRegime(){
        return politicalRegime;
}
void Country::setPoliticalRegime(enums::PoliticalRegime pr){
    this->politicalRegime = pr;
}