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
    int cit = (int)(populationSize * 0.7);
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

    recruits.clear();

    // Marines= false;
    // Guardians= false;
    // Pilots= false;
    // Soldiers = false;

    warTheatres = new WarTheatre *[4];
    warTheatres[0] = nullptr;
    warTheatres[1] = nullptr;
    warTheatres[2] = nullptr;
    warTheatres[3] = nullptr;
}

Country *Country::cloneCountry()
{
    auto *result = new Country(countryName);
    result->economy = economy;
    result->power = power;
    result->populationSize = populationSize;
    result->citizens = new Citizens();                      // added this
    citizens->setGroupSize(this->citizens->getGroupSize()); // added this
    result->notEnlisted = this->notEnlisted;                // added

    return result;
}

CountryMemento *Country::createMemento(Country *country)
{
    CountryMemento *mem = new CountryMemento(country->cloneCountry());
    std::cout << "Recording " << country->getName() << " into world database..." << std::endl;
    return mem;
}

void Country::reinstateMemento(CountryMemento *mem)
{
    if(mem== nullptr)
    {
        return;
    }
    Country *mems = mem->state;
    this->countryName = mems->countryName;
    this->economy = mems->economy;
    this->power = mems->power;
    this->populationSize = mems->populationSize;
    this->citizens->setGroupSize(mems->citizens->getGroupSize()); // added this
    this->notEnlisted = mems->notEnlisted;                        // added
}

const std::string &Country::getName() const
{
    return countryName;
}

double Country::getPower() const
{
    return power;
}

void Country::setPower(double power)
{
    Country::power = power;
}

double Country::getEconomy() const
{
    return economy;
}

void Country::setEconomy(double economy)
{
    Country::economy = economy;
}

