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