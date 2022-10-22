#ifndef WARTHEATRES_H
#define WARTHEATRES_H

#include <string>

class WarTheatre
{
private:
    int damage;
    std::string location;

public:
    explicit WarTheatre(std::string location);
    virtual ~WarTheatre();

    std::string getLocation();

    virtual void add(WarTheatre* trap)=0;

    int getDamage();
    void setDamage(int damage);
    virtual int damageTotal()=0;

    virtual int penalty(int* recruitNumber) = 0;
};

#endif