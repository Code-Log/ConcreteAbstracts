#include <MeleeWeapons.h>

int MeleeWeapons::getDamage()
{
	return this->damage;
}

std::string MeleeWeapons::getName()
{
	return "Melee Weapon(s)";
}

int MeleeWeapons::getDurability() {
    return this->durability;
}

void MeleeWeapons::setDurability(int durability) {
    this->durability = durability;
}
