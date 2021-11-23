#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "graphics_engine/ThreeDim/Mesh.hpp"

class Cube : public Mesh{
public:
    Cube(float size, Point3D loc){
        const float L = 0.5*size;

        points.reserve(8);
        points.push_back({ L,  L,  L});
        points.push_back({-L,  L,  L});
        points.push_back({-L, -L,  L});
        points.push_back({ L, -L,  L});
        points.push_back({ L,  L, -L});
        points.push_back({-L,  L, -L});
        points.push_back({-L, -L, -L});
        points.push_back({ L, -L, -L});

        outline = {0,1,  1,2,  2,3,  3,0,
                   0,4,  3,7,  1,5,  2,6,
                   4,5,  5,6,  6,7,  7,4};

        indices = {0, 1, 3,   1, 2, 3,   0, 3, 4,   3, 7, 4, 
                   5, 4, 7,   7, 6, 5,   1, 5, 6,   6, 2, 1,
                   0, 4, 1,   4, 5, 1,   2, 3, 7,   7, 6, 2};

    }
};

#endif
