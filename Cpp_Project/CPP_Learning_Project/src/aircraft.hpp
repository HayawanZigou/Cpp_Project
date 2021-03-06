#pragma once

#include "GL/displayable.hpp"
#include "aircraft_types.hpp"
#include "config.hpp"
#include "geometry.hpp"
#include "tower.hpp"
#include "waypoint.hpp"

#include <string>
#include <string_view>

class Aircraft : public GL::Displayable, public GL::DynamicObject
{
private:
    const AircraftType& type;
    const std::string flight_number;
    Point3D pos, speed; // note: the speed should always be normalized to length 'speed'
    WaypointQueue waypoints = {};
    Tower& control;
    bool landing_gear_deployed = false; // is the landing gear deployed?
    bool is_at_terminal        = false;
    
    int fuel; //TASK_2 Obj-2 A

    // TASK-0 C-3
    // L'endroit le plus approprié pour retirer l'avion, c'est lorsque :
    // 1. l'attérissage a déjà eu lieu => on ajoute un attribut
    // 2. l'avion a terminé sa course de décollage => waypoints.empty()
    bool service_done = false;

    // turn the aircraft to arrive at the next waypoint
    // try to facilitate reaching the waypoint after the next by facing the
    // right way to this end, we try to face the point Z on the line spanned by
    // the next two waypoints such that Z's distance to the next waypoint is
    // half our distance so: |w1 - pos| = d and [w1 - w2].normalize() = W and Z
    // = w1 + W*d/2
    void turn_to_waypoint();
    void turn(Point3D direction);

    // select the correct tile in the plane texture (series of 8 sprites facing
    // [North, NW, W, SW, S, SE, E, NE])
    unsigned int get_speed_octant() const;
    // when we arrive at a terminal, signal the tower
    void arrive_at_terminal();
    // deploy and retract landing gear depending on next waypoints
    void operate_landing_gear();
    
    //TASK_4 Obj-1.2
    template <bool front>
    void add_waypoint(const Waypoint& wp);
    
    bool is_on_ground() const { return pos.z() < DISTANCE_THRESHOLD; }
    float max_speed() const { return is_on_ground() ? type.max_ground_speed : type.max_air_speed; }

    Aircraft(const Aircraft&) = delete;
    Aircraft& operator=(const Aircraft&) = delete;

public:
    Aircraft(const AircraftType& type_, const std::string_view& flight_number_, const Point3D& pos_,
             const Point3D& speed_, Tower& control_) :
        GL::Displayable { pos_.x() + pos_.y() },
        type { type_ },
        flight_number { flight_number_ },
        pos { pos_ },
        speed { speed_ },
        control { control_ }
    {
        speed.cap_length(max_speed());
        fuel = MIN_FUEL + (std::rand()  % (MAX_FUEL - MIN_FUEL)); //TASK_2 Obj-2 A
    }

    const std::string& get_flight_num() const { return flight_number; }
    float distance_to(const Point3D& p) const { return pos.distance_to(p); }

    void display() const override;
    bool move() override;

    bool has_terminal() const; //TASK_2 Obj-2 B.1

    bool is_circling() const; //TASK_2 Obj-2 B.2

    int get_fuel() const; //TASK_2 Obj-2 C

    bool is_low_on_fuel() const; //TASK_2 Obj-2 D.1

    bool at_terminal() const; //TASK_2 Obj-2 D.2

    void refill(int& fuel_stock); //TASK_2 Obj-2 D.4

    friend class Tower;
};