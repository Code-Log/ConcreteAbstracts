#include <iostream>

#include "Country.h"
//#include "WarTheatre.h"
#include <string>

using namespace std;

int main() {
    // Country* x = new Country("jack");

    // Country* y = x->cloneCountry();

    // cout << x->getName() << endl;   

    // /
    // delete y;
    // cout << "hello world" << endl;

    Country* Germany = new Country("Germany");
    cout<<"Name: "<< Germany->getName()<<endl;
    
    cout<<"Population: "<<Germany->getPopulation()<<endl;

    cout<<"Before recruits: "<<Germany->getNotEnlisted()<<endl;
    Germany->recruitSoldiers(50);
    Germany->recruitMarines(50);
   
    cout<<"After recruits: "<<Germany->getNotEnlisted()<<endl;
    cout<<"Recruit a lot more!!"<<endl;
    Germany->recruitGuardians(Germany->getNotEnlisted()+1);

    
    Germany->addWarFront("Air");
    Germany->addWarFront("Land");

    delete Germany;

    return 0;
}