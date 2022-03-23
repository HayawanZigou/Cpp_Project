#include "tower_sim.hpp"

//TASK_4 Obj-2.2
void test_generic_points(){
    Point<3, float> p1 {0,0,0};
    // Point<2, float> p2 {0,0};
    // auto p3 = p1 + p2;
    // p1 += p3;
    // p1 *= 3.f; // ou 3.f, ou 3.0 en fonction du type de Point
}

int main(int argc, char** argv)
{
    TowerSimulation simulation { argc, argv };
    test_generic_points();
    simulation.launch();

    return 0;
}