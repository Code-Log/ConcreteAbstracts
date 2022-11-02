
#include<WarPedal.h>
#include <random>
#include<sstream>

std::string countryData(Country*);
std::string toString(int);
void WarPedal::startPedaling()
{
    Phase1();
   // Phase2();
    //Phase3();
}

void WarPedal::Phase1()
{
    //make countries
    countries = new Country*[8];
    for(int x=0; x<8; x++)
    {
        countries[x]= nullptr;
    }

    UserCountryInput();

    for(int x=1; x<8; x++)
    {
        countries[x]= new Country(nameGenerator());
    }

    std::cout<<"Country Data: "<<std::endl;
    std::cout<<outPutCountries()<<std::endl;

    std::cout<<"Power Levels Before War:"<<std::endl;
    std::cout<<countryRanks()<<std::endl;

    std::cout<<"************Saving onto MEMENTO! First use********************"<<std::endl;
    
    

}

void WarPedal::Dispute()
{
    std::cout<<"Meat is good. Meat is tasty. But not everyone thinks to so and "<<countries[0]->getName()<<" wants "<<countries[1]->getName()<<" to give up their medium-rare tendencies. It's WAR!!!"<<std::endl;

    
}

void WarPedal::UserCountryInput()
{
    std::cout<<"Name for your country: ";
    std::string name;
    std::cin>>name;

    Country* userCountry = new Country(name);
    std::cout<<"Is your country capatalist or socialist (c/s): ";
    std::string ans;
    std::cin>>ans;

    if(ans=="c")
    {
        int economy = userCountry->getEconomy();
        economy = economy*1.2;
        userCountry->setEconomy(economy);

        std::cout<<userCountry->getName()<<"'s economy has risen by 20%."<<std::endl<<std::endl;
    }
    else
    {
        int people = userCountry->getNotEnlisted();
        people = people*1.2;
        userCountry->setNotEnlisted(people);

        std::cout<<userCountry->getName()<<"'s man power has risen by 20%."<<std::endl<<std::endl;
    }

    countries[0]= userCountry;
}

std::string WarPedal::nameGenerator()
{
    bool found = false;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 6);
    int i = dist(gen);

   while(!found)
   {
        if(names[i]!="")
        {
            found== true;
            std::string pick = names[i];
            names[i]="";
            return pick;
        }
        i= dist(gen);
   }

   return "";
}

std::string WarPedal::outPutCountries()
{
    
    std::string output = "";
    for(int x=0; x<8; x++)
    {
        
        output += countryData(countries[x]);
    }

    return output;
}

std::string WarPedal::countryRanks()
{

  for (int step = 0; step < 8-1; step++)
  {
    for (int i = 0; i < 8 - step-1; i++)
    {
      if (countries[i]->getPower()> countries[i + 1]->getPower())
      {
        auto* temp = countries[i];
        countries[i] = countries[i + 1];
        countries[i + 1] = temp;
      }
    }
  }

    std::string out = "";
    out += "1.";
    for(int x=0; x<8; x++)
    {
        out += countries[x]->getName();
        out += "--";
        out += toString(countries[x]->getPower());
        out += "\n";
        out+= "-----------------------------------------------------------------";
        out+="\n";
    }

    return out;
}

std::string toString(int a)
{
    std::stringstream in;
    std::string st;
    in<<a;
    in>>st;
    return st;
}
std::string countryData(Country* ca)
{
    std::string output = "";
    output += ca->getName();
    output += "\n";
    output += "Economy: ";
    output += toString( ca->getEconomy());
    output += "\n";
    output += "Population: ";
    output += toString(ca->getPopulation());
    output += "\n";
    output += "Man Power: ";
    output += toString(ca->getNotEnlisted());
    output += "\n";
    output += "POWER: ";
    output += toString(ca->getPower());
    output += "\n\n";

    return output;
}
void WarPedal::stopPedaling()
{
    
}

// void WarPedal::runGUIEngine()
// {
    
// }

// AllyRegistry WarPedal::getAllyRegistry()
// {
//     return allyRegistry;
// }

// BattleRegistry WarPedal::getBattleRegistry()
// {
//     return battleRegistry;
// }

// void WarPedal::setTest(int data)
// {
//     test = data;
// }

// int WarPedal::getTest()
// {
//     return test;
// }

// void WarPedal::setAllyRegistry(AllyRegistry &ar)
// {
//     this->allyRegistry = ar;
// }

// void WarPedal::setBattleRegistry(BattleRegistry &br)
// {
//     this->battleRegistry = br;
// }

WarPedal& WarPedal::getInstanceWarPedal()
{
    static WarPedal onlyInstance_;
    return onlyInstance_;
}

WarPedal::~WarPedal()
{
    
}


WarPedal::WarPedal()
{
    names = new std::string[7];
    //for now 7 names

    names[0] = "Asgard";
    names[1] = "New London";
    names[2] = "Westeros";
    names[3] = "Rome";
    names[4] = "Hell";
    names[5] = "Musk Mars";
    names[6] = "Wonder Land";
}
