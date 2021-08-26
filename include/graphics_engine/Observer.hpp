#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include "graphics_engine/Orientation.hpp"

class Observer{
public:
    Point3D loc;
    Orientation ori;
    float screen_dist;

    Point2D project(const Point3D& p3D){
        Point2D p2D;
        Vec3D offset = p3D;

        // Transform the point such that the observer
        // is at the point (0,0,0) with identity rotation
        offset.x() -= loc.x();
        offset.y() -= loc.y();
        offset.z() -= loc.z();

        std::cout << "After offset:"; offset.print();

        ori.inv().rotateVector(offset);

        std::cout << "After rotation:"; offset.print();


        // Determine the point of intersection of the ray between the observer
        // and the Point3D with the Display
        float ratio = screen_dist/offset.x();
        p2D.x() = -offset.y() * ratio;
        p2D.y() = offset.z() * ratio;
        return p2D;
    }
};

#endif 
