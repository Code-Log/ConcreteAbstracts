#include <util/ListSelectionPrompt.h>
#include <WarEngine.h>
#include <iostream>

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
    WarEngine::getInstanceWarEngine().prePhase1(true);
    WarEngine::getInstanceWarEngine().phase1(true);
    WarEngine::getInstanceWarEngine().setAllies(true);
    return 0;

}