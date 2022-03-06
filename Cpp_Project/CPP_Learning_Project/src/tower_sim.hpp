#pragma once

#include "aircraft_manager.hpp"
#include "aircraft_factory.hpp"

class Airport;
struct AircraftType;

class TowerSimulation
{
private:
    bool help        = false;
    Airport* airport = nullptr;
    
    AircraftManager aircraft_manager;  // TASK_1 C
    AircraftFactory aircraft_factory;  //TASK_1 Obj-2 A
    
    TowerSimulation(const TowerSimulation&) = delete;
    TowerSimulation& operator=(const TowerSimulation&) = delete;

    //TASK_1 Obj-2 A: plus besoin de ces fonctions, creation des avions dans aircraft_factory.hpp.
    // void create_aircraft(const AircraftType& type) /*const*/;
    // void create_random_aircraft() /*const*/;

    void create_keystrokes() /*const*/;
    void display_help() const;

    void init_airport();

public:
    TowerSimulation(int argc, char** argv);
    ~TowerSimulation();

    void launch();
};
