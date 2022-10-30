#include <RangedWeapons.h>

int RangedWeapons::getDamage()
{
	return this->damage;
}

std::string RangedWeapons::getName()
{
	return "Ranged Weapon(s)";
}

int RangedWeapons::getDurability() {
    return this->durability;
}

void RangedWeapons::setDurability(int durability) {
    this->durability = durability;
}
