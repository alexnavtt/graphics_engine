#ifndef AXIS_HPP_
#define AXIS_HPP_

#include "graphics_engine/ThreeDim/Mesh.hpp"

class Axis : public Mesh{
public:
    Axis(Point3D loc = Point3D(0, 0, 0), float length = 1){
        points.reserve(6);
        points.push_back(loc);
        points.push_back(loc + Vec3D(1, 0, 0));
        points.push_back(loc);
        points.push_back(loc + Vec3D(0, 1, 0));
        points.push_back(loc);
        points.push_back(loc + Vec3D(0, 0, 1));

        outline = {0, 1, 2, 3, 4, 5};

        points[0].setColour(1, 0, 0);
        points[1].setColour(1, 0, 0);
        points[2].setColour(0, 1, 0);
        points[3].setColour(0, 1, 0);
        points[4].setColour(0, 0, 1);
        points[5].setColour(0, 0, 1);

        shade_faces = false;
        use_outline_colour = true;
        draw_outline = true;
    }
};

#endif
