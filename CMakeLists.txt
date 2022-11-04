cmake_minimum_required(VERSION 3.12)
project(ConcreteAbstracts)

enable_testing()

# ADD CPP EXECUTABLES HERE
add_executable(simulator 
                src/main.cpp 
                src/Country.cpp
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
                src/ArmoryFacade.cpp
                include/WarTheatre.h
                src/WarTheatre.cpp
                include/Trap.h
                src/Trap.cpp
                include/BattleGround.h
                src/BattleGround.cpp
                include/Air.h
                src/Air.cpp
                include/Land.h
                src/Land.cpp
                include/Sea.h
                src/Sea.cpp
                include/Space.h
                src/Space.cpp
                include/Mines.h
                src/Mines.cpp
                include/Barricades.h
                src/Barricades.cpp
                include/Trenches.h
                src/Trenches.cpp
                include/SpaceMagnets.h
                src/SpaceMagnets.cpp
                include/CountryHistory.h
                include/CountryMemento.h
                src/CountryHistory.cpp
                src/CountryMemento.cpp
                include/AttackWeapon.h
                include/AttackWeaponCreator.h
                include/ExplosiveWeaponCreator.h
                include/ExplosiveWeapons.h
                include/JetCreator.h
                include/Jets.h
                include/MeleeWeaponCreator.h
                include/MeleeWeapons.h
                include/NuclearWeaponCreator.h
                include/NuclearWeapons.h
                include/RangedWeaponCreator.h
                include/RangedWeapons.h
                include/ShipCreator.h
                include/Ships.h
                include/Spacecraft.h
                include/SpacecraftCreator.h
                include/TankCreator.h
                include/Tanks.h
                include/VesselWeapon.h
                include/VesselWeaponCreator.h
                include/WarEngine.h
                src/AttackWeaponCreator.cpp
                src/ExplosiveWeaponCreator.cpp
                src/ExplosiveWeapons.cpp
                src/JetCreator.cpp
                src/Jets.cpp
                src/MeleeWeaponCreator.cpp
                src/MeleeWeapons.cpp
                src/NuclearWeaponCreator.cpp
                src/NuclearWeapons.cpp
                src/RangedWeaponCreator.cpp
                src/RangedWeapons.cpp
                src/ShipCreator.cpp
                src/Ships.cpp
                src/Spacecraft.cpp
                src/SpacecraftCreator.cpp
                src/TankCreator.cpp
                src/Tanks.cpp
                src/VesselWeaponCreator.cpp
                src/WarEngine.cpp
        include/RecruitIterator.h include/Iterator.h src/RecruitIterator.cpp
        include/Recruits.h include/util/ListSelectionPrompt.h src/ListSelectionPrompt.cpp 
                include/util/enums.h

        )
        
file(GLOB CPP_FILES src/*.cpp)
list(FILTER CPP_FILES EXCLUDE REGEX src/main.cpp)
add_executable(testExec testSrc/testMain.cpp ${CPP_FILES})

# To add a test, follow the following format.
# add_test(<test_name> <test_executable> <program arguments>)
add_test(testCountry testExec testCountry)
add_test(testRecruits testExec testRecruits)
add_test(testRegistry testExec testRegistry)
add_test(testTransport testExec testTransport)
add_test(testTheatreCountryPeopleCombo testExec testTheatreCountryPeopleCombo)
add_test(testWarEngine testExec testWarEngine)
add_test(testMemento testExec testMemento)


target_include_directories(simulator PUBLIC include)
target_include_directories(testExec PUBLIC include)