#include "aircraft_manager.hpp"

void AircraftManager::add(std::unique_ptr<Aircraft> aircraft)
{
    aircrafts.emplace_back(std::move(aircraft));
}

// TASK_1 C
bool AircraftManager::move()
{
    for(auto& aircraft : aircrafts){
        aircraft->move();
    }
    return true;
}

std::unique_ptr<Aircraft> AircraftManager::create_random_aircraft(Airport* airport)
{   
    return aircraft_factory.create_random_aircraft(airport);
}

void AircraftManager::init_aircraft_types()
{
    aircraft_factory.init_aircraft_types();
}