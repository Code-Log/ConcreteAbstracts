// #include <AttackVessel.h>
// #include <Country.h>
#include <BattleRegistry.h>
#include <vector>
// #include <VesselWeapon.h>
#include <string>
#include <WarEngine.h>

AttackVessel::AttackVessel()
{
    factory[0] = new TankCreator();
    factory[1] = new ShipCreator();
    factory[2] = new JetCreator();
    factory[3] = new SpacecraftCreator();
}

void AttackVessel::purchase(Recruits* recruits)
{

   std::string question =  std::string("What kind of Vessel do you wish to produce?\n")
                     + "1. Tank\n"
                     + "2. Ship\n"
                     + "3. Jet\n"
                     + "4. Spacecraft\n";
   std::cout<<question;
   int answer;
   std::cin>>answer;
   std::cout<<answer;
   // int budget = recruits->getCountry()->getEconomy();
   // VesselWeapon* vessel;
   // std::string vesselName;
   // switch(answer) {
   // case 1:
   //    if(factory[0]->getPrice()>budget){
   //       std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
   //       return;
   //    }
   //    else{
   //       vessel = factory[0]->produce();
   //       vesselName = "Tank";
   //    }
   //    break;
   // case 2:
   //   if(factory[1]->getPrice()>budget){
   //       std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
   //       return;
   //    }
   //    else{
   //       vessel = factory[1]->produce();
   //       vesselName = "Ship";
   //    }
   //    break;
   // case 3:
   //    if(factory[2]->getPrice()>budget){
   //       std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
   //       return;
   //    }
   //    else{
   //       vessel = factory[2]->produce();
   //       vesselName = "Jet";
   //    }
   //    break;
   // case 4:
   //    if(factory[3]->getPrice()>budget){
   //       std::cout<<"sorry you do not have the funds neccesary to continue with the purchase."<<std::endl;
   //       return;
   //    }
   //    else{
   //       vessel = factory[3]->produce();
   //       vesselName = "Spacecraft";
   //    }
   // default:
   //    std::cout<<"Option not available..."<<std::endl;
   //    return;
   // }
   // std::vector<UnorderedPair<Country*>> countries = WarEngine::getInstanceWarEngine().getBattleRegistry().getRecords(recruits->getCountry());
   // int randomCountryIndex = (rand() % countries.size());
   // std::cout<<"Transporting "<<vesselName<<" vessel to enemy country: "<<countries[randomCountryIndex].getOther(recruits->getCountry())->getName()<<std::endl;

   // recruits->addVessel(vessel);
}
