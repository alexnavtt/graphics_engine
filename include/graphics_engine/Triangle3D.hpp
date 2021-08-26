#ifndef TRIANGLE_3D_HPP_
#define TRIANGLE_3D_HPP_

#include <cstring>
#include "graphics_engine/GraphicsTypes.hpp"

struct Triangle3D{
    Triangle3D(){}
    
    Triangle3D(Point3D a, Point3D b, Point3D c){
        memcpy(&vertices[0],  a.data(), sizeof(a.data()));
        memcpy(&vertices[7],  b.data(), sizeof(b.data()));
        memcpy(&vertices[14], c.data(), sizeof(c.data()));
    }

    Triangle3D(float x1, float y1, float z1, 
               float x2, float y2, float z2, 
               float x3, float y3, float z3){
        vertices[0]  = x1;
        vertices[1]  = y1;
        vertices[2]  = z1;
        vertices[7]  = x2;
        vertices[8]  = y2;
        vertices[9]  = z2;
        vertices[14] = x3;
        vertices[15] = y3;
        vertices[16] = z3;
    }

    GLfloat vertices[21] = {0.0, 0.0, 0.0,   0.0, 0.0, 0.0, 1.0, 
                            0.0, 0.0, 0.0,   0.0, 0.0, 0.0, 1.0, 
                            0.0, 0.0, 0.0,   0.0, 0.0, 0.0, 1.0};
    
    Vec3D normal;
    
    Colour colour;
};

#endif