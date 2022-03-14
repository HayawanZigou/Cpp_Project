#include "tower_sim.hpp"

#include "GL/opengl_interface.hpp"
#include "aircraft.hpp"
#include "airport.hpp"
#include "config.hpp"
#include "img/image.hpp"
#include "img/media_path.hpp"

#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std::string_literals;

//TASK_1 Obj-2 A: présent dans aircraft_factory.hpp.
//const std::string airlines[8] = { "AF", "LH", "EY", "DL", "KL", "BA", "AY", "EY" };

TowerSimulation::TowerSimulation(int argc, char** argv) :
    help { (argc > 1) && (std::string { argv[1] } == "--help"s || std::string { argv[1] } == "-h"s) }
{
    MediaPath::initialize(argv[0]);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    GL::init_gl(argc, argv, "Airport Tower Simulation");

    create_keystrokes();
    // TASK_1 C
    // On doit ajouter le aircraft_manager à la move_queue afin que la fonction timer 
    // appelle bien sa fonction move() à chaque frame.
    GL::move_queue.emplace(&aircraft_manager);

}

TowerSimulation::~TowerSimulation()
{
    delete airport;
}

//TASK_1 Obj-2 A
// void TowerSimulation::create_aircraft(const AircraftType& type) /*const*/
// {
//     assert(airport); // make sure the airport is initialized before creating aircraft

//     const std::string flight_number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
//     const float angle       = (rand() % 1000) * 2 * 3.141592f / 1000.f; // random angle between 0 and 2pi
//     const Point3D start     = Point3D { std::sin(angle), std::cos(angle), 0 } * 3 + Point3D { 0, 0, 2 };
//     const Point3D direction = (-start).normalize();

//     Aircraft* aircraft = new Aircraft { type, flight_number, start, direction, airport->get_tower() };
//     GL::Displayable::display_queue.emplace_back(aircraft);
//     aircraft_manager.add(std::unique_ptr<Aircraft>(aircraft));//TASK_1 C: On ajoute l'avion dans le manager des avions.
//     //GL::move_queue.emplace(aircraft);
// }

// void TowerSimulation::create_random_aircraft() /*const*/
// {
//     create_aircraft(*(aircraft_types[rand() % 3]));
// }

void TowerSimulation::create_keystrokes() /*const*/
{
    GL::keystrokes.emplace('x', []() { GL::exit_loop(); });
    GL::keystrokes.emplace('q', []() { GL::exit_loop(); });
    GL::keystrokes.emplace('c', [this]() { aircraft_manager.add(aircraft_manager.create_random_aircraft(airport));}); //TASK_1 Obj-2 A
    GL::keystrokes.emplace('+', []() { GL::change_zoom(0.95f); });
    GL::keystrokes.emplace('-', []() { GL::change_zoom(1.05f); });
    GL::keystrokes.emplace('f', []() { GL::toggle_fullscreen(); });
    GL::keystrokes.emplace('a', []() { GL::faster(); });
    GL::keystrokes.emplace('s', []() { GL::slower(); });
    GL::keystrokes.emplace('p', []() { GL::pause(); });

    // TASK_2 Obj-1 B.2
    for (int i = 0; i < 8; i++)
    {
        GL::keystrokes.emplace(i+'0',[this, i](){aircraft_manager.number_aircraft_by_airline(aircraft_manager.airline(i));});
    }
}

void TowerSimulation::display_help() const
{
    std::cout << "This is an airport tower simulator" << std::endl
              << "the following keysstrokes have meaning:" << std::endl;

    /*TASK_2 Obj-1 A*/
    for (const auto& [key, value]/*ks_pair*/ : GL::keystrokes)
    {
        std::cout << key /*ks_pair.first*/ << ' ';
    }

    std::cout << std::endl;
}

void TowerSimulation::init_airport()
{
    airport = new Airport { one_lane_airport, Point3D { 0, 0, 0 },
                            new img::Image { one_lane_airport_sprite_path.get_full_path() } };

    GL::Displayable::display_queue.emplace_back(airport);
    GL::move_queue.emplace(airport);
}

void TowerSimulation::launch()
{
    if (help)
    {
        display_help();
        return;
    }

    init_airport();
    //init_aircraft_types();
    //TASK_1 Obj-2 A
    aircraft_manager.init_aircraft_types();

    GL::loop();
}
