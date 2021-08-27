#ifndef POINT_2D_HPP_
#define POINT_2D_HPP_

#include <iostream>
#include "graphics_engine/base/Point.hpp"

class Point2D : public Point{
public:
    Point2D(){}
    Point2D(float x, float y){
        this->x() = x;
        this->y() = y;
    }

    float& depth(){return data_[2];}
    const float& depth() const {return data_[2];}

    void print() {
        std::cout << "(" << x() << ", " << y() << ")  D = " << depth() << std::endl;
    }
};

typedef Point2D Vec2D;

#endif
