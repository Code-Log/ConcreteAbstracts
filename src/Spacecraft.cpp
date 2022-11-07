#include <Spacecraft.h>

int Spacecraft::getDamage()
{
	return this->damage;
}

int Spacecraft::getDefense()
{
	return this->defense;
}

std::string Spacecraft::getName()
{
	return "Spacecraft";
}

int Spacecraft::getDurability() {
    return this->durability;
}

void Spacecraft::setDurability(int durability) {
    this->durability = durability;
}
