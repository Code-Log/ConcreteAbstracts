#include <AttackVessel.h>
#include <Country.h>

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

    int priceOfWeapon = 30;
    if(recruits->getCountry()->getEconomy() > priceOfWeapon){

    }
    else{

    }
    /// \todo: Implement AttackVessel::purchase
}
