#include <Recruits.h>
#include <Country.h>

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
    delete country;

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