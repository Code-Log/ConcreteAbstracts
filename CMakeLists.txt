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
                src/Air.cpp
                include/Air.h
                src/Land.cpp
                include/Land.h
                src/Sea.cpp
                include/Sea.h
                src/Space.cpp
                include/Space.h
                src/Mines.cpp
                include/Mines.h
                src/SpaceMagnets.cpp
                include/SpaceMagnets.h
                src/Trenches.cpp
                include/Trenches.h
                src/Barricades.cpp
                include/Barricades.h
                src/Traps.cpp
                include/Traps.h
                src/BattleGround.cpp
                include/BattleGround.h
                src/WarTheatre.cpp
                include/WarTheatre.h)

file(GLOB CPP_FILES src/*.cpp)
list(FILTER CPP_FILES EXCLUDE REGEX src/main.cpp)
add_executable(testExec testSrc/testMain.cpp ${CPP_FILES})

# To add a test, follow the following format.
# add_test(<test_name> <test_executable> <program arguments>)
add_test(testCountry testExec testCountry)
add_test(testRecruits testExec testRecruits)
add_test(testRegistry testExec testRegistry)
add_test(testTransport testExec testTransport)
add_test(testWarTheatre testExec warTheatreTest)

target_include_directories(simulator PUBLIC include)
target_include_directories(testExec PUBLIC include)
