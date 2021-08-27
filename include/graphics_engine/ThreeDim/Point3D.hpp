#ifndef POINT_3D_HPP_
#define POINT_3D_HPP_

#include <math.h>
#include <iostream>
#include "graphics_engine/base/Point.hpp"

class Point3D : public Point{
public:
    Point3D(){}
    Point3D(float x, float y, float z){
        this->x() = x;
        this->y() = y;
        this->z() = z;
    }

    float& z(){return data_[2];}
    const float& z() const {return data_[2];}

    float sqNorm(){return data_[0]*data_[0] + data_[1]*data_[1];}

    float norm(){return sqrt(sqNorm());}

    void print(){std::cout << "(" << x() << ", " << y() << ", " << z() << ")" << std::endl;}
};

typedef Point3D Vec3D;

#endif
