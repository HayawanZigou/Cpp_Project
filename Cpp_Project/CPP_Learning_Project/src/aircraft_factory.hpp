#pragma once

#include "aircraft.hpp"
// #include "airport.hpp"
// #include "airport_type.hpp"

#include "GL/texture.hpp"
#include "img/image.hpp"
#include "img/media_path.hpp"


#include <string>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>

class Airport;

class AircraftFactory
{
private:

    const std::string airlines[8] = { "AF", "LH", "EY", "DL", "KL", "BA", "AY", "EY" };
    AircraftType* aircraft_types[NUM_AIRCRAFT_TYPES] {};
    
    //TASK_1 Obj-2 B
    std::vector<std::string> flight_numbers;



public:

        
    std::unique_ptr<Aircraft> create_aircraft(const AircraftType& type, Airport* airport);

    std::unique_ptr<Aircraft> create_random_aircraft(Airport* airport);


    std::string airline(int index);

    // note: textures have to be initialized after initializing glut, so we'll need
    // our own init here
    void init_aircraft_types();
    
};