#include <WeaponTransport.h>
#include <BattleRegistry.h>
#include <vector>
#include <string>
#include <WarPadel.h>
#include <random>

int randomNumGenerator(int, int );

WeaponTransport::WeaponTransport(){
    factory[0] = new NuclearWeaponCreator();
    factory[1] = new ExplosiveWeaponCreator();
    factory[2] = new MeleeWeaponCreator();
    factory[3] = new RangedWeaponCreator();

    factory[0]->setPrice(500);
    factory[1]->setPrice(200);
    factory[2]->setPrice(150);
    factory[3]->setPrice(90);
}
void WeaponTransport::purchase(Recruits* recruits)
{
    
    //  std::string question =  std::string("What kind of weapon do you wish to produce?\n")
    //                  + "1. Nuclear\n"
    //                  + "2. Explosive\n"
    //                  + "3. Melee\n"
    //                  + "4. Ranged\n";
    // std::cout<<question;
    // int answer;
    // std::cin>>answer;

    int answer = randomNumGenerator(1,4);
    int budget = recruits->getCountry()->getEconomy();
    AttackWeapon* weapon;
    std::string weaponName;

    switch(answer) {
        case 1:
            if(factory[0]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[0]->produce();
            recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[0]->getPrice());
            weaponName = "Nuclear";

            std::cout<<"Purchasing Nuclear weapons"<<std::endl;
            }
            break;
        case 2:
            if(factory[1]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[1]->produce();
             recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[1]->getPrice());
            weaponName = "Explosive";
            std::cout<<"Purchasing Explosive weapons"<<std::endl;
            }
            break;
        case 3:
            if(factory[2]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[2]->produce();
             recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[2]->getPrice());
            weaponName = "Melee";
            std::cout<<"Purchasing Melee weapons"<<std::endl;
            }
            break;
        case 4:
            if(factory[3]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[3]->produce();
            weaponName = "Ranged";
             recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[3]->getPrice());
            std::cout<<"Purchasing Ranged weapons"<<std::endl;
            }
            break;
        default:
            std::cout<<"Option not available..."<<std::endl;
            return;
    }

    // std::random_device rd;
    // std::mt19937 gen(rd());


    // std::vector<UnorderedPair<Country*>> countries = WarPedal::getInstanceWarPedal().getBattleRegistry()->getRecords(recruits->getCountry());

    // // std::cout<<"size"<<countries.size()<<std::endl;
    // std::uniform_int_distribution<> dist(0, (int)countries.size() - 1);
    // int randomCountryIndex = dist(gen);
    // // std::cout<<countries[randomCountryIndex].first->getName();
    // std::cout<<"Transporting"<<weaponName<<"weapon to enemy country: "<<countries[randomCountryIndex].getOther(recruits->getCountry())->getName()<<std::endl;

    recruits->addWeapon(weapon);
}

void WeaponTransport::purchaseInput(Recruits* recruits)
{
    
     std::string question =  std::string("What kind of weapon do you wish to produce?\n")
                     + "1. Nuclear\n"
                     + "2. Explosive\n"
                     + "3. Melee\n"
                     + "4. Ranged\n";
    std::cout<<question;
    int answer;
    std::cin>>answer;

    int budget = recruits->getCountry()->getEconomy();
    AttackWeapon* weapon;
    std::string weaponName;

    switch(answer) {
        case 1:
            if(factory[0]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[0]->produce();
            recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[0]->getPrice());
            weaponName = "Nuclear";

            std::cout<<"Purchasing Nuclear weapons"<<std::endl;
            }
            break;
        case 2:
            if(factory[1]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[1]->produce();
             recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[1]->getPrice());
            weaponName = "Explosive";
            std::cout<<"Purchasing Explosive weapons"<<std::endl;
            }
            break;
        case 3:
            if(factory[2]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[2]->produce();
             recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[2]->getPrice());
            weaponName = "Melee";
            std::cout<<"Purchasing Melee weapons"<<std::endl;
            }
            break;
        case 4:
            if(factory[3]->getPrice()>budget){
            std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
            return;
            }
            else{
            weapon = factory[3]->produce();
            weaponName = "Ranged";
             recruits->getCountry()->setEconomy(recruits->getCountry()->getEconomy()- factory[3]->getPrice());
            std::cout<<"Purchasing Ranged weapons"<<std::endl;
            }
            break;
        default:
            std::cout<<"Option not available..."<<std::endl;
            return;
    }

    // std::random_device rd;
    // std::mt19937 gen(rd());


    // std::vector<UnorderedPair<Country*>> countries = WarPedal::getInstanceWarPedal().getBattleRegistry()->getRecords(recruits->getCountry());

    // // std::cout<<"size"<<countries.size()<<std::endl;
    // std::uniform_int_distribution<> dist(0, (int)countries.size() - 1);
    // int randomCountryIndex = dist(gen);
    // // std::cout<<countries[randomCountryIndex].first->getName();
    // std::cout<<"Transporting"<<weaponName<<"weapon to enemy country: "<<countries[randomCountryIndex].getOther(recruits->getCountry())->getName()<<std::endl;

    recruits->addWeapon(weapon);
}


