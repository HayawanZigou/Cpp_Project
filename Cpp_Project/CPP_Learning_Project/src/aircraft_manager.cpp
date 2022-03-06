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