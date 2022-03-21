#pragma once

#include "GL/dynamic_object.hpp"
#include "aircraft.hpp"
#include "aircraft_factory.hpp"

#include <memory>
#include <vector>
#include <algorithm>

class AircraftManager : public GL::DynamicObject
{
private:
    std::vector<std::unique_ptr<Aircraft>> aircrafts; // TASK_1 C
    
    AircraftFactory aircraft_factory;

public:
    
    AircraftManager()=default;
    ~AircraftManager()=default;

    void add(std::unique_ptr<Aircraft> aircraft); // TASK_1 C

    bool move() override; // TASK_1 C
    
    std::unique_ptr<Aircraft> create_random_aircraft(Airport* airport);

    void init_aircraft_types();

    std::string airline(int index);
    
    void number_aircraft_by_airline(const std::string& airline);

    int get_required_fuel() const;

};