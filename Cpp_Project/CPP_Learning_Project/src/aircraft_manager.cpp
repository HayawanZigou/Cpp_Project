#include "aircraft_manager.hpp"

void AircraftManager::add(std::unique_ptr<Aircraft> aircraft)
{
    aircrafts.emplace_back(std::move(aircraft));
}

// TASK_1 C
bool AircraftManager::move()
{
    // TASK_2 Obj-1 B.1
    aircrafts.erase(std::remove_if(aircrafts.begin(), aircrafts.end(), [](auto& aircraft){
        return !aircraft->move();
    }), aircrafts.end());
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

std::string AircraftManager::airline(int index){
    return aircraft_factory.airline(index);
}

// TASK_2 Obj-1 B.2
void AircraftManager::number_aircraft_by_airline(const std::string& airline){
    const auto counter = std::count_if(aircrafts.begin(), aircrafts.end(),
    [airline](const auto& aircraft){
        return aircraft->get_flight_num().substr(0,2).compare(airline) == 0;
    });
    std::cout << "number of " << airline << ": "<< counter << std::endl;
}