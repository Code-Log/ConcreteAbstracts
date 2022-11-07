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

    enemyRecruits->setGroupSize(armory[0]->getDamage());
    armory[0]->setDurability(armory[0]->getDurability() - 5);
}

void Recruits::addWeapon(AttackWeapon* attackWeapon)
{
    armory.push_back(attackWeapon);
}

Country* Recruits::getCountry()
{
    return country;
}
void Recruits::setCountry(Country* country){
    this->country = country;
}

void Recruits::addVessel(VesselWeapon* vesselWeapon)
{
    vehicles.push_back(vesselWeapon);
}

Recruits::~Recruits()
{
    // for (auto weapon : armory)
    // {
    //     delete weapon;
    // }
    // armory.clear();
    // delete country;

    // for (auto vessel : vehicles)
    // {
    //     delete vessel;
    // }
    // vehicles.clear();
}

std::string Recruits::getMilitaryType()
{
    return militaryType;
}

void Recruits::setMilitaryType(std::string type)
{
    this->militaryType = std::move(type);
}

void Recruits::handle()
{

}

int Recruits::getWeaponDamage() const 
{
    return weaponDamage;
}

void Recruits::setWeaponDamage(int weaponDamage) 
{
    Recruits::weaponDamage = weaponDamage;
}
void Recruits::setName(std::string name)
{
    this->name = name;
}
std::string Recruits::getName(){
    return name;
}