#include "aircraft.hpp"

#include "GL/opengl_interface.hpp"

#include <cmath>

void Aircraft::turn_to_waypoint()
{
    if (!waypoints.empty())
    {
        Point3D target = waypoints[0];
        if (waypoints.size() > 1)
        {
            const float d   = (waypoints[0] - pos).length();
            const Point3D W = (waypoints[0] - waypoints[1]).normalize(d / 2.0f);
            target += W;
        }

        turn(target - pos - speed);
    }
}

void Aircraft::turn(Point3D direction)
{
    (speed += direction.cap_length(type.max_accel)).cap_length(max_speed());
}

unsigned int Aircraft::get_speed_octant() const
{
    const float speed_len = speed.length();
    if (speed_len > 0)
    {
        const Point3D norm_speed { speed * (1.0f / speed_len) };
        const float angle =
            (norm_speed.y() > 0) ? 2.0f * 3.141592f - std::acos(norm_speed.x()) : std::acos(norm_speed.x());
        // partition into NUM_AIRCRAFT_TILES equal pieces
        return (static_cast<int>(std::round((angle * NUM_AIRCRAFT_TILES) / (2.0f * 3.141592f))) + 1) %
               NUM_AIRCRAFT_TILES;
    }
    else
    {
        return 0;
    }
}

// when we arrive at a terminal, signal the tower
void Aircraft::arrive_at_terminal()
{
    // we arrived at a terminal, so start servicing
    control.arrived_at_terminal(*this);
    is_at_terminal = true;
}

// deploy and retract landing gear depending on next waypoints
void Aircraft::operate_landing_gear()
{
    if (waypoints.size() > 1u)
    {
        const auto it            = waypoints.begin();
        const bool ground_before = it->is_on_ground();
        const bool ground_after  = std::next(it)->is_on_ground();
        // deploy/retract landing gear when landing/lifting-off
        if (ground_before && !ground_after)
        {
            std::cout << flight_number << " lift off" << std::endl;
        }
        else if (!ground_before && ground_after)
        {
            std::cout << flight_number << " is now landing..." << std::endl;
            landing_gear_deployed = true;
        }
        else if (!ground_before && !ground_after)
        {
            landing_gear_deployed = false;
        }
    }
}

//TASK_4 Obj-1.2: Pour que l'evaluation ait lieu à la compilation, il faut passer le flag en template plutôt qu'en parametre de la fonction.
template <bool front>
void Aircraft::add_waypoint(const Waypoint& wp)
{
    if (front)
    {
        waypoints.push_front(wp);
    }
    else
    {
        waypoints.push_back(wp);
    }
}

bool Aircraft::move()
{
    if (waypoints.empty())
    {
        if (service_done) {// TASK_0 C-4: si entretien déja effectué, pas de nouvelle instruction à donner.
            return false;
        }
        const auto front = false;
        for (const auto& wp: control.get_instructions(*this)) //TASK_4 Obj-1.1
        {
            add_waypoint<front>(wp);
        }
    }

    if (!is_at_terminal)
    {   
        //TASK_2 Obj-2 A: On décrémente la variable correspondant au carburant quand l'avion est en vol et on gere le cas où un avion n'a plus de carburant.

        if( fuel <= 0){
            throw AircraftCrash { "Aircraft " + flight_number + " crashed due to fuel" }; // TASK_3 Obj-1.3
        }

        //TASK_2 Obj-2 B.4: Si l'avion est en attente d'un terminal, on en lui attribue un si cela est possible.
        if(is_circling()){
            
            auto newWaypoints =  control.reserve_terminal(*this);
            if(!newWaypoints.empty()){
                waypoints = std::move(newWaypoints);
            }     
        }

        turn_to_waypoint();
        // move in the direction of the current speed
        pos += speed;

        // if we are close to our next waypoint, stike if off the list
        if (!waypoints.empty() && distance_to(waypoints.front()) < DISTANCE_THRESHOLD)
        {
            if (waypoints.front().is_at_terminal())
            {
                arrive_at_terminal();
            }
            else
            {
                operate_landing_gear();
            }
            waypoints.pop_front();
        }

        if (is_on_ground())
        {
            if (!landing_gear_deployed)
            {
                using namespace std::string_literals;
                throw AircraftCrash { flight_number + " crashed into the ground"s };
            }
        }
        else
        {   
            fuel--; //TASK_2 Obj-2 A
            
            // if we are in the air, but too slow, then we will sink!
            const float speed_len = speed.length();
            if (speed_len < SPEED_THRESHOLD)
            {
                pos.z() -= SINK_FACTOR * (SPEED_THRESHOLD - speed_len);
            }
        }

        // update the z-value of the displayable structure
        GL::Displayable::z = pos.x() + pos.y();
    }
    return true;
}

void Aircraft::display() const
{
    type.texture.draw(project_2D(pos), { PLANE_TEXTURE_DIM, PLANE_TEXTURE_DIM }, get_speed_octant());
}


//TASK_2 Obj-2 B.1
bool Aircraft::has_terminal() const
{
    return !waypoints.empty() && waypoints.back().is_at_terminal(); // Si le dernier waypoint (si les waypoints existent) est à un terminal.
};

//TASK_2 Obj-2 B.2
bool Aircraft::is_circling() const
{   
   return !has_terminal() && !is_at_terminal && !service_done; // Pas de terminal attribué, pas à un terminal et service non effectué.
}

//TASK_2 Obj-2 C
int Aircraft::get_fuel() const 
{
    return fuel;
}

//TASK_2 Obj-2 D.1
bool Aircraft::is_low_on_fuel() const
{
    return fuel < 200;
}

//TASK_2 Obj-2 D.2
bool Aircraft::at_terminal() const
{
    return is_at_terminal;
}

//TASK_2 Obj-2 D.4
void Aircraft::refill(int& fuel_stock)
{   
    assert(fuel_stock >= 0);
    int to_refill = MAX_FUEL - fuel;

    to_refill = to_refill < fuel_stock ? to_refill : fuel_stock;

    fuel_stock -= to_refill;
    fuel += to_refill;
    if (!is_low_on_fuel()){
        std::cout << flight_number << " refueled to "<< fuel <<" | fuel used: "<< to_refill << std::endl;
    }
}

