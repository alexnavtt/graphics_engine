#ifndef MESH_HPP_
#define MESH_HPP_

#include <vector>
#include "GL/glew.h"
#include "graphics_engine/base/Transforms.hpp"
#include "graphics_engine/ThreeDim/Orientation.hpp"
#include "graphics_engine/ThreeDim/Triangle3D.hpp"

class Mesh{
public:
    Pose3D pose;
    std::vector<Triangle3D> triangles;
    std::vector<Point3D> points;
    std::vector<GLuint> indices;
    std::vector<GLuint> outline;

    bool shade_faces = true;
    bool use_element_array = true;
    bool draw_outline = false;
    bool use_outline_colour = false;
};

#endif
