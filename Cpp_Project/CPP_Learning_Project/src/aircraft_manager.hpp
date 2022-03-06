#pragma once

#include "GL/dynamic_object.hpp"
#include "aircraft.hpp"

#include <memory>
#include <vector>
#include <algorithm>

class AircraftManager : public GL::DynamicObject
{
private:
    std::vector<std::unique_ptr<Aircraft>> aircrafts; // TASK_1 C

public:
    
    AircraftManager()=default;
    ~AircraftManager()=default;

    void add(std::unique_ptr<Aircraft> aircraft); // TASK_1 C

    bool move() override; // TASK_1 C

};