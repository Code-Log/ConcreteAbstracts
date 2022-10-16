#include <AbstractCountry.h>
#include <cstring>
#include <Country.h>

int testCountry()
{
    int result = 0;
    std::string name = "TestName";
    auto* country = new Country(name);
    if (country->getName() != name)
        result = -1;

    delete country;
    return result;
}

// Write your testing functions like this
//int myTest()
//{
//    // Testing code goes here
//}

int main(int argc, const char   ** argv) {
    if (std::strcmp(argv[0], "testCountry") == 0)
        return testCountry();

//    To add a new test
//    if (std::strcmp(argv[0], "myTest") == 0)
//        return myTest();
}