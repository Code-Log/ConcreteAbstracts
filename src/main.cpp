#include <iostream>

#include "Country.h"
//#include "WarTheatre.h"
#include <string>
#include <WarPadel.h>

using namespace std;

int main() {
    

    WarPadel& war = WarPadel::getInstanceWarPadel();
 

    war.startPedaling();

    

    return 0;
}