void Country::recruitMarines(int squadSize)
{
    if (notEnlisted < squadSize)
    {
        std::cout << "Not enough man power" << std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for (; it < recruits.end(); it++)
    {
        if ((*it)->getMilitaryType() == "Marine")
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        (*it)->setGroupSize((*it)->getGroupSize() + squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;
    }
    else
    {
    
        Recruits *Navy = new Marine();
        Navy->setCountry(this);
        Navy->setGroupSize(squadSize);
        Navy->setMilitaryType("Marine");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Navy);
    }

    std::cout << squadSize << " Marines ready for battle!" << std::endl;
}

void Country::recruitSoldiers(int squadSize)
{
    if (notEnlisted < squadSize)
    {
        std::cout << "Not enough man power" << std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for (; it < recruits.end(); it++)
    {
        if ((*it)->getMilitaryType() == "Soldier")
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        (*it)->setGroupSize((*it)->getGroupSize() + squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;
    }
    else
    {

        Recruits *Army = new Soldier();
        Army->setCountry(this);
        Army->setGroupSize(squadSize);
        Army->setMilitaryType("Soldier");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Army);
    }

    std::cout << squadSize << " Soldiers ready for battle!" << std::endl;
}

void Country::recruitMedics(int squadSize)
{
    if (notEnlisted < squadSize)
    {
        std::cout << "Not enough man power" << std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for (; it < recruits.end(); it++)
    {
        if ((*it)->getMilitaryType() == "Medic")
        {
            found = true;
            break;
        }
    }

    if (found) 
    {
        (*it)->setGroupSize((*it)->getGroupSize() + squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;
    }
    else
    {
        Recruits *Med = new Medic();
        Med->setCountry(this);
        Med->setGroupSize(squadSize);
        Med->setMilitaryType("Medic");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Med);
    }

    std::cout << squadSize << " Medics ready for battle!" << std::endl;
}

void Country::recruitPilots(int squadSize)
{
    if (notEnlisted < squadSize)
    {
        std::cout << "Not enough man power" << std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for (; it < recruits.end(); it++)
    {
        if ((*it)->getMilitaryType() == "Pilot")
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        (*it)->setGroupSize((*it)->getGroupSize() + squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;
    }
    else
    {
        Recruits *pilot = new Pilot();
        pilot->setCountry(this);
        pilot->setGroupSize(squadSize);
        pilot->setMilitaryType("Pilot");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(pilot);
    }

    std::cout << squadSize << " Pilots ready for battle!" << std::endl;
}

void Country::recruitGuardians(int squadSize)
{
    if (notEnlisted < squadSize)
    {
        std::cout << "Not enough man power" << std::endl;
        return;
    }

    bool found = false;
    auto it = recruits.begin();

    for (; it < recruits.end(); it++)
    {
        if ((*it)->getMilitaryType() == "Guardian")
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        (*it)->setGroupSize((*it)->getGroupSize() + squadSize);
        this->notEnlisted = this->notEnlisted - squadSize;
    }
    else
    {

        Recruits *Guard = new Guardian();
        Guard->setCountry(this);
        Guard->setGroupSize(squadSize);
        Guard->setMilitaryType("Marine");
        this->notEnlisted = this->notEnlisted - squadSize;
        recruits.push_back(Guard);
    }

    std::cout << squadSize << " Guardians ready for battle!" << std::endl;
}

void Country::setCitizens(int amount)
{
    citizens->setGroupSize(amount);
}

int Country::getCitizens()
{
   return citizens->getGroupSize();
}

RecruitIterator *Country::createRecruitIterator(std::vector<Recruits *> rec)
{
    RecruitIterator *it = new RecruitIterator(rec);
    return it;
}

WarTheatre** Country::getWarFront()
{
    return warTheatres;
}

void Country::updatePopulationSize()
{
    int count = 0;

    count += citizens->getGroupSize();

    if (!(refugees.empty()))
    {
        for(int x=0; x< refugees.size(); x++)
        {
            count += refugees[x]->getGroupSize();
            economy -= refugees[x]->getGroupSize();
        }
        
    }

    count += notEnlisted;

    auto it = recruits.begin();
    int am=0;

    for(; it< recruits.end(); it++)
    {
        am= (*it)->getGroupSize();

        if(am>0)
        {
            count += am; 
        }
   
    }
    //std::cout<<count<<" <-<-<-<-"<<std::endl;

    this->populationSize = count;
}

std::vector<Recruits*> Country::getRecruits()
{
    return recruits;
}

std::vector<Refugee*> Country::getRefugees()
{
    return refugees;
}
Recruits* Country::searchAndRetrieve(std::string Type)
{
    for(int x=0; x< recruits.size(); x++)
    {
        if(recruits[x]->getMilitaryType()== Type && recruits[x]->getGroupSize()>0)
        {
            return recruits[x];
        }
    }

    return nullptr;
}
void Country::updatePower()
{
    this->power = this->populationSize * economy;
}

double Country::getPopulation() const
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

WarTheatre *Country::getWarFront(const std::string &Type)
{
    int index = getIndex(Type);
    WarTheatre *front = warTheatres[index];

    if (front != nullptr)
    {
        while (front->getLocation() == "Trap")
        {
            front = front->getTrap();
        }
    }

    return front;
}

void Country::addWarFront(const std::string &location)
{
    WarTheatre *check = getWarFront(location);

    if (check == nullptr)
    {
        WarTheatre *warFront;

        if (location == "Land")
        {
            warFront = new Land();
            warTheatres[0] = warFront;
        }
        else if (location == "Sea")
        {
            warFront = new Sea();
            warTheatres[1] = warFront;
        }
        else if (location == "Air")
        {
            warFront = new Air();
            warTheatres[2] = warFront;
        }
        else
        {
            warFront = new Space();
            warTheatres[3] = warFront;
        }
    }
}

int Country::getIndex(const std::string &Type)
{
    int i = -1;
    if (Type == "Land")
    {
        i = 0;
    }
    else if (Type == "Sea")
    {
        i = 1;
    }
    else if (Type == "Air")
    {
        i = 2;
    }
    else
    {
        i = 3;
    }

    return i;
}

std::string Country::allWarFronts()
{
    std::string out = "";

    if (warTheatres[0] != nullptr)
    {
        out += "Land\n";
    }
    if (warTheatres[1] != nullptr)
    {
        out += "Sea\n";
    }
    if (warTheatres[2] != nullptr)
    {
        out += "Air\n";
    }
    if (warTheatres[3] != nullptr)
    {
        out += "Space\n";
    }
    return out;
}

void Country::setTrap(const std::string &battleGround, const std::string &Trap)
{
    
    WarTheatre *check = getWarFront(battleGround);
    if (check == nullptr)
    {
        //std::cout<<"WarFront not set"<<std::endl;
        return;
    }
    
    WarTheatre *Temp;

    if (Trap == "SpaceMagnets")
    {
        if (battleGround != "Space" || getEconomy()<400)
        {
            //std::cout<<"Trap failed"<<std::endl;
            return;
        }

        setEconomy(getEconomy()-400);
        Temp = new SpaceMagnets();
    }
    
    if (Trap == "Mines")
    {
        if (battleGround == "Air" || getEconomy()<300)
        {
            //std::cout<<"Trap failed"<<std::endl;
            return;
        }

        setEconomy(getEconomy()-300);
        Temp = new Mines();
    }
    
    if (Trap == "Barricades")
    {
        if (battleGround == "Air" || getEconomy()<200)
        {
            //std::cout<<"Trap failed"<<std::endl;
            return;
        }

        setEconomy(getEconomy()-200);
        Temp = new Barricades();
    }
    
    if (Trap == "Trenches")
    {
        if (battleGround != "Land" || getEconomy()<100)
        {
            //std::cout<<"Trap failed"<<std::endl;
            return;
        }

        setEconomy(getEconomy()-100);
        Temp = new Trenches();
    }

    int index = getIndex(battleGround);
    Temp->add(warTheatres[index]);
    warTheatres[index] = Temp;

   
}

WarTheatre* Country::getIndexWarFront(int i)
{
    return warTheatres[i];
}
void Country::removeFront(const std::string &Location)
{
    int index = getIndex(Location);

    if (warTheatres[index] != nullptr)
    {
        delete warTheatres[index];
    }

    warTheatres[index] = nullptr;
}

int Country::warFrontDanger(const std::string &totalOf)
{
    int total = 0;
    if (totalOf == "All")
    {

        for (int x = 0; x < 4; x++)
        {
            if (warTheatres[x] != nullptr)
            {
                total += warTheatres[x]->damageTotal();
            }
        }
    }
    else
    {
        int index = getIndex(totalOf);

        if (warTheatres[index] != nullptr)
        {
            total = warTheatres[index]->damageTotal();
        }
    }

    return total;
}
void Country::addRefugee(Country* ally, int amount)
{
    auto refugee = new Refugee();
    refugee->setGroupSize(amount);
    refugee->setCountry(ally);
    refugees.push_back(refugee);

}
Country::~Country()
{
    for (int x = 0; x < 4; x++)
    {
        delete warTheatres[x];
    }

    delete[] warTheatres;

    while (!recruits.empty())
    {
        Recruits *r = recruits.back();
        recruits.pop_back();
        delete r;
    }
}
