#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "graphics_engine/Mesh.hpp"

class Cube : public Mesh{
    Cube(float size, Point3D loc){
        const float L = 0.5*size;

        triangles.push_back(Triangle3D({L, L, L}, {L, -L, L}, {L, L, -L}));
        triangles.push_back(Triangle3D({L, -L, L}, {L, -L, -L}, {L, L, -L}));
        // Left face
        triangles.push_back(Triangle3D({L, L, L}, {-L, L, L}, {-L, L, -L}));
        triangles.push_back(Triangle3D({L, L, L}, {-L, L, -L}, {L, L, -L}));
        // Right face
        triangles.push_back(Triangle3D({L, -L, L}, {-L, -L, L}, {-L, -L, -L}));
        triangles.push_back(Triangle3D({L, -L, L}, {-L, -L, -L}, {L, -L, -L}));
        // Rear face
        triangles.push_back(Triangle3D({-L, L, L}, {-L, -L, L}, {-L, L, -L}));
        triangles.push_back(Triangle3D({-L, -L, L}, {-L, -L, -L}, {-L, L, -L}));
        // Top face 
        triangles.push_back(Triangle3D({L, L, L}, {L, -L, L}, {-L, -L, L}));
        triangles.push_back(Triangle3D({L, L, L}, {-L, -L, L}, {-L, L, L}));
        // Bottom face
        triangles.push_back(Triangle3D({L, L, -L}, {L, -L, -L}, {-L, -L, -L}));
        triangles.push_back(Triangle3D({L, L, -L}, {-L, -L, -L}, {-L, L, -L}));
    }
};

#endif
