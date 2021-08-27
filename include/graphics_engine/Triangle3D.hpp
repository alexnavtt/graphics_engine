#ifndef TRIANGLE_3D_HPP_
#define TRIANGLE_3D_HPP_

#include <cstring>
#include "graphics_engine/ThreeDim/Point3D.hpp"

struct Triangle3D{
    Triangle3D(){}
    
    Triangle3D(Point3D a, Point3D b, Point3D c){
        p1 = a;
        p2 = b;
        p3 = c;
    }

    float* data(){
        vertices[0] = p1.x();
        vertices[1] = p1.y();
        vertices[2] = p1.z();

        vertices[7] = p2.x();
        vertices[8] = p2.y();
        vertices[9] = p2.z();

        vertices[14] = p3.x();
        vertices[15] = p3.y();
        vertices[16] = p3.z();

        memcpy(&vertices[3],  colour.data(), 4*sizeof(float));
        memcpy(&vertices[10], colour.data(), 4*sizeof(float));
        memcpy(&vertices[17], colour.data(), 4*sizeof(float));

        return vertices;
    }

    float vertices[21] = {0, 0, 0,    1, 1, 1, 1, 
                          0, 0, 0,    1, 1, 1, 1, 
                          0, 0, 0,    1, 1, 1, 1};
        
    Colour colour;

    Point3D p1;
    Point3D p2;
    Point3D p3;
};

#endif