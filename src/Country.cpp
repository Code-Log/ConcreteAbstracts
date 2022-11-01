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

void Country::addWarFront(const std::string& location)
{
    bool found = false;
    auto it = warTheatres.begin();

    for(; it< warTheatres.end(); it++)
    {
        if((*it)->getLocation()== location)
        {
            found=true;
            break;
        }
    }

    if(!found)
    {
        WarTheatre *warFront;

        if(location == "Sea")
        {
            warFront = new Sea();
        }
        else if(location == "Land")
        {
            warFront = new Land();
        }
        else if(location == "Space")
        {
            warFront = new Space();
        }
        else{
            warFront = new Air();
        }

        warTheatres.push_back(warFront);
    }
}

Country::~Country()
{
    while(!warTheatres.empty())
    {
        WarTheatre* wt = warTheatres.back();
        warTheatres.pop_back();
        delete wt;
    }

    while(!recruits.empty())
    {
        Recruits* r = recruits.back();
        recruits.pop_back();
        delete r;
    }
}