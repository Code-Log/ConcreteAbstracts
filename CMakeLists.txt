cmake_minimum_required(VERSION 3.12)
project(ConcreteAbstracts)

enable_testing()

# ADD CPP EXECUTABLES HERE
add_executable(simulator 
                src/main.cpp 
                src/Country.cpp 
                src/AbstractCountry.cpp
                include/AbstractCountry.h
                include/Country.h
                include/Registry.h
                include/AllyRegistry.h
                src/AllyRegistry.cpp
                include/BattleRegistry.h
                src/BattleRegistry.cpp
                include/util/UnorderedPair.hpp
                src/Citizens.cpp
                src/Guardian.cpp
                src/Marine.cpp
                src/Medic.cpp
                src/People.cpp
                src/Pilot.cpp
                src/RecruiterContext.cpp
                src/Recruits.cpp
                src/Refugee.cpp
                src/Soldier.cpp
                include/TransportContext.h
                include/Transport.h
                src/TransportContext.cpp
                include/WeaponTransport.h
                src/WeaponTransport.cpp
                include/AttackVessel.h
                src/AttackVessel.cpp
                include/SuppliesTransport.h
                src/SuppliesTransport.cpp
                include/ArmoryFacade.h
                src/ArmoryFacade.cpp)

file(GLOB CPP_FILES src/*.cpp)
list(FILTER CPP_FILES EXCLUDE REGEX src/main.cpp)
add_executable(testExec testSrc/testMain.cpp ${CPP_FILES})

# To add a test, follow the following format.
# add_test(<test_name> <test_executable> <program arguments>)
add_test(testCountry testExec testCountry)
add_test(testRecruits testExec testRecruits)
add_test(testRegistry testExec testRegistry)
add_test(testTransport testExec testTransport)

target_include_directories(simulator PUBLIC include)
target_include_directories(testExec PUBLIC include)
