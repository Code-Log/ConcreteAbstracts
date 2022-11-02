#include <iostream>

#include "Country.h"
//#include "WarTheatre.h"
#include <string>
#include <WarPedal.h>

using namespace std;

int main() {
    

    WarPedal& war = WarPedal::getInstanceWarPedal();
 

    war.startPedaling();

 

    

    return 0;
}