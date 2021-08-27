#ifndef TRIANGLE_2D_HPP_
#define TRIANGLE_2D_HPP_

#include "graphics_engine/TwoDim/Point2D.hpp"

struct Triangle2D{
    Triangle2D(){}
    
    Triangle2D(Point2D a, Point2D b, Point2D c){
        p1 = a;
        p2 = b;
        p3 = c;
    }

    Triangle2D(float x1, float y1, float x2, float y2, float x3, float y3){
        p1 = Point2D(x1, y1);
        p2 = Point2D(x2, y2);
        p3 = Point2D(x3, y3);
    }

    float* data(){
        vertices[0] = p1.x();
        vertices[1] = p1.y();
        vertices[2] = p1.depth();

        vertices[7] = p2.x();
        vertices[8] = p2.y();
        vertices[9] = p2.depth();

        vertices[14] = p3.x();
        vertices[15] = p3.y();
        vertices[16] = p3.depth();

        memcpy(&vertices[3],  colour.data(), 4*sizeof(float));
        memcpy(&vertices[10], colour.data(), 4*sizeof(float));
        memcpy(&vertices[17], colour.data(), 4*sizeof(float));

        return vertices;
    }

    int dataSize(){
        return sizeof(vertices);
    }

    GLfloat vertices[21] = {0, 0, 0,    1, 1, 1, 1, 
                            0, 0, 0,    1, 1, 1, 1, 
                            0, 0, 0,    1, 1, 1, 1};
        
    Colour colour;

    Point2D p1;
    Point2D p2;
    Point2D p3;
};

#endif
