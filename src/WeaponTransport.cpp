#include <WeaponTransport.h>
#include <BattleRegistry.h>
#include <vector>
#include <string>
#include <WarEngine.h>


WeaponTransport::WeaponTransport(){
    factory[0] = new NuclearWeaponCreator();
    factory[1] = new ExplosiveWeaponCreator();
    factory[2] = new MeleeWeaponCreator();
    factory[3] = new RangedWeaponCreator();
}
void WeaponTransport::purchase(Recruits* recruits)
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
         weaponName = "Nuclear";
      }
      break;
   case 2:
     if(factory[1]->getPrice()>budget){
         std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
         return;
      }
      else{
         weapon = factory[1]->produce();
         weaponName = "Explosive";
      }
      break;
   case 3:
      if(factory[2]->getPrice()>budget){
         std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
         return;
      }
      else{
         weapon = factory[2]->produce();
         weaponName = "Melee";
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
      }
   default:
      std::cout<<"Option not available..."<<std::endl;
      return;
   }
   std::vector<UnorderedPair<Country*>> countries = WarEngine::getInstanceWarEngine().getBattleRegistry().getRecords(recruits->getCountry());
   int randomCountryIndex = (rand() % countries.size());
   std::cout<<"Transporting"<<weaponName<<"weapon to enemy country: "<<countries[randomCountryIndex].getOther(recruits->getCountry())->getName()<<std::endl;

   recruits->addWeapon(weapon);
}