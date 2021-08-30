#ifndef MESH_HPP_
#define MESH_HPP_

#include <vector>
#include "graphics_engine/base/Transforms.hpp"
#include "graphics_engine/ThreeDim/Orientation.hpp"
#include "graphics_engine/ThreeDim/Triangle3D.hpp"

class Mesh{
public:
    Pose3D pose;
    std::vector<Triangle3D> triangles;
    std::vector<Point3D> points;
    std::vector<GLuint> indices;
    bool use_element_array = false;
    bool draw_outline = false;
};

#endif
