#include <util/ListSelectionPrompt.h>
#include <WarEngine.h>
#include <iostream>
#include <util/colours.h>

int main() {
    ListSelectionPrompt prompt = {"Real", "Design"};
    int selection = prompt.getSelectionIndex("Select in which mode you wish to run the simulation");
    if(selection == 0){
        WarEngine::getInstanceWarEngine().run(false);
    }
    else{
       WarEngine::getInstanceWarEngine().run(true); 
    }
    return 0;
}