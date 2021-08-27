#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include "graphics_engine/ThreeDim/Mesh.hpp"
#include "graphics_engine/ThreeDim/Triangle3D.hpp"
#include "graphics_engine/ThreeDim/Orientation.hpp"

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

        ori.inv().rotateVector(offset);

        // Determine the point of intersection of the ray between the observer
        // and the Point3D with the Display
        float ratio = screen_dist/offset.x();
        p2D.x() = -offset.y() * ratio;
        p2D.y() = offset.z() * ratio;
        p2D.depth() = 1 - ratio;
        return p2D;
    }

    Triangle2D project(const Triangle3D& tri3D){
        Triangle2D tri2D;
        tri2D.colour = tri3D.colour;

        tri2D.p1 = project(tri3D.p1);
        tri2D.p2 = project(tri3D.p2);
        tri2D.p3 = project(tri3D.p3);

        return tri2D;
    }

    void drawMesh(const Mesh& mesh, const Display& disp){
        for (Triangle3D T : mesh.triangles){
            Triangle2D tri = project(T);
            disp.drawTriangle(tri);
        }
    }
};

#endif 
