#include <iostream>
#include "include/Country.h"
#include "include/AbstractCountry.h"
using namespace std;

int main() {
    AbstractCountry* x = new Country("jack");

    AbstractCountry* y = x->cloneCountry(); 

    cout << x->getName() << endl;   
    delete y;
    cout << "hello world" << endl;
    return 0;
}
