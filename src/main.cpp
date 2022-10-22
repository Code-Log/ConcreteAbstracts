#include <iostream>
#include "ExplosiveWeaponCreator.h"
#include "AttackWeapon.h"

/*
#include "Jaguar.h"
#include "Gorilla.h"
#include "Cannibal.h"
#include "forceMember.h"
#include "SnakeFactory.h"
#include "JaguarFactory.h"
#include "GorillaFactory.h"
#include "CannibalFactory.h"
#include "Squad.h"
#include "Store.h"
//#include <random>*/

int main()
{
    ExplosiveWeaponCreator ExplosiveWeaponFactory;
    AttackWeapon *myAttackWeapon = ExplosiveWeaponFactory.produce();


    return 0;
}