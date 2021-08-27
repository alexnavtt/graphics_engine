#ifndef LINE_HPP_
#define LINE_HPP_

#include "graphics_engine/TwoDim/Point2D.hpp"

struct Line{
    Point2D p1;
    Point2D p2;
    Colour colour;

    Line(float x1, float y1, float x2, float y2){
        p1.x() = x1;
        p1.y() = y1;
        p2.x() = x2;
        p2.y() = y2;
    }
};

#endif
