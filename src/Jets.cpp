#include <Jets.h>

int Jets::getDamage()
{
	return this->damage;
}

int Jets::getDefense()
{
	return this->defense;
}

std::string Jets::getName()
{
	return "Jet";
}

int Jets::getDurability()
{
    return this->durability;
}

void Jets::setDurability(int durability) {
    this->durability = durability;
}
