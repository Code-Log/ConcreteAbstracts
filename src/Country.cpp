#include <Country.h>
#include <random>

Country::Country(std::string countryName)
    : countryName(std::move(countryName))
{
    // Set up PRNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1e4, 5e4);

    this->populationSize = dist(gen);
    this->citizens = new Citizens();
    int cit = (int)(populationSize*0.7);
    this->citizens->setGroupSize(cit);
    this->notEnlisted = populationSize - cit;
    
    dist = std::uniform_int_distribution<>(1, 3);
    this->economicClass = static_cast<EconomicClass>(dist(gen));

    std::uniform_int_distribution<> classDist;
    switch (economicClass)
    {
        case FIRST_WORLD:
            classDist = std::uniform_int_distribution<>(1e4, 5e4);
            break;
        case SECOND_WORLD:
            classDist = std::uniform_int_distribution<>(5e3, 1e4);
            break;
        case THIRD_WORLD:
            classDist = std::uniform_int_distribution<>(1e3, 5e3);
            break;
    }
    economy = classDist(gen);
    this->power = populationSize * economy;

    // Marines= false;
    // Guardians= false;
    // Pilots= false;
    // Soldiers = false;

    warTheatres = new WarTheatre*[4];
    warTheatres[0] = nullptr;
    warTheatres[1] = nullptr;
    warTheatres[2] = nullptr;
    warTheatres[3] = nullptr;
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

    bool found = false;
    auto it = recruits.begin();

    for(;it< recruits.end(); it++)
    {
        if((*it)->getMilitaryType()=="Marine")
        {
            found=true;
            break;
        }
    }

    if(found)
    {
        (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;

    }
    else
    {
        Recruits *Navy = new Marine();
        Navy->setGroupSize(squadSize);
        Navy->setMilitaryType("Marine");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Navy);
    }
}

void Country::recruitSoldiers(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for(; it< recruits.end(); it++)
    {
        if((*it)->getMilitaryType()=="Soldier")
        {
            found=true;
            break;
        }
    }

    if(found)
    {
        (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;

    }
    else
    {
        Recruits *Army = new Soldier();
        Army->setGroupSize(squadSize);
        Army->setMilitaryType("Soldier");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Army);
    }
}

void Country::recruitMedics(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for(; it< recruits.end(); it++)
    {
        if((*it)->getMilitaryType()=="Medic")
        {
            found=true;
            break;
        }
    }

    if(found)
    {
        (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;

    }
    else
    {
        Recruits *Med = new Medic();
        Med->setGroupSize(squadSize);
        Med->setMilitaryType("Medic");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Med);
    }
}

void Country::recruitGuardians(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for(; it< recruits.end(); it++)
    {
        if((*it)->getMilitaryType()=="Guardian")
        {
            found=true;
            break;
        }
    }

    if(found)
    {
        (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;

    }
    else
    {
        Recruits *Guard = new Marine();
        Guard->setGroupSize(squadSize);
        Guard->setMilitaryType("Marine");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Guard);
    }
}

void Country::recruitPilots(int squadSize)
{
    if(notEnlisted< squadSize)
    {
        std::cout<<"Not enough man power"<<std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for(; it< recruits.end(); it++)
    {
        if((*it)->getMilitaryType()=="Pilot")
        {
            found=true;
            break;
        }
    }

    if(found)
    {
        (*it)->setGroupSize((*it)->getGroupSize()+ squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;

    }
    else
    {
        Recruits *Pilot = new Marine();
        Pilot->setGroupSize(squadSize);
        Pilot->setMilitaryType("Pilot");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Pilot);
    }
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

WarTheatre* Country::getWarFront(const std::string& Type)
{ 
    int index = getIndex(Type);
    WarTheatre* front = warTheatres[index];
    
    if(front != nullptr)
    {
        while(front->getLocation()== "Trap")
        {
            front = front->getTrap();
        }
    }

    return front;
}

void Country::addWarFront(const std::string& location)
{
    WarTheatre* check = getWarFront(location);

    if(check == nullptr)
    {
        WarTheatre *warFront;

        if(location == "Land")
        {
            warFront = new Land();
            warTheatres[0] = warFront;
        }
        else if(location == "Sea")
        {
            warFront = new Sea();
            warTheatres[1] = warFront;
        }
        else if(location == "Air")
        {
            warFront = new Air();
            warTheatres[2] = warFront;
        }
        else{
            warFront = new Space();
            warTheatres[3] = warFront;
        }
    }
}

int Country::getIndex(const std::string& Type)
{
    int i=-1;
    if(Type=="Land")
    {
        i=0;
    }
    else if(Type=="Sea")
    {
        i=1;
    }
    else if(Type=="Air")
    {
        i=2;
    }
    else
    {
        i=3;
    }

    return i;
}

std::string Country:: allWarFronts()
{
    std::string out = "";

    if(warTheatres[0]!= nullptr)
    {
        out += "Land\n";
    }
    if(warTheatres[1]!= nullptr)
    {
        out += "Sea\n";
    }
    if(warTheatres[2]!= nullptr)
    {
        out += "Air\n";
    }
    if(warTheatres[3]!= nullptr)
    {
        out += "Space\n";
    }
    return out;
}

void Country::setTrap(const std::string& battleGround, const std::string& Trap)
{
    WarTheatre* check = getWarFront(battleGround);
    if(check == nullptr)
    {
        return;
    }

    WarTheatre* Temp;

    if(Trap == "SpaceMagnets")
    {
        if(battleGround!= "Space")
        {
            return;
        }
        
        Temp = new SpaceMagnets();  
    }

    if(Trap == "Mines")
    {
        if(battleGround == "Air")
        {
            return;
        }

        Temp = new Mines();
    }

    if(Trap == "Barricades")
    {
        if(battleGround == "Air")
        {
            return;
        }

        Temp = new Barricades();
    }

    if(Trap == "Trenches")
    {
        if(battleGround!= "Land")
        {
            return;
        }

        Temp = new Trenches();

    }

    int index = getIndex(battleGround);
    Temp->add(warTheatres[index]);
    warTheatres[index]= Temp;

}

void Country::removeFront(const std::string& Location)
{
    int index = getIndex(Location);

    if(warTheatres[index]!= nullptr)
    {
        delete warTheatres[index];
    }

    warTheatres[index]= nullptr;

}

int Country:: warFrontDanger(const std::string& totalOf)
{
    int total =0;
    if(totalOf=="All")
    {
        

        for(int x=0; x<4; x++)
        {
            if(warTheatres[x] != nullptr)
            {
                total += warTheatres[x]->damageTotal();
            }
        }
    }
    else
    {
        int index = getIndex(totalOf);

        if(warTheatres[index] != nullptr)
        {
            total = warTheatres[index]->damageTotal();
        }

    }

    return total;
}

Country::~Country()
{
    for(int x=0; x<4; x++)
    {
        delete warTheatres[x];
    }

    delete [] warTheatres;

    while(!recruits.empty())
    {
        Recruits* r = recruits.back();
        recruits.pop_back();
        delete r;
    }
}
