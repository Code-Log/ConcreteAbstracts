#include <util/ListSelectionPrompt.h>
#include <WarEngine.h>
#include <iostream>
#include <util/colours.h>

int main() {
    // WarEngine::getInstanceWarEngine().selectCountry(false);
    // for(auto c : WarEngine::getInstanceWarEngine().countries){
    //     if(c == nullptr){
    //         std::cout<<"mhhh"<<std::endl;
    //     }
    //     else
    //         std::cout<<c->getName()<<std::endl;
    // }
    // WarEngine::getInstanceWarEngine().selectPoliticalRegime(false);
    WarEngine::getInstanceWarEngine().setHuman(true);
    WarEngine::getInstanceWarEngine().prePhase1();
    WarEngine::getInstanceWarEngine().phase1();
    WarEngine::getInstanceWarEngine().setAllies();
    WarEngine::getInstanceWarEngine().partitionRecruits();
    WarEngine::getInstanceWarEngine().buyAndDistributeWeapons();
    WarEngine::getInstanceWarEngine().destributeRecruiteToWarTheatres();
    // WarEngine::getInstanceWarEngine().setWarTheatres();
    // WarEngine::getInstanceWarEngine().phase3();
    // WarEngine::getInstanceWarEngine().setAllies().buyAndDistributeWeapons();


    return 0;
}