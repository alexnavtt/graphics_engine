#include <iostream>
#include "graphics_engine/Observer.hpp"

int main(){
    Observer obs;
    obs.loc.z() = 1;
    obs.loc.y() = 1;
    obs.screen_dist = 0.5;
    obs.ori.setRPY(0, M_PI_2, 0);
    obs.ori.print();

    Point3D p(0, 1, 0);

    Point2D proj = obs.project(p);
    std::cout << "Projection is (" << proj.x() << ", " << proj.y() << ")\n";

    return 0;
}