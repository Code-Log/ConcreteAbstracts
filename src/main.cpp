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

    WarEngine::getInstanceWarEngine().setHuman(false);
    WarEngine::getInstanceWarEngine().prePhase1();
    WarEngine::getInstanceWarEngine().phase1();
    WarEngine::getInstanceWarEngine().setAllies();
    // WarEngine::getInstanceWarEngine().partitionRecruits();

    std::cout<<colours::CYAN_UNDERLINED<<"hello world"<<colours::RESET<<std::endl;
    std::cout<<"hey"<<std::endl;
    return 0;

}