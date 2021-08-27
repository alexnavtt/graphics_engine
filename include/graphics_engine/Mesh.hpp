#ifndef MESH_HPP_
#define MESH_HPP_

#include <vector>
#include "graphics_engine/Triangle3D.hpp"
#include "graphics_engine/Orientation.hpp"

class Mesh{
public:
    Point3D loc;
    Orientation ori;
    std::vector<Triangle3D> triangles;
};

#endif
