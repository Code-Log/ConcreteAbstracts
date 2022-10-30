#include <WarTheatre.h>
#include <random>
#include <utility>

WarTheatre::WarTheatre(std::string location)
{
    this->location = std::move(location);
    damage=0;
}

WarTheatre::~WarTheatre() = default;

void WarTheatre::setDamage(int damage)
{
    this->damage = damage;
}

int WarTheatre::getDamage() const
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, damage);

    int damageLevel = dist(gen);
    return damageLevel;
}

std::string WarTheatre::getLocation()
{
    return location;
}