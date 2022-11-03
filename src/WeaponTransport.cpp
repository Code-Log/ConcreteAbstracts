#include <WeaponTransport.h>
#include <BattleRegistry.h>
#include <vector>
#include <string>
#include <WarEngine.h>
#include <random>

WeaponTransport::WeaponTransport(){
    factory[0] = new NuclearWeaponCreator();
    factory[1] = new ExplosiveWeaponCreator();
    factory[2] = new MeleeWeaponCreator();
    factory[3] = new RangedWeaponCreator();

    factory[0]->setPrice(100);
    factory[1]->setPrice(100);
    factory[2]->setPrice(100);
    factory[3]->setPrice(100);
}

void WeaponTransport::purchase(Recruits *recruits, int purchaseType)
{

    int budget = recruits->getCountry()->getEconomy();
    AttackWeapon* weapon;
    std::string weaponName;

    switch(purchaseType) {
        case 0:
            if(factory[0]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[0]->produce();
            weaponName = "Nuclear";
            }
            break;
        case 1:
            if(factory[1]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[1]->produce();
            weaponName = "Explosive";
            }
            break;
        case 2:
            if(factory[2]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[2]->produce();
            weaponName = "Melee";
            }
            break;
        case 3:
            if(factory[3]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[3]->produce();
            weaponName = "Ranged";
            }
        default:
            std::cout<<"Option not available..."<<std::endl;
            return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<UnorderedPair<Country*>> countries = WarEngine::getInstanceWarEngine().getBattleRegistry().getRecords(recruits->getCountry());
    // std::cout<<"size"<<countries.size()<<std::endl;
    std::uniform_int_distribution<> dist(0, (int)countries.size() - 1);
    int randomCountryIndex = dist(gen);
    // std::cout<<countries[randomCountryIndex].first->getName();
    std::cout<<"Transporting"<<weaponName<<"weapon to enemy country: "<<countries[randomCountryIndex].getOther(recruits->getCountry())->getName()<<std::endl;

    recruits->addWeapon(weapon);
}