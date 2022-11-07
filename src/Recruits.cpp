#include <Recruits.h>
#include <Country.h>

#include <utility>

Recruits::Recruits()
{
    
}

void Recruits::fireWeapon(Recruits* enemyRecruits)
{
    if(armory.empty())
    {
        /// \todo PRINT ARMORY IS EMPTY
        return;
    }

    if(armory[0]->getDurability() <= 0)
    {
        delete armory[0];
        armory.erase(armory.begin());

        if(armory.empty())
        {
            /// \todo PRINT ARMORY JUST RAN OUT OF WEAPONS
            return;
        }
    }

    std::cout<<"+++++"<<this->getCountry()->getName()<<" recruits firing at "<<enemyRecruits->getCountry()->getName()<<" men+++++"<<std::endl;
    enemyRecruits->setGroupSize(enemyRecruits->getGroupSize()- armory[0]->getDamage());
    armory[0]->setDurability(armory[0]->getDurability() - 5);
}

bool Recruits::amoryEmpty()
{
    if(armory.empty())
    {
        return true;
    }

    return false;
}

void Recruits::addWeapon(AttackWeapon* attackWeapon)
{
    armory.push_back(attackWeapon);
}

void Recruits::weaponLoss(Recruits* enemy)
{
    AttackWeapon* weapon;
    for(int x=0; x<armory.size(); x++)
    {
        weapon = armory.back();
        armory.pop_back();
        enemy->addWeapon(weapon);
    }

    VesselWeapon* vess ;
    for(int x=0; x<vehicles.size(); x++)
    {
        vess = vehicles.back();
        vehicles.pop_back();
        enemy->addVessel(vess);
    }
}

int Recruits::getDefense(const std::string& type)
{
    int count=0;
    for(int x=0; x< vehicles.size(); x++)
    {
        if(vehicles[x]->getName() == type)
        {
            count+= vehicles[x]->getDamage();
            vehicles[x]->setDurability(vehicles[x]->getDurability() - 10);
        }
    }

    return count;
}


void Recruits::addVessel(VesselWeapon* vesselWeapon)
{
    vehicles.push_back(vesselWeapon);
}

Recruits::~Recruits()
{
    for (AttackWeapon* weapon : armory)
    {
        delete weapon;
    }
    armory.clear();
    //delete country;

    for (VesselWeapon* vessel : vehicles)
    {
        delete vessel;
    }
    vehicles.clear();
}

std::string Recruits::getMilitaryType()
{
    return militaryType;
}

void Recruits::setMilitaryType(std::string type)
{
    this->militaryType = type;
}

void Recruits::handle()
{

}

int Recruits::getWeaponDamage() const {
    return weaponDamage;
}

void Recruits::setWeaponDamage(int weaponDamage) {
    Recruits::weaponDamage = weaponDamage;
}
