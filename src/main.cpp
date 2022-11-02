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

    auto* Germany = new Country("Germany");
    cout<<"Name: "<< Germany->getName()<<endl;
    
    cout<<"Population: "<<Germany->getPopulation()<<endl;

    cout<<"Before recruits: "<<Germany->getNotEnlisted()<<endl;
    Germany->recruitSoldiers(50);
    Germany->recruitMarines(50);
   
    cout<<"After recruits: "<<Germany->getNotEnlisted()<<endl;
    cout<<"Recruit a lot more!!"<<endl;
    Germany->recruitGuardians(Germany->getNotEnlisted()+1);

    cout<<Germany->getWarFront("Air")<<endl;
    Germany->addWarFront("Air");
    cout<<Germany->getWarFront("Air")<<endl;
    Germany->removeFront("Air");
    cout<<Germany->getWarFront("Air")<<endl;

    Germany->addWarFront("Land");
    Germany->addWarFront("Land");

    Germany->setTrap("Land", "Mines");
    cout<<Germany->warFrontDanger("Air")<<endl;
    cout<<Germany->warFrontDanger("Land")<<endl;

    Germany->setTrap("Land", "Barricades");

    cout<<Germany->warFrontDanger("Land")<<endl;

    Germany->addWarFront("Space");
    Germany->setTrap("Space", "Trenches");
    cout<<Germany->warFrontDanger("Space")<<endl;
    Germany->setTrap("Space", "SpaceMagnets");
    cout<<Germany->warFrontDanger("Space")<<endl;





    

    delete Germany;

    return 0;
}