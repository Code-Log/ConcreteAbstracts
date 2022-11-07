#include <Tanks.h>

int Tanks::getDamage()
{
	return this->damage;
}

int Tanks::getDefense()
{
	return this->defense;
}

std::string Tanks::getName()
{
	return "Tank";
}

int Tanks::getDurability() {
    return this->durability;
}

void Tanks::setDurability(int durability) {
    this->durability = durability;
}
