#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "graphics_engine/GraphicsTypes.hpp"

struct Triangle{
    Triangle(){}
    
    Triangle(Point a, Point b, Point c){
        memcpy(&vertices[0], a.data(), sizeof(a.data()));
        memcpy(&vertices[6], b.data(), sizeof(b.data()));
        memcpy(&vertices[12], c.data(), sizeof(c.data()));
    }

    Triangle(float x1, float y1, float x2, float y2, float x3, float y3){
        vertices[0]  = x1;
        vertices[1]  = y1;
        vertices[6]  = x2;
        vertices[7]  = y2;
        vertices[12] = x3;
        vertices[13] = y3;
    }

    GLfloat vertices[18] = {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1};
    
    Vec normal;
    
    Colour colour;
};

#endif
