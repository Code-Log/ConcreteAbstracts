#include <NuclearWeapons.h>

int NuclearWeapons::getDamage()
{
	return this->damage;
}

std::string NuclearWeapons::getName()
{
	return "Nuclear Weapon(s)";
}

int NuclearWeapons::getDurability() {
    return this->durability;
}

void NuclearWeapons::setDurability(int durability) {

}
