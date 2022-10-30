#include <ExplosiveWeapons.h>

int ExplosiveWeapons::getDamage()
{
	return this->damage;
}

std::string ExplosiveWeapons::getName()
{
	return "Explosive Weapon(s)";
}

int ExplosiveWeapons::getDurability() {
    return this->durability;
}

void ExplosiveWeapons::setDurability(int durability) {
    this->durability = durability;
}


