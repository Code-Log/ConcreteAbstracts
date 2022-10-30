#include <Ships.h>

int Ships::getDamage()
{
	return this->damage;
}

int Ships::getDefense()
{
	return this->defense;
}

std::string Ships::getName()
{
	return "Ship(s)";
}

int Ships::getDurability() {
    return durability;
}

void Ships::setDurability(int durability) {
    this->durability = durability;
}
