#ifndef __RECRUITS_H__
#define __RECRUITS_H__

#include <string>
#include <vector>

#include <People.h>
#include <AttackWeapon.h>
#include <VesselWeapon.h>

class Recruits: public People{
private:
    bool isEnlisted;
    std::string militaryType;
    int weaponDamage;
    // std::vector<AttackWeapon*> armory;
    // std::vector<VesselWeapon*> vehicles;

public:
    Recruits(/* args */);
    void handle();
    virtual ~Recruits();
};


#endif // __RECRUITS_H